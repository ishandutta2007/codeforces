#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string;		// yay python!

// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

const int MOD = (int)1e9 + 7; // 998244353;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(
	int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31 - __builtin_clz(x);
} // floor(log2(x))
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
} // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
} // divide a by b rounded down

tcT > bool ckmin(T &a, const T &b) {
	return b < a ? a = b, 1 : 0;
} // set a = min(a,b)
tcT > bool ckmax(T &a, const T &b) {
	return a < b ? a = b, 1 : 0;
} // set a = max(a,b)

tcTU > T fstTrue(T lo, T hi, U f) {
	++hi;
	assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true
		T mid = lo + (hi - lo) / 2;
		f(mid) ? hi = mid : lo = mid + 1;
	}
	return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
	--lo;
	assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true
		T mid = lo + (hi - lo + 1) / 2;
		f(mid) ? lo = mid : hi = mid - 1;
	}
	return lo;
}
tcT > void remDup(vector<T> &v) { // sort and remove duplicates
	sort(all(v));
	v.erase(unique(all(v)), end(v));
}
tcTU > void erase(T &t, const U &u) { // don't erase
	auto it = t.find(u);
	assert(it != end(t));
	t.erase(it);
} // element that doesn't exist from (multi)set

#define tcTUU tcT, class... U

inline namespace Helpers {
//////////// is_iterable
// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
// this gets used only when we can call begin() and end() on that type
tcT, class = void > struct is_iterable : false_type {};
tcT > struct is_iterable<
		  T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>
	: true_type {};
tcT > constexpr bool is_iterable_v = is_iterable<T>::value;

//////////// is_readable
tcT, class = void > struct is_readable : false_type {};
tcT > struct is_readable<T, typename std::enable_if_t<is_same_v<
								decltype(cin >> declval<T &>()), istream &>>>
	: true_type {};
tcT > constexpr bool is_readable_v = is_readable<T>::value;

//////////// is_printable
// // https://nafe.es/posts/2020-02-29-is-printable/
tcT, class = void > struct is_printable : false_type {};
tcT > struct is_printable<T, typename std::enable_if_t<is_same_v<
								 decltype(cout << declval<T>()), ostream &>>>
	: true_type {};
tcT > constexpr bool is_printable_v = is_printable<T>::value;
} // namespace Helpers

inline namespace Input {
tcT > constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
tcTUU > void re(T &t, U &...u);
tcTU > void re(pair<T, U> &p); // pairs

// re: read
tcT > typename enable_if<is_readable_v<T>, void>::type re(T &x) {
	cin >> x;
} // default
tcT > void re(complex<T> &c) {
	T a, b;
	re(a, b);
	c = {a, b};
} // complex
tcT > typename enable_if<needs_input_v<T>, void>::type
	  re(T &i); // ex. vectors, arrays
tcTU > void re(pair<T, U> &p) { re(p.f, p.s); }
tcT > typename enable_if<needs_input_v<T>, void>::type re(T &i) {
	each(x, i) re(x);
}
tcTUU > void re(T &t, U &...u) {
	re(t);
	re(u...);
} // read multiple

// rv: resize and read vectors
void rv(size_t) {}
tcTUU > void rv(size_t N, V<T> &t, U &...u);
template <class... U> void rv(size_t, size_t N2, U &...u);
tcTUU > void rv(size_t N, V<T> &t, U &...u) {
	t.rsz(N);
	re(t);
	rv(N, u...);
}
template <class... U> void rv(size_t, size_t N2, U &...u) { rv(N2, u...); }

// dumb shortcuts to read in ints
void decrement() {} // subtract one from each
tcTUU > void decrement(T &t, U &...u) {
	--t;
	decrement(u...);
}
#define ints(...)                                                              \
	int __VA_ARGS__;                                                           \
	re(__VA_ARGS__);
#define int1(...)                                                              \
	ints(__VA_ARGS__);                                                         \
	decrement(__VA_ARGS__);
} // namespace Input

