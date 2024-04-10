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
mt19937 rng(1);
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

/**
 * Description: A set (not multiset!) with support for finding the $n$'th
 * element, and finding the index of an element. Change \texttt{null\_type} for
 * map. Time: O(\log N) Source: KACTL https://codeforces.com/blog/entry/11080
 * Verification: many
 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tcT > using Tree =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key
#define fbo find_by_order

void treeExample() {
	Tree<int> t, t2;
	t.insert(8);
	auto it = t.insert(10).f;
	assert(it == t.lb(9));
	assert(t.ook(10) == 1 && t.ook(11) == 2 && *t.fbo(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

/**
int atMost(Tree<pi>& T, int r) {
	return T.ook({r,MOD}); }
int getSum(Tree<pi>& T, int l, int r) {
	return atMost(T,r)-atMost(T,l-1); }
*/

/**
 * Description: Easy BBST. Use split and merge to implement insert and delete.
 * Time: O(\log N)
 * Source: https://cp-algorithms.com/data_structures/treap.html + others. Also
 * consider https://codeforces.com/contest/1340/submission/77861280 (no pointers
 * -> faster) https://codeforces.com/contest/1340/submission/77852254
 * (shared_ptr -> destroyed when nothing refers to it) Verification:
 * http://www.spoj.com/problems/ORDERSET/
 */

using pt = struct tnode *;
struct tnode { // OK
	int pri;
	ll val, lazy = 0;
	int immovable, sum_immovable;
	pt c[2]; // essential
	int sz;
	tnode(pair<ll, int> p) {
		pri = rng();
		val = p.f;
		sz = 1;
		immovable = !p.s;
		sum_immovable = immovable;
		c[0] = c[1] = nullptr;
	}
	pair<ll, int> get_pair() {
		assert(!lazy);
		assert(sz == 1);
		return {val, !immovable};
	}
	~tnode() { F0R(i, 2) delete c[i]; } /// assume no sharing of data
};
int getsz(pt x) { return x ? x->sz : 0; }
int getsum(pt x) { return x ? x->sum_immovable : 0; }
pt prop(pt x) { // lazy propagation
	if (!x) return x;
	x->val += x->lazy;
	F0R(i, 2) if (x->c[i]) x->c[i]->lazy += x->lazy;
	x->lazy = 0;
	return x;
}
pt calc(pt x) {
	pt a = x->c[0], b = x->c[1];
	x->sz = 1 + getsz(a) + getsz(b);
	x->sum_immovable = x->immovable + getsum(a) + getsum(b);
	return x;
}
void tour(pt x, vl &v) { // print values of nodes,
	if (!x) return;		 // inorder traversal
	prop(x);
	tour(x->c[0], v);
	v.pb(x->val);
	tour(x->c[1], v);
}
pair<pt, pt> split(pt t, ll v) { // >= v goes to the right
	if (!t) return {t, t};
	prop(t);
	if (t->val >= v) {
		auto p = split(t->c[0], v);
		t->c[0] = p.s;
		return {p.f, calc(t)};
	} else {
		auto p = split(t->c[1], v);
		t->c[1] = p.f;
		return {calc(t), p.s};
	}
}
pair<pt, pt> splitsz(pt t, int sz) { // sz nodes go to left
	if (!t) return {t, t};
	prop(t);
	if (getsz(t->c[0]) >= sz) {
		auto p = splitsz(t->c[0], sz);
		t->c[0] = p.s;
		return {p.f, calc(t)};
	} else {
		auto p = splitsz(t->c[1], sz - getsz(t->c[0]) - 1);
		t->c[1] = p.f;
		return {calc(t), p.s};
	}
}
pt merge(pt l, pt r) { //  keys in l < keys in r
	if (!l || !r) return l ?: r;
	prop(l), prop(r);
	pt t;
	if (l->pri > r->pri) l->c[1] = merge(l->c[1], r), t = l;
	else r->c[0] = merge(l, r->c[0]), t = r;
	return calc(t);
}
// pt ins(pt x, int v) { // insert v
// 	auto a = split(x, v), b = split(a.s, v + 1);
// 	return merge(a.f, merge(new tnode(v), b.s));
// }
// pt del(pt x, int v) { // delete v
// 	auto a = split(x, v), b = split(a.s, v + 1);
// 	return merge(a.f, b.s);
// }

pt t_mid = nullptr;
int N, D;
Tree<pair<ll, int>> tl, tr;

ll fbo(pt p, int pos) {
	assert(p);
	assert(pos < p->sz);
	prop(p);
	const int s = getsz(p->c[0]);
	if (pos == s) return p->val;
	if (pos < s) return fbo(p->c[0], pos);
	return fbo(p->c[1], pos - s - 1);
}

