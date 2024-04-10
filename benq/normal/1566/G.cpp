#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
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
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
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
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

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

	const clock_t beg = clock();
	#define dbg_time() dbg((db)(clock()-beg)/CLOCKS_PER_SEC)
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

//  1. min and other edge
//  2. one adjacent to each endpoint of min, min not taken
//  3. three adjacent to one vertex (one endpoint of min)

int N,M;
// V<tuple<int,int,int>> edge_info;
map<pi,pi> cur_edges;
multiset<pi> adj_weights[100005];

// vpi mods;


// void ins_edge(int e) {
// 	mods.pb({e,1});
// 	auto [u,v,w] = edge_info[e];
// 	auto it = cur_edges.find({u,v}); assert(it == end(cur_edges));
// 	cur_edges[{u,v}] = e;
// }

// void del_edge(int e) {
// 	mods.pb({e,-1});
// 	auto [u,v,w] = edge_info[e];
// 	auto it = cur_edges.find({u,v}); assert(it != end(cur_edges));
// 	cur_edges.erase(it);
// }

const int SZ = 1<<18;
V<tuple<int,int,int>> seg[2*SZ];

void comb(const V<tuple<int,int,int>>& a, const V<tuple<int,int,int>>& b, V<tuple<int,int,int>>& c) {
	c.clear();
	set<int> verts_so_far;
	auto try_add = [&](tuple<int,int,int> x) {
		if (!sz(c)) {
			c.pb(x);
			return;
		}
		auto [w,u,v] = x;
		auto test = [&](int r) -> bool {
			if (r == u || r == v) return 0;
			vpi bad;
			each(e,c) {
				auto [_,uu,vv] = e;
				if (uu == r || vv == r) continue;
				bad.pb({uu,vv});
			}
			if (!sz(bad)) return 1;
			auto test2 = [&](int s) {
				if (s == u || s == v) return 0;
				each(e,bad) {
					if (e.f == s || e.s == s) continue;
					return 0;
				}
				return 1;
			};
			return test2(bad[0].f) || test2(bad[0].s);
		};
		// if there's a single vert you can remove
		if (test(get<1>(c[0])) || test(get<2>(c[0]))) {
			c.pb(x);
			return;
		}
	};
	int ia = 0, ib = 0;
	while (ia < sz(a) && ib < sz(b)) {
		if (get<0>(a[ia]) < get<0>(b[ib])) try_add(a[ia++]);
		else try_add(b[ib++]);
	}
	while (ia < sz(a)) try_add(a[ia++]);
	while (ib < sz(b)) try_add(b[ib++]);
}

void upd(int pos, const V<tuple<int,int,int>>& v) {
	pos += SZ; seg[pos] = v;
	for (pos /= 2; pos; pos /= 2)
		comb(seg[2*pos],seg[2*pos+1],seg[pos]);
}

int cnt = 0;

void ins(int u, int v, int w) {
	if (u > v) swap(u,v);
	adj_weights[u].ins({w,v}), adj_weights[v].ins({w,u});
	auto it = cur_edges.find({u,v}); assert(it == end(cur_edges));
	int label = cnt++;
	cur_edges[{u,v}] = {label,w};
	upd(label,{{w,u,v}});
}

void del(int u, int v) {
	if (u > v) swap(u,v);
	auto it = cur_edges.find({u,v}); assert(it != end(cur_edges));
	auto [label,w] = it->s; cur_edges.erase(it);
	erase(adj_weights[u],pi{w,v}), erase(adj_weights[v],pi{w,u});
	upd(label,{});
}

//  1. min and other edge
//  2. one adjacent to each endpoint of min, min not taken
//  3. three adjacent to one vertex (one endpoint of min)

bool isect(tuple<int,int,int> a, tuple<int,int,int> b) {
	if (get<1>(a) == get<1>(b)) return 1;
	if (get<1>(a) == get<2>(b)) return 1;
	if (get<2>(a) == get<1>(b)) return 1;
	if (get<2>(a) == get<2>(b)) return 1;
	return 0;
}

ll get_1(tuple<int,int,int> edge) {
	const auto& c = seg[1];
	each(e,c) if (!isect(edge,e)) 
		return get<0>(edge)+get<0>(e);
	return BIG;
}

ll get_2(int x, int y) {
	// if (sz(adj_weights[x]) < 2 || sz(adj_weights[y]) < 2) return BIG;
	ll ret = BIG;
	for (auto it_x = begin(adj_weights[x]); it_x != end(adj_weights[x]); ++it_x) {
		if (it_x->s == y) continue;
		bool flag = 0;
		for (auto it_y = begin(adj_weights[y]); it_y != end(adj_weights[y]); ++it_y) {
			if (it_y->s == x) continue;
			if (it_y->s == it_x->s) {
				flag = 1;
				continue;
			}
			ckmin(ret,(ll)it_x->f+it_y->f);
			break;
		}
		if (!flag) break;
	}
	return ret;
	// auto it_x = next(begin(adj_weights[x]));
	// auto it_y = next(begin(adj_weights[y]));
	// dbg("GET 2",x,y,adj_weights[x],adj_weights[y]);
	// if (it_x->s != it_y->s) return it_x->f+it_y->f;
	// ll ret = BIG;
	// if (next(it_x) != end(adj_weights[x])) {
	// 	ckmin(ret,(ll)next(it_x)->f+it_y->f);
	// }
	// if (next(it_y) != end(adj_weights[y])) {
	// 	ckmin(ret,(ll)it_x->f+next(it_y)->f);
	// }
	// return ret;
	// if (sz(adj_weights[x]) < 2) return BIG;
	// return *next(begin(adj_weights[x]));
}

ll get_3(int x) {
	if (sz(adj_weights[x]) < 3) return BIG;
	auto it = begin(adj_weights[x]);
	ll a = (it++)->f;
	ll b = (it++)->f;
	ll c = (it++)->f;
	return a+b+c;
}

ll query() {
	// each(e,seg[1]) {
	// 	auto [w,u,v] = e;
	// 	ps(w,u,v);
	// }
	// ps("----");

	assert(sz(seg[1]));
	auto [w,u,v] = seg[1][0];
	// ll ans = BIG; 
	ll ans = get_1(seg[1][0]);
	ckmin(ans,get_2(u,v));
	ckmin(ans,get_3(u));
	ckmin(ans,get_3(v));
	return ans;
}

int main() {
	setIO();
	re(N,M);
	F0R(i,M) {
		ints(u,v,w);
		if (u > v) swap(u,v);
		ins(u,v,w);
		// dbg("INSERTING ...");
		// int e = make_edge(u,v,w);
		// ins_edge(e);
	}
	ps(query());
	ints(Q);
	rep(Q) {
		ints(t,u,v); 
		if (t == 0) {
			del(u,v);
		} else {
			ints(w);
			ins(u,v,w);
		}
		ps(query());
	}

	// dbg(mods);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/