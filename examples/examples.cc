#include<fmt/core.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<initializer_list>

using type = fmt::detail::type;

fmt::detail::type emit_type(auto t) {
	switch(t%2) {
		case 0: 
			return  type::int_type;
		case 1:
			return type::custom_type;
	}
	return fmt::detail::type::none_type;
}

template<class T>
class ShitClass {
private:
	template<class C>
	int get_type_id(fmt::basic_string_view<C> &bview, const int offset) {
		int next = 0;
		int start = 100;
		fmt::basic_format_parse_context context(bview);
		while((next=context.next_arg_id())<start + offset);
		for(auto S : context ) next-=*context;
		return -next;
	}

	void iter_values(T a) {
		for(int i=1;i<a;i++) {
			unsigned int bs = get_type_id(bsview, i)/bsview.size();
		 	contain = contain + " " + std::string((char*)&bs);
		}
	}
	fmt::basic_string_view<char> bsview;
	std::string contain;
public:
	ShitClass(fmt::basic_string_view<char> &bsview, T start_offset)  : bsview(bsview) {
		iter_values(start_offset);
	}

	ShitClass(fmt::basic_string_view<T> &bsview)  : bsview(bsview) {
		iter_values(10);
	}

	ShitClass() = delete;

	std::string getStr() const {return contain;}
};

template<class T>
std::ostream &operator<<(std::ostream &os, ShitClass<T> &shit) {
		os << shit.getStr();
		return os;
}


template<int N>
struct string_struct {
public:
	constexpr string_struct(const char (&str)[N]) {
		std::copy_n(str,N,name);
	}
	char name[N];
};

template<string_struct S>
class nameclass {
	public:
	static constexpr const char *name = S.name;
	using Type = decltype(S);
	static Type tp;
};

template<typename T>
concept NameType = requires(T a) {
	{T::name} -> std::convertible_to<const char*>;
	{T::tp} -> std::convertible_to<string_struct<5>>;
};

template<typename... Args>
void get_idx(Args... a) {
	std::vector v{std::initializer_list(a...)};
}

// TODO Orgranize 
template<NameType... Args>
auto example_contains(Args... a) { 
	return fmt::detail::check_arg_in_Arg<0, Args...>(fmt::basic_string_view("fuck"));
}

int main() {
	fmt::basic_string_view bsview("fuck");
	for(char s : bsview) std::cout << s << "\n";
	type t = emit_type(3);
	if(fmt::detail::is_integral_type(t)) std::cout << "int type";
	int type_v_int = static_cast<int>(fmt::detail::is_utf8());
	if(type_v_int>0) std::cout << "is utf8\n";
	else std::cout << "is not utf8\n";

	ShitClass shit(bsview, 10);
	ShitClass shitt  = bsview;
	using errorHandler  = fmt::detail::error_handler;
	errorHandler eh;
	fmt::detail::format_string_checker  fmt_checker(fmt::basic_string_view("fuck"), eh, 10, "yout", "fucktard");
	fmt::detail::check_format_string(bsview);

	//fmt_checker.on_error("nigger wrong argument\n");
	fmt_checker.on_text("nigger", "fucker");
	//std::cout << "ID ==" << fmt_checker.on_arg_id("fuck") << "\n";
	std::cout << example_contains(nameclass<"cuck">()) << "\n";

	std::cout << fmt_checker.check_arg_exist("fucktard") << "\n";

	std::cout << "id = " << fmt_checker.on_basic_next_id() << "\n";
	//fmt::detail::encode_types<fmt::basic_string_view,int,char*>();
	
	//std::cout << shitt << "\n";
}
