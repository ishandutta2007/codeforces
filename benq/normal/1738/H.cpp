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

namespace TwoWayPal {

str S;
vi len{0, -1};
V<AR<int, 26>> fail(2), child(2);
vb active(2);

vi pref_pal{0}, suf_pal{0}, ans{0}, last_set{-1};

void init(str _S) {
	S = _S;
	each(t, fail.at(0)) t = 1;
}

void set_last(int cur) {
	if (!active.at(cur)) {
		last_set.bk = cur;
		active.at(cur) = 1;
		++ans.bk;
	}
}

void append(int i) {
	const int new_len = sz(pref_pal);
	pref_pal.pb(pref_pal.bk);
	suf_pal.pb(suf_pal.bk);
	ans.pb(ans.bk);
	last_set.pb(-1);
	const int c = S.at(i) - 'a';

	if (len.at(suf_pal.bk) == new_len - 1 ||
		S.at(i) != S.at(i - len.at(suf_pal.bk) - 1)) {
		suf_pal.bk =
			fail.at(suf_pal.bk).at(c); // longest suffix pal with c preceding it
	}
	{
		int cur = suf_pal.bk;
		if (!child.at(cur).at(c)) {
			const int nxt = sz(len);
			child.at(cur).at(c) = nxt;
			const int link = child.at(fail.at(cur).at(c)).at(c);
			assert(link != 1);
			len.pb(len.at(cur) + 2);
			fail.pb(fail.at(link));
			fail.bk.at(S.at(i - len.at(link)) - 'a') = link;
			child.eb();
			active.eb();
		}
		suf_pal.bk = child.at(cur).at(c);
	}
	// dbg("NEW LEN", new_len);
	if (len.at(suf_pal.bk) == new_len) pref_pal.bk = suf_pal.bk;
	set_last(suf_pal.bk);
	dbg("APPEND", i, ans.bk, len.at(pref_pal.bk), len.at(suf_pal.bk));
}

void prepend(int i) {
	const int new_len = sz(pref_pal);
	pref_pal.pb(pref_pal.bk);
	suf_pal.pb(suf_pal.bk);
	ans.pb(ans.bk);
	last_set.pb(-1);
	const int c = S.at(i) - 'a';

	if (len.at(pref_pal.bk) == new_len - 1 ||
		S.at(i) != S.at(i + len.at(pref_pal.bk) + 1)) {
		pref_pal.bk = fail.at(pref_pal.bk)
						  .at(c); // longest suffix pal with c preceding it
	}
	{
		int cur = pref_pal.bk;
		if (!child.at(cur).at(c)) {
			const int nxt = sz(len);
			child.at(cur).at(c) = nxt;
			const int link = child.at(fail.at(cur).at(c)).at(c);
			assert(link != 1);
			len.pb(len.at(cur) + 2);
			fail.pb(fail.at(link));
			fail.bk.at(S.at(i + len.at(link)) - 'a') = link;
			child.eb();
			active.eb();
		}
		pref_pal.bk = child.at(cur).at(c);
	}
	if (len.at(pref_pal.bk) == new_len) suf_pal.bk = pref_pal.bk;
	set_last(pref_pal.bk);
	dbg("PREPEND", i, ans.bk, len.at(pref_pal.bk), len.at(suf_pal.bk));
}

void undo() {
	pref_pal.pop_back();
	assert(sz(pref_pal));
	suf_pal.pop_back();
	ans.pop_back();
	if (last_set.bk != -1) { active.at(last_set.bk) = 0; }
	last_set.pop_back();
	dbg("UNDO", ans.bk);
}

int get_ans() { return ans.bk; }
} // namespace TwoWayPal

void recurse(const vpi &queries, int l, int r) {
	if (l == r) return;
	if (l + 1 == r) {
		dbg(queries.at(l));
		cout << TwoWayPal::get_ans() << "\n";
		return;
	}
	int m = (l + r) / 2;
	pi ival{queries.at(r - 1).f, queries.at(l).s};
	pi l_ival{queries.at(m - 1).f, queries.at(l).s};
	pi r_ival{queries.at(r - 1).f, queries.at(m).s};
	int undos = 0;
	auto undo_all = [&]() {
		while (undos) TwoWayPal::undo(), --undos;
	};

	for (int x = min(queries.at(l).s, queries.at(r - 1).f - 1);
		 x >= queries.at(m - 1).f; --x)
		TwoWayPal::prepend(x), ++undos;
	recurse(queries, l, m);
	undo_all();

	for (int x = max(queries.at(l).s + 1, queries.at(r - 1).f);
		 x <= queries.at(m).s; ++x)
		TwoWayPal::append(x), ++undos;
	recurse(queries, m, r);
	undo_all();
}

int main() {
	// read read read
	setIO();
	ints(Q);
	str S;
	vpi queries;
	int l = 0, r = -1;
	rep(Q) {
		str op;
		re(op);
		if (op == "push") {
			char c;
			re(c);
			S += c;
			++r;
		} else {
			++l;
		}
		queries.pb({l, r});
	}
	TwoWayPal::init(S);
	FOR(i, queries.bk.f, queries.ft.s + 1) TwoWayPal::append(i);
	recurse(queries, 0, sz(queries));
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */