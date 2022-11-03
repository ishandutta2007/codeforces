#define MOD 1000000007

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

#define BEGIN int main() { io_init();
#define END }

#ifdef CODEFORCES_TESTCASES
    #define BEGIN void solve() {
    #define END } int main() { io_init(); int T; cin >> T; while(T--) { solve(); } }
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


template<typename T, typename = void>
struct integral_superclass { using type = T; };
template<typename T>
struct integral_superclass<T, enable_if_t<is_integral<T>::value and sizeof(T) <= 4>> { using type = ULL; };
template<typename T>
struct integral_superclass<T, enable_if_t<is_integral<T>::value and (sizeof(T) > 4 and sizeof(T) <= 8)>> { using type = __uint128_t; };
template<typename T>
using integral_superclass_t = typename integral_superclass<T>::type;



template<typename T>
T modular_inverse(const T& x, const T& y) {
    T z = x % y;
    if(z <= 1) {
        return z;
    }
    return y - T((integral_superclass_t<T>(y) * modular_inverse(y, z) - 1) / z);
}



template<typename Mod, typename T, typename = enable_if_t<(sizeof(T) > 8)>>
inline constexpr auto fast_mod(const T& x) {
    return x % Mod::mod();
}
template<typename Mod, typename T, typename = enable_if_t<sizeof(T) <= 8>>
inline constexpr T fast_mod (const T& x) {
    ULL q = (Mod::invmod() * x) >> 64;
    ULL r = x - q *  Mod::mod();
    return r - Mod::mod() * (r >= Mod::mod());
}



template<typename T, typename Mod>
class number_mod {
    T n;
public:
    inline static constexpr T mod() {
        return Mod::mod();
    }
    inline static void set_mod(const T& m) {
        Mod::set_mod(m);
    }
    constexpr number_mod(const T& num = T()) : n(num % mod()) {
        n += (n < 0) * mod();
    }
    inline constexpr const T& get() const {
        return n;
    }
    template<typename S, typename = enable_if_t<is_convertible<T, S>::value>>
    explicit inline constexpr operator S() const {
        return n;
    }
    friend constexpr bool operator == (const number_mod& x, const number_mod& y) {
        return x.n == y.n;
    }
    friend constexpr bool operator != (const number_mod& x, const number_mod& y) {
        return x.n != y.n;
    }
    friend constexpr bool operator < (const number_mod& x, const number_mod& y) {
        return x.n < y.n;
    }
    friend constexpr bool operator > (const number_mod& x, const number_mod& y) {
        return x.n > y.n;
    }
    friend constexpr bool operator <= (const number_mod& x, const number_mod& y) {
        return x.n <= y.n;
    }
    friend constexpr bool operator >= (const number_mod& x, const number_mod& y) {
        return x.n >= y.n;
    }
    auto inv() const {
        auto x = *this;
        x.n = modular_inverse(n, mod());
        return x;
    }
    auto operator - () const {
        auto x = *this;
        x.n = mod() * (n > 0) - n;
        return x;
    }
    auto& operator += (const number_mod& other) {
        n += other.n;
        n -= (n >= mod()) * mod();
        return *this;
    }
    friend constexpr auto operator + (number_mod x, const number_mod& y) {
        x += y;
        return x;
    }
    auto& operator -= (const number_mod& other) {
        n -= other.n;
        n += (n < 0) * mod();
        return *this;
    }
    friend constexpr auto operator - (number_mod x, const number_mod& y) {
        x -= y;
        return x;
    }
    auto& operator *= (const number_mod& other) {
        n = fast_mod<Mod>(integral_superclass_t<T>(n) * integral_superclass_t<T>(other.n));
        return *this;
    }
    friend constexpr auto operator * (number_mod x, const number_mod& y) {
        x *= y;
        return x;
    }
    auto& operator /= (const number_mod& other) {
        return operator *= (other.inv());
    }
    friend constexpr auto operator / (number_mod x, const number_mod& y) {
        x /= y;
        return x;
    }
};

template<typename T, typename Mod>
ostream& operator << (ostream& out, const number_mod<T, Mod>& x) {
    return out << x.get();
}

template<typename T, typename Mod>
istream& operator >> (istream& in, number_mod<T, Mod>& x) {
    T a;
    in >> a;
    x = a;
    return in;
}