ll query(int pos) {
	--pos;
	assert(0 <= pos && pos < N);
	if (pos < sz(tl)) return tl.fbo(pos)->f;
	pos -= sz(tl);
	if (pos < t_mid->sz) return fbo(t_mid, pos);
	pos -= t_mid->sz;
	assert(pos < sz(tr));
	return tr.fbo(pos)->f;
}

pair<ll, int> peek_first() {
	auto [l, r] = splitsz(t_mid, 1);
	auto res = l->get_pair();
	t_mid = merge(l, r);
	return res;
}

pair<ll, int> poll_first() {
	auto [l, r] = splitsz(t_mid, 1);
	t_mid = r;
	return l->get_pair();
}

pair<ll, int> peek_last() {
	auto [l, r] = splitsz(t_mid, t_mid->sz - 1);
	assert(r && r->sz == 1);
	auto res = r->get_pair();
	t_mid = merge(l, r);
	return res;
}

ll first_zero() {
	pt cur = t_mid;
	if (!cur->sum_immovable) return BIG;
	ll ans = 0;
	while (true) {
		// dbg(cur->sz, cur->sum_immovable);
		assert(cur);
		assert(cur->sum_immovable);
		if (cur->c[0] && cur->c[0]->sum_immovable) {
			cur = cur->c[0];
			continue;
		}
		ans += getsz(cur->c[0]);
		if (cur->immovable) {
			// dbg("RETURN");
			return ans;
		}
		++ans;
		cur = cur->c[1];
	}
}

ll num_less(ll x) {
	auto [l, r] = split(t_mid, x);
	int res = getsz(l);
	t_mid = merge(l, r);
	return res;
}

ll cur_time = 0;

void advance(ll ntime) {
	while (cur_time < ntime) {
		dbg("ADVANCE", cur_time, ntime);
		// dbg("HUH", t_mid->sz);
		assert(t_mid && t_mid->sz);
		// assert(tr);
		if (!t_mid->sum_immovable) {
			ll max_iters = (ntime - cur_time) / t_mid->sz;
			int wut = D + t_mid->sz - 1;
			ckmin(max_iters, (begin(tr)->f - peek_last().f - 1) / wut);
			if (max_iters) {
				cur_time += t_mid->sz * max_iters;
				t_mid->lazy += (D + t_mid->sz - 1) * max_iters;
				continue;
			}
		}
		// dbg("AA");
		{
			ll max_steps = ntime - cur_time;
			ckmin(max_steps, first_zero());
			ckmin(max_steps,
				  num_less(begin(tr)->f - (D + t_mid->sz - 1))); // OK
			if (max_steps) {
				// dbg(max_steps);
				assert(max_steps > 0);
				assert(max_steps <= t_mid->sz);
				const int skip = D + t_mid->sz - 1;
				auto [l, r] = splitsz(t_mid, (int)max_steps);
				assert(l);
				cur_time += max_steps;
				l->lazy += skip;
				t_mid = merge(r, l);
				// dbg("SKIP 2");
				continue;
			}
		}
		// dbg("BB");
		++cur_time;
		while (1) { // OK
			// dbg("LOOP");
			assert(t_mid && t_mid->sz);
			dbg(t_mid->sz);
			dbg(peek_first());
			if (peek_first().s == 0) { // immovable
				tl.ins(poll_first());
				continue;
			}
			auto upper = peek_first().f;
			upper += D + t_mid->sz - 1;
			while (begin(tr)->f <= upper) {
				auto p = *begin(tr);
				tr.erase(p);
				t_mid = merge(t_mid, new tnode(p));
				++upper;
			}
			// dbg("MIDDLE", t_mid);
			auto p = poll_first();
			// dbg("POLLED");
			assert(p.s);
			pair<ll, int> np{p.f + D + getsz(t_mid), p.s};
			// dbg("MERGE", t_mid);
			t_mid = merge(t_mid, new tnode(np));
			break;
		}
		// dbg("DONE LOOP");
	}
	assert(cur_time == ntime);
}

int main() {
	// read read read
	setIO();
	re(N);
	re(D);
	// dbg("OH");
	ints(Q);
	vi A(N);
	re(A);
	str S;
	re(S);
	F0R(i, N) tr.ins({A[i], S[i] - '0'});
	tr.ins({4e18, 0});
	while (true) {
		auto it = begin(tr);
		if (it->s == 0) {
			tl.ins(*it);
			tr.erase(it);
			continue;
		}
		t_mid = new tnode(*it);
		assert(t_mid->get_pair() == *it);
		tr.erase(it);
		break;
	}
	dbg("INIT");
	V<tuple<int, int, int>> queries;
	F0R(q, Q) {
		ints(k, m);
		queries.pb({k, m, q});
	}
	sor(queries);
	vl ans(Q);
	for (auto [k, m, q] : queries) {
		advance(k);
		assert(sz(tl) + sz(tr) + t_mid->sz == N + 1);
		ans.at(q) = query(m);
	}
	each(t, ans) ps(t);

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */