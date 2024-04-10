#include <bits/stdc++.h>

using namespace std; 

using LL = long long;
using ULL = unsigned long long;

#if __cplusplus >= 201703L

#else
static_assert(__cplusplus >= 201402L, "C++14 or later required");
template<typename...> using void_t = void;
template<typename T>
inline T gcd(T x, T y) {
    while(y) {
        x %= y;
        swap(x, y);
    }
    return x;
}
template<typename T>
inline T lcm(T x, T y) {
    return x / gcd(x, y) * y;
}
#endif 

template<typename T, typename = void> struct is_iterable : false_type {};
template<typename T> struct is_iterable<T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>> : true_type {};
template<typename T> constexpr bool is_iterable_v = is_iterable<T>::value;

template<typename T> constexpr bool is_string_v = is_same<decay_t<T>, string>::value; 

template<bool...> constexpr bool constexpr_and;
template<bool B, bool... Bs> constexpr bool constexpr_and<B, Bs...> = B and constexpr_and<Bs...>;
template<> constexpr bool constexpr_and<> = true;

template<bool...> constexpr bool constexpr_or;
template<bool B, bool... Bs> constexpr bool constexpr_or<B, Bs...> = B or constexpr_or<Bs...>;
template<> constexpr bool constexpr_or<> = false;

template <typename T,  uint32_t ...I, typename F>
void tuple_foreach_impl(T&& t, index_sequence<I...>, F&& f) {
    using dummy_array = int[];
    dummy_array{(void(f(get<I>(t))), 0)..., 0};
}

template <typename T, typename F> void tuple_foreach(T&& t, F&& f) {
    constexpr auto size = tuple_size<remove_reference_t<T>>::value;
    tuple_foreach_impl(forward<T>(t), make_index_sequence<size>{}, forward<F>(f));
}


#ifdef CODEFORCES_TESTCASES
    #define BEGIN void solve() {
    #define END } int main() { io_init(); int T; cin >> T; while(T--) { solve(); } }
#else
    #define BEGIN int main() { io_init();
    #define END }
#endif

void io_init() {
    #ifndef INTERACTIVE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #endif
}

void put_stream(ostream&) { }
template<typename T, typename ...Ts>
inline void put_stream(ostream& out, T&& x, Ts&&... xs) {
    out << x;
    put_stream(out, forward<Ts>(xs)...);
}

template<typename ...Ts>
struct string_formatter {
    tuple<Ts...> vs;
    string_formatter(Ts&&... xs) : vs(forward<Ts>(xs)...) { }
    template<size_t ...I>
    inline void print_helper(ostream& out, index_sequence<I...>) const {
        put_stream(out, get<I>(vs)...);
    }
    template<size_t ...I>
    inline void print_iterables_helper(ostream& out, index_sequence<I...>) const {
        auto its = make_tuple(begin(get<I>(vs))...);
        while(get<0>(its) != end(get<0>(vs))) {
            tuple_foreach(its, ([&](auto&& _, auto&&... _other_args){(void)_; return out << *(_++) << " ", void();}));
            out << "\n";
        }
    }
};

template<typename ...Ts, typename = enable_if_t<constexpr_or<is_string_v<Ts> or not is_iterable_v<Ts>...>>, typename = void>
ostream& operator << (ostream& out, const string_formatter<Ts...>& st) {
    st.print_helper(out, make_index_sequence<sizeof...(Ts)>{});
    return out;
}

template<typename T, typename = enable_if_t<(not is_string_v<T>) and is_iterable_v<T>>>
ostream& operator << (ostream& out, const string_formatter<T>& st) {
    for(auto&& x : get<0>(st.vs)) {
        out << x << " ";
    }
    return out;
}
template<typename ...Ts, typename = enable_if_t<constexpr_and<(not is_string_v<Ts>) and is_iterable_v<Ts>...>>>
ostream& operator << (ostream& out, const string_formatter<Ts...>& st) {
    st.print_iterables_helper(out, make_index_sequence<sizeof...(Ts)>{});
    return out;
}
template<typename ...Ts>
auto make_string_formatter(Ts&&... vs) {
    return string_formatter<Ts...>(forward<Ts>(vs)...);
}

#define min ___min_new
template<typename T1, typename T2>
inline constexpr common_type_t<T1, T2> min(const T1& x, const T2& y) {
    if(x < y) {
        return x;
    }
    return y;
}
template<typename T>
inline constexpr const T& min(const T& x, const T& y) {
    if(x < y) {
        return x;
    }
    return y;
}

template<typename T1, typename T2, typename ...Ts>
inline constexpr auto min(const T1& x1, const T2& x2, const Ts&... xs) {
    return min(min(x1, x2), xs...);
}

#define max ___max_new
template<typename T1, typename T2>
inline constexpr common_type_t<T1, T2> max(const T1& x, const T2& y) {
    if(not(x < y)) {
        return x;
    }
    return y;
}
template<typename T>
inline constexpr const T& max(const T& x, const T& y) {
    if(not(x < y)) {
        return x;
    }
    return y;
}

template<typename T1, typename T2, typename ...Ts>
inline constexpr auto max(const T1& x1, const T2& x2, const Ts&... xs) {
    return max(max(x1, x2), xs...);
}

BEGIN

int N;
cin >> N;
vector<int> H(N);
vector<LL> B(N);
for(int n = 0; n < N; ++n) {
	cin >> H[n];
}
for(int n = 0; n < N; ++n) {
	cin >> B[n];
}

/*vector<int> pr_lo(N);
vector<int> S;
for(int n = 0; n < N; ++n) {
	while(S.size() and H[S.back()] > H[n]) {
		S.pop_back();
	}
	if(S.empty()) {
		pr_lo[n] = -1;
	} else {
		pr_lo[n] = S.back();
	}
	S.push_back(n);
}*/

vector<LL> ans(N, 0);
ans[0] = B[0];
vector<pair<int, LL>> S;
S.emplace_back(0, ans[0]);
LL from_begin = 0;
for(int n = 1; n < N; ++n) {
	ans[n] = ans[n - 1] + B[n];
	LL v =  -(1LL << 60);
	while(S.size() and H[S.back().first] > H[n]) {
		v = max(v, S.back().second);
		S.pop_back();
	}
	if(S.size()) {
		S.back().second = max(S.back().second, v);
		ans[n] = max(ans[n], ans[S.back().first], S.back().second + B[n]);
	} else {
		from_begin = max(from_begin, v);
		ans[n] = max(ans[n], from_begin + B[n], B[n]);
	}
	S.emplace_back(n, ans[n]);
}
//~ [&]() { auto& out = cout; put_stream(out, "", make_string_formatter(ans), "\n");  }();

[&]() { auto& out = cout; put_stream(out, "", make_string_formatter(ans[N - 1]), "\n");  }();


END