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
#elif defined(GOOGLE_CODEJAM)
    #define BEGIN(t0) void solve(int t0) {
    #define END } int main() { io_init(); int T; cin >> T; for(int t = 1; t <= T; ++t) { solve(t); } }
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


template<typename F>
class _y_combinator_impl {
    F f;
public:
    template<typename G>
    explicit _y_combinator_impl(G g) : f(g) { }
    template<typename ...Args>
    decltype(auto) operator () (Args&& ...args) {
        return f(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<typename F>
decltype(auto) y_combinator(F f) {
    return _y_combinator_impl<F>(f);
}

struct DSU {
	vector<int> f;
	vector<int> rk;
	DSU(int n) : f(n), rk(n, 1) {
		iota(f.begin(), f.end(), 0);
	}
	int find(int u) {
		return (u == f[u]) ? (u) : (f[u] = find(f[u]));
	}
	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if(u == v) {
			return;
		}
		if(rk[u] < rk[v]) {
			swap(u, v);
		}
		f[v] = u;
		rk[u] += rk[v];
	}
};

BEGIN

int N, M;
cin >> N >> M;
vector<tuple<int, int, LL>> E;
vector<unordered_set<int>> G(N);
while(M--) {
	int u, v, x;
	cin >> u >> v >> x;
	E.emplace_back(u - 1, v - 1, x);
	G[u - 1].insert(v - 1);
	G[v - 1].insert(u - 1);
}
unordered_set<int> unvisited;
for(int n = 0; n < N; ++n) {
	unvisited.insert(n);
}
DSU dsu(N);
LL blank_used = 0;
auto dfs = y_combinator([&](auto rec, int n) -> void {
	vector<int> to_visit;
	for(int x : unvisited) {
		if(G[n].count(x) == 0) {
			to_visit.push_back(x);
			blank_used++;
			dsu.join(n, x);
			//~ [&]() { auto& out = cout; put_stream(out, "joining ", make_string_formatter(n), " and ", make_string_formatter(x), "\n");  }();
		}
	}
	for(auto i: to_visit) {
		unvisited.erase(i);
	}
	for(auto i : to_visit) {
		rec(i);
	}
});
for(int n = 0; n < N; ++n) {
	if(unvisited.count(n)) {
		unvisited.erase(n);
		dfs(n);
	}
}
//~ [&]() { auto& out = cout; put_stream(out, "", make_string_formatter(blank_used), "\n");  }();
sort(E.begin(), E.end(), ([&](auto&& _1, auto&& _2, auto&&... _other_args){(void)_1;(void)_2; return get<2>(_1) < get<2>(_2);}));
vector<tuple<int, int, LL>> unusedE;
DSU dsuE(N);
LL w = 0;
LL ans = 0;
for(auto[u, v, x] : E) {
	w ^= x;
	if(dsu.find(u) == dsu.find(v)) {
		unusedE.emplace_back(u, v, x);
	} else {
		ans += x;
		dsu.join(u, v);
		dsuE.join(u, v);
	}
}
if(blank_used + int(E.size()) < LL(N) * LL(N - 1) / 2) {
	[&]() { auto& out = cout; put_stream(out, "", make_string_formatter(ans), "\n");  }();
	return 0;
}
for(auto[u, v, x] : unusedE) {
	if(dsuE.find(u) != dsuE.find(v)) {
		w = min(w, x);
	}
}
[&]() { auto& out = cout; put_stream(out, "", make_string_formatter(ans + w), "\n");  }();

END