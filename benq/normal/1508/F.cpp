#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } // element that doesn't exist from (multi)set

#define tcTUU tcT, class ...U

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); // pairs

	// re: read
	tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

	// rv: resize and read vectors
	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	// dumb shortcuts to read in ints
	void decrement() {} // subtract one from each
	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
	#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
	tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	tcT> str bit_vec(T t) { // bit vector to string
		str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
	tcTU> str ts(pair<T,U> p); // pairs
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
		// convert container to string w/ separator sep
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	// for nested DS
	template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
	  ts_lev(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		F0R(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	// print w/ no spaces
	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	// print w/ spaces, end with newline
	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	// debug to cerr
	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...) 0
		#define dbgl(lev,x) 0
	#endif
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		// cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
}

vi bit(25005,MOD);
void upd_fenwick(int x, int y) {
	for (;x; x -= x&-x) ckmin(bit[x],y);
}
int query_fenwick(int x) {
	int ans = MOD;
	for (;x<sz(bit); x+=x&-x) ckmin(ans,bit[x]);
	return ans;
}

// /**
//  * Description: range sum queries and point updates for $D$ dimensions
//  * Source: https://codeforces.com/blog/entry/64914
//  * Verification: SPOJ matsum
//  * Usage: \texttt{BIT<int,10,10>} gives 2D BIT
//  * Time: O((\log N)^D)
//  */

// template <class T, int ...Ns> struct BIT {
// 	T val = 0; void upd(T v) { val += v; }
// 	T query() { return val; }
// };
// template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
// 	BIT<T,Ns...> bit[N+1];
// 	template<typename... Args> void upd(int pos, Args... args) { assert(pos > 0);
// 		for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); }
// 	template<typename... Args> T sum(int r, Args... args) {
// 		T res=0; for (;r;r-=r&-r) res += bit[r].query(args...); 
// 		return res; }
// 	template<typename... Args> T query(int l, int r, Args... 
// 		args) { return sum(r,args...)-sum(l-1,args...); }
// }; 
// template<class T, int N> int get_kth(const BIT<T,N>& bit, T des) { 
// 	assert(des > 0);
// 	int ind = 0;
// 	for (int i = 1<<bits(N); i; i /= 2)
// 		if (ind+i <= N && bit.bit[ind+i].val < des)
// 			des -= bit.bit[ind += i].val;
// 	assert(ind < N); return ind+1;
// }

int N,Q;
vpi imp;
vi A, rev_A;
vpi _ranges, ranges, cand;
vpi cand_left[25005], cand_right[25005];

void gen_cands() {
	ranges = _ranges;
	const int B = max(int(N/sqrt(Q)),1);
	sort(all(ranges),[&](pi a, pi b) {
		if (a.f/B != b.f/B) return a.f < b.f;
		return a.s < b.s;
	});
	set<int> s;
	int l = 1, r = 0;
	each(t,ranges) {
		auto ins = [&](int x) {
			auto it = s.ins(x).f;
			if (it != begin(s)) cand.pb({*prev(it),*it});
			if (next(it) != end(s)) cand.pb({*it,*next(it)});
		};
		auto del = [&](int x) {
			auto it = s.find(x);
			if (it != begin(s) && next(it) != end(s)) cand.pb({*prev(it),*next(it)});
			s.erase(it);
		};
		while (l > t.f) ins(A[--l]);
		while (r < t.s) ins(A[++r]);
		while (l < t.f) del(A[l++]);
		while (r > t.s) del(A[r--]);
	}
	sor(cand); cand.erase(unique(all(cand)),end(cand));
	F0R(i,sz(cand)) {
		int lo = rev_A[cand[i].f], hi = rev_A[cand[i].s];
		if (lo < hi) cand_right[lo].eb(hi,i);
		else cand_left[lo].eb(hi,i);
	}
	swap(ranges,_ranges);
}

V<AR<int,3>> ev[MX];
vpi add[MX];

void build_ivals() {
	A.pb(0);
	FOR(i,1,N+1) {
		reverse(all(cand_left[i]));
		reverse(all(cand_right[i]));
		cand_left[i].eb(0,-1), cand_right[i].eb(N+1,-1);
		// dbg("OO",i,cand_left[i],cand_right[i]);
		for (int il = 0, ir = 0; il < sz(cand_left[i])-1 || ir < sz(cand_right[i])-1; ) {
			// dbg("??",il,ir);
			if (A[cand_left[i][il].f] > A[cand_right[i][ir].f]) {
				assert(il < sz(cand_left[i])-1);
				int id = cand_left[i][il].s;
				ev[cand_left[i][il].f].pb({i,id,0});
				ev[cand_left[i][il+1].f].pb({i,id,1});
				ev[cand_left[i][il].f].pb({cand_right[i][ir].f,id,1});
				++il;
			} else {
				assert(ir < sz(cand_right[i])-1);
				int id = cand_right[i][ir].s;
				assert(cand_right[i][ir].f < cand_right[i][ir+1].f);
				ev[i].pb({cand_right[i][ir].f,id,0});
				ev[i].pb({cand_right[i][ir+1].f,id,1});
				ev[cand_left[i][il].f].pb({cand_right[i][ir].f,id,1});
				++ir;
			}
		}
	}
	F0R(i,Q) add[ranges[i].f].pb({ranges[i].s,i});
}

int main() {
	setIO(); re(N,Q);
	A.rsz(N+1); FOR(i,1,N+1) re(A[i]);
	rev_A.rsz(N+1); FOR(i,1,N+1) rev_A[A[i]] = i;

	_ranges.rsz(Q); re(_ranges);
	gen_cands();
	build_ivals();

	dbg(cand);
	vi in(sz(cand),Q), out(sz(cand),Q);
	FOR(i,1,N+1) {
		each(t,add[i]) upd_fenwick(t.f,t.s);
		each(t,ev[i]) {
			dbg("HA",i,t);
			if (t[2] == 0) {
				ckmin(in[t[1]],query_fenwick(t[0]));
			} else {
				ckmin(out[t[1]],query_fenwick(t[0]));
			}
		}
	}
	vi ans(Q+1);
	F0R(i,sz(cand)) {
		dbg("OOPS",i,in[i],out[i]);
		assert(in[i] <= out[i]);
		++ans[in[i]]; --ans[out[i]];
	}
	F0R(i,Q) {
		if (i) ans[i] += ans[i-1];
		ps(ans[i]);
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/