template<typename T, T m>
struct compile_time_mod {
    constexpr static __uint128_t invm = -1ULL / m;
    static void set_mod(const T&) {
        abort();
    }
    static inline constexpr T mod() {
        return m;
    }
    static inline constexpr auto invmod() {
        return invm;
    }
};



#ifdef MOD
using imod = number_mod<int, compile_time_mod<int, MOD>>;
using lmod = number_mod<LL, compile_time_mod<int, MOD>>;
#else
template<int m>
using imod = number_mod<int, compile_time_mod<int, m>>;
template<LL m>
using lmod = number_mod<LL, compile_time_mod<LL, m>>;
#endif



template<typename T, typename E>
constexpr T fast_exp(T b, E e) {
    T a = 1;
    while(e >= 1) {
        if(e & 1) {
            a *= b;
        }
        b *= b;
        e >>= 1;
    }
    return a;
}



template<typename T, typename E>
inline constexpr T pow(T b, E e) {
    return (e < 0) ? (fast_exp(1 / b, -e)) : (fast_exp(b, e));
}



template<typename T, typename = enable_if_t<is_integral<T>::value and (sizeof(T) == 4 or sizeof(T) == 8)>>
inline constexpr int ilog2(const T x) {
    if(sizeof(T) == 4) {
        return 31 - __builtin_clz(x);
    } else {
        return 63 - __builtin_clzll(x);
    }
}



BEGIN

int N, Q;
cin >> N >> Q;
string s0, t;
cin >> s0 >> t;
int M = s0.length();
vector<imod> pow2(1000000), invpow2(1000000);
pow2[0] = 1;
invpow2[0] = 1;
invpow2[1] = imod(2).inv();
for(int i = 1; i < 1000000; ++i) {
	pow2[i] = 2 * pow2[i - 1];
	invpow2[i] = invpow2[i - 1] * invpow2[1];
}
vector<vector<imod>> count_occ_s(t.length() + 1, vector<imod>(26, 0));
for(int n = 1; n <= int(t.length()); ++n) {
	for(int c = 0; c < 26; ++c) {
		count_occ_s[n][c] = 2 * count_occ_s[n - 1][c];
	}
	count_occ_s[n][t[n - 1] - 'a'] += 1;
	//~ [&]() { auto& out = cout; put_stream(out, "", make_string_formatter(count_occ_s[n]), "\n");  }();
}
while(Q--) {
	int k;
	string w;
	cin >> k >> w;
	imod ans = 0;
	for(int n = 0; n <= M; ++n) {
		string v;
		bool ok = true;
		for(int j = 0; j < int(w.length()); ++j) {
			if((n + j) % (M + 1) == M) {
				v += w[j];
			} else if(w[j] != s0[(n + j) % (M + 1)]) {
				ok = false;
				break;
			}
		}
		if(not ok) {
			continue;
		}
		//~ [&]() { auto& out = cout; put_stream(out, "v: '", make_string_formatter(v), "'\n");  }();
		if(v.empty()) {
			ans += pow(imod(2), k);
			continue;
		}
		if(ilog2(v.length()) >= k) {
			continue;
		}
		vector<imod> f(v.length(), 0);
		for(int j = ilog2(v.length()) + 1; j >= 0; --j) {
			for(int i = 0; i < int(v.length()); ++i) {
				if(i + (1 << j) >= int(v.length())) {
					f[i] = count_occ_s[k][v[i] - 'a'] - pow2[k - j] * count_occ_s[j][v[i] - 'a'];
					continue;
				}
				auto tmp = f[i];
				f[i] = 0;
				ok = true;
				for(int l = i; l < int(v.length()); l += 1 << (j + 1)) {
					if(v[l] != t[j]) {
						ok = false;
						break;
					}
				}
				if(ok) {
					f[i] += f[i + (1 << j)];
				}
				ok = true;
				for(int l = i + (1 << j); l < int(v.length()); l += 1 << (j + 1)) {
					if(v[l] != t[j]) {
						ok = false;
						break;
					}
				}
				if(ok) {
					f[i] += tmp;
				}
			}
			//~ [&]() { auto& out = cout; put_stream(out, "j = ", make_string_formatter(j), ": ", make_string_formatter(f), "\n");  }();
		}
		ans += f[0];
	}
	[&]() { auto& out = cout; put_stream(out, "", make_string_formatter(ans), "\n");  }();
}

END