inline namespace ToString {
tcT > constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

// ts: string representation to print
tcT > typename enable_if<is_printable_v<T>, str>::type ts(T v) {
	stringstream ss;
	ss << fixed << setprecision(15) << v;
	return ss.str();
} // default
tcT > str bit_vec(T t) { // bit vector to string
	str res = "{";
	F0R(i, sz(t)) res += ts(t[i]);
	res += "}";
	return res;
}
str ts(V<bool> v) { return bit_vec(v); }
template <size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
tcTU > str ts(pair<T, U> p);									 // pairs
tcT >
	typename enable_if<needs_output_v<T>, str>::type ts(T v); // vectors, arrays
tcTU > str ts(pair<T, U> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
tcT > typename enable_if<is_iterable_v<T>, str>::type ts_sep(T v, str sep) {
	// convert container to string w/ separator sep
	bool fst = 1;
	str res = "";
	for (const auto &x : v) {
		if (!fst) res += sep;
		fst = 0;
		res += ts(x);
	}
	return res;
}
tcT > typename enable_if<needs_output_v<T>, str>::type ts(T v) {
	return "{" + ts_sep(v, ", ") + "}";
}

// for nested DS
template <int, class T>
typename enable_if<!needs_output_v<T>, vs>::type ts_lev(const T &v) {
	return {ts(v)};
}
template <int lev, class T>
typename enable_if<needs_output_v<T>, vs>::type ts_lev(const T &v) {
	if (lev == 0 || !sz(v)) return {ts(v)};
	vs res;
	for (const auto &t : v) {
		if (sz(res)) res.bk += ",";
		vs tmp = ts_lev<lev - 1>(t);
		res.ins(end(res), all(tmp));
	}
	F0R(i, sz(res)) {
		str bef = " ";
		if (i == 0) bef = "{";
		res[i] = bef + res[i];
	}
	res.bk += "}";
	return res;
}
} // namespace ToString

inline namespace Output {
template <class T> void pr_sep(ostream &os, str, const T &t) { os << ts(t); }
template <class T, class... U>
void pr_sep(ostream &os, str sep, const T &t, const U &...u) {
	pr_sep(os, sep, t);
	os << sep;
	pr_sep(os, sep, u...);
}
// print w/ no spaces
template <class... T> void pr(const T &...t) { pr_sep(cout, "", t...); }
// print w/ spaces, end with newline
void ps() { cout << "\n"; }
template <class... T> void ps(const T &...t) {
	pr_sep(cout, " ", t...);
	ps();
}
// debug to cerr
template <class... T> void dbg_out(const T &...t) {
	pr_sep(cerr, " | ", t...);
	cerr << endl;
}
void loc_info(int line, str names) {
	cerr << "Line(" << line << ") -> [" << names << "]: ";
}
template <int lev, class T> void dbgl_out(const T &t) {
	cerr << "\n\n" << ts_sep(ts_lev<lev>(t), "\n") << "\n" << endl;
}
#ifdef LOCAL
#define dbg(...) loc_info(__LINE__, #__VA_ARGS__), dbg_out(__VA_ARGS__)
#define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)
#else // don't actually submit with this
#define dbg(...) 0
#define dbgl(lev, x) 0
#endif

const clock_t beg = clock();
#define dbg_time() dbg((db)(clock() - beg) / CLOCKS_PER_SEC)
} // namespace Output

inline namespace FileIO {
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
	cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
	// cin.exceptions(cin.failbit);
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) setIn(s + ".in"), setOut(s + ".out"); // for old USACO
}
} // namespace FileIO

// make sure to intialize ALL GLOBAL VARS between tcs!

/**
 * Description: Use in place of \texttt{complex<T>}.
 * Source: http://codeforces.com/blog/entry/22175, KACTL
 * Verification: various
 */

using T = db;		// or ll
const T EPS = 1e-9; // adjust as needed
using P = pair<T, T>;
using vP = V<P>;
using Line = pair<P, P>;
int sgn(T a) { return (a > EPS) - (a < -EPS); }
T sq(T a) { return a * a; }

bool close(const P &a, const P &b) {
	return sgn(a.f - b.f) == 0 && sgn(a.s - b.s) == 0;
}
T norm(const P &p) { return sq(p.f) + sq(p.s); }
T abs(const P &p) { return sqrt(norm(p)); }
T arg(const P &p) { return atan2(p.s, p.f); }
P conj(const P &p) { return P(p.f, -p.s); }
P perp(const P &p) { return P(-p.s, p.f); }
P dir(T ang) { return P(cos(ang), sin(ang)); }

P operator-(const P &l) { return P(-l.f, -l.s); }
P operator+(const P &l, const P &r) { return P(l.f + r.f, l.s + r.s); }
P operator-(const P &l, const P &r) { return P(l.f - r.f, l.s - r.s); }
P operator*(const P &l, const T &r) { return P(l.f * r, l.s * r); }
P operator*(const T &l, const P &r) { return r * l; }
P operator/(const P &l, const T &r) { return P(l.f / r, l.s / r); }
P operator*(const P &l, const P &r) {
	return P(l.f * r.f - l.s * r.s, l.s * r.f + l.f * r.s);
}
P operator/(const P &l, const P &r) { return l * conj(r) / norm(r); }
P &operator+=(P &l, const P &r) { return l = l + r; }
P &operator-=(P &l, const P &r) { return l = l - r; }
P &operator*=(P &l, const T &r) { return l = l * r; }
P &operator/=(P &l, const T &r) { return l = l / r; }
P &operator*=(P &l, const P &r) { return l = l * r; }
P &operator/=(P &l, const P &r) { return l = l / r; }

P unit(const P &p) { return p / abs(p); }
T dot(const P &a, const P &b) { return a.f * b.f + a.s * b.s; }
T dot(const P &p, const P &a, const P &b) { return dot(a - p, b - p); }
T cross(const P &a, const P &b) { return a.f * b.s - a.s * b.f; }
T cross(const P &p, const P &a, const P &b) { return cross(a - p, b - p); }
P reflect(const P &p, const Line &l) {
	P a = l.f, d = l.s - l.f;
	return a + conj((p - a) / d) * d;
}
P foot(const P &p, const Line &l) { return (p + reflect(p, l)) / (T)2; }
bool onSeg(const P &p, const Line &l) {
	return sgn(cross(l.f, l.s, p)) == 0 && sgn(dot(p, l.f, l.s)) <= 0;
}

ll solve(int tc) {
	ints(N);
	AR<int, 3> goal;
	re(goal);
	V<tuple<int, db, int>> tasks;
	rep(N) {
		int r, type, d;
		re(r, type, d);
		--type;
		tasks.pb({d, r + uniform_real_distribution<db>(0, 1.0 / 3)(rng), type});
	}
	sort(rall(tasks));
	auto greed = [&](AR<db, 3> adds) -> pair<ll, AR<int, 3>> {
		int j = 0;
		priority_queue<pair<db, int>> pq;
		ll ans = 0;
		AR<int, 3> cnt{};
		ROF(i, 1, goal[0] + goal[1] + goal[2] + 1) {
			for (; j < sz(tasks) && get<0>(tasks.at(j)) >= i; ++j) {
				pq.push({get<1>(tasks.at(j)) + adds.at(get<2>(tasks.at(j))),
						 get<2>(tasks.at(j))});
			}
			if (sz(pq)) {
				ans += (ll)floor(pq.top().f - adds.at(pq.top().s));
				++cnt.at(pq.top().s);
				pq.pop();
			}
		}
		return {ans, cnt};
	};
	// dbg("SOLVING", sz(tasks));
	// for (auto [d, r,])
	AR<AR<db, 2>, 3> bounds;
	F0R(i, 3) bounds[i] = {-1e10, 1e10};
	F0R(i, 3) {
		AR<db, 3> to_test{-1e10, -1e10, -1e10};
		to_test.at(i) = 1e10;
		auto [_, cnt] = greed(to_test);
		if (cnt.at(i) < goal.at(i)) return -1;
	}
	// bounds = {{{-1010798003.829446730611380, -992605229.409579332394060},
	// 		   {-577140.846479195259008, 10127314.814814814793863},
	// 		   {999710648.148148148145992, 1000670689.014631915837526}}};
	while (true) {
		AR<db, 2> sums{};
		F0R(i, 3) F0R(j, 2) sums.at(j) += bounds.at(i).at(j);
		F0R(i, 3) {
			// y-x, z-y, x-z
			// y-x >=
			ckmax(bounds.at(i).at(0), bounds.at(i).at(1) - sums.at(1));
			ckmin(bounds.at(i).at(1), bounds.at(i).at(0) - sums.at(0));
			if (bounds.at(i).at(1) - bounds.at(i).at(0) < 1e-8) return -1;
		}

		AR<db, 3> to_test;
		F0R(i, 3) to_test.at(i) = (bounds.at(i).at(0) + bounds.at(i).at(1)) / 2;

		db avg = 0;
		each(t, to_test) avg += t;
		avg /= 3;
		each(t, to_test) t -= avg;
		dbg(to_test);
		// F0R(i, 3) {
		// if (!(bounds[i][0] <= to_test[i] && to_test[i] <= bounds[i][1]))
		// { 	ps("FAIL", i); 	ps(bounds); 	ps(to_test); 	exit(0);
		// }
		// assert(bounds[i][0] <= to_test[i] && to_test[i] <= bounds[i][1]);
		// }
		// dbg(bounds);
		// dbg(to_test);
		// exit(0);
		AR<db, 3> adds{0, to_test[0], to_test[0] + to_test[1]};
		auto [ans, cnt] = greed(adds);
		if (cnt[0] + cnt[1] + cnt[2] != goal[0] + goal[1] + goal[2]) return -1;
		if (cnt == goal) { return ans; }
		F0R(i, 3) {
			int j = (i + 1) % 3;
			if (cnt[i] > goal[i] && cnt[j] < goal[j]) {
				// need to increase adds.at(j)-adds.at(i)
				ckmax(bounds.at(i).at(0), to_test.at(i));
			} // x[j] - x[i] >= ??
			if (cnt[i] < goal[i] && cnt[j] > goal[j]) {
				ckmin(bounds.at(i).at(1), to_test.at(i));
			}
		}
	}
}

int main() {
	setIO();
	int TC;
	re(TC);
	vl res;
	FOR(i, 1, TC + 1) res.pb(solve(i));
	each(t, res) ps(t);
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */