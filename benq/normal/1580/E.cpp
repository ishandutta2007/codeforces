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
const uint64_t BIG = 1e18; // not too close to LLONG_MAX
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
	++hi; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	--lo; assert(lo <= hi); // assuming f is decreasing
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

/**
 * Description: shortest path
 * Source: own
 * Verification: https://open.kattis.com/problems/shortestpath1
 */

template<class C, bool directed> struct Dijkstra {
	int SZ; V<C> dist; 
	V<V<pair<int,C>>> adj;
	void init(int _SZ) { SZ = _SZ; adj.clear(); adj.rsz(SZ); }
	void ae(int u, int v, C cost) {
		adj[u].pb({v,cost}); if (!directed) adj[v].pb({u,cost}); }
	void gen(int st) {
		dist.assign(SZ,numeric_limits<C>::max());
		using T = pair<C,int>; pqg<T> pq; 
		auto ad = [&](int a, C b) {
			if (dist[a] <= b) return;
			pq.push({dist[a] = b,a});
		}; ad(st,0);
		while (sz(pq)) {
			T x = pq.top(); pq.pop(); if (dist[x.s] < x.f) continue;
			each(y,adj[x.s]) ad(y.f,x.f+y.s);
		}
	}
};

int N,M,Q;

V<uint64_t> W;
Dijkstra<ll,0> D;
vi bad;
vi pre_, pre;
vl dist;

vi with_illegal[200000];

// AR<int,2> min_idx[MX];

AR<uint64_t,2> get_val(AR<int,2> a) {
	return {W.at(a[0]), a[1] == -1 ? BIG : W.at(a[1])};
}

// struct Seg {
// 	AR<int,2> mn_idx;
// 	int l, r;
// 	bool operator<(const Seg& other) const {
// 		return get_val(mn_idx) > get_val(other.mn_idx);
// 	}
// };

map<int,AR<int,2>> segs;

// V<Seg> segs;
// set<Seg> segs;

int count_illegal(int x, int r) {
	return upb(with_illegal[x],r);
	// int ans = 0;
	// for (int i: with_illegal[x]) ans += l <= i && i <= r;
	// return ans;

}

int count_illegal(int x, int l, int r) {
	assert(x >= 0);
	return count_illegal(x,r)-count_illegal(x,l-1);
	// int illegal = 0;
	// FOR(i,l,r+1) illegal += (pre[i] == x);
	// return illegal;
}

int count_legal(int x, int l, int r) {
	return r-l+1-count_illegal(x,l,r);
}

AR<int,2> upd_min_idx(AR<int,2> p, int x) {
	vi cands{x};
	F0R(i,2) if (p[i] != -1) cands.pb(p[i]);
	remDup(cands);
	sort(all(cands),[](int a, int b) { return mp(W[a],a) < mp(W[b],b); }); // well-define order
	p = {-1,-1};
	F0R(i,min(sz(cands),2)) p[i] = cands[i];
	return p;
}

pair<uint64_t,int> get_pair(int x) {
	if (x == -1) return {BIG,x};
	return {W.at(x),x};
}

uint64_t cur_ans;
AR<int,MX> endpoint;

void _process_W(int k, uint64_t nval) {
	const int idx = int(ub(all(dist),D.dist[k])-begin(dist));
	if (idx == sz(dist)) return;
	auto old_contrib = [&](map<int,AR<int,2>>::iterator it) -> uint64_t {
		if (it->s.at(0) == -1) return 0;
		uint64_t illegal = count_illegal(it->s[0],it->f,next(it)->f-1);
		const uint64_t len = next(it)->f-it->f;
		uint64_t res = 0;
		res += (len-illegal)*W.at(it->s.at(0));
		if (illegal) res += illegal*W.at(it->s.at(1));
		return res;
	};
	// auto new_contrib = [&](map<int,AR<int,2>>::iterator it) {
	// 	swap(W.at(k),nval);
	// 	auto res = old_contrib(it);
	// 	swap(W.at(k),nval);
	// 	return res;
	// };
	auto set_last_dif = [&](map<int,AR<int,2>>::iterator it) {
		if (it->s.at(0) == k) {
			endpoint.at(k) = next(it)->f;
			const int prev_ind = prev(it)->s.at(0);
			if (prev_ind != k && prev_ind != -1) {
				endpoint.at(prev_ind) = it->f;
			}
		}
	};
	
	auto it = prev(segs.ub(idx));
	for (;next(it) != end(segs);) {
		if (it->s[0] == k) {
			// it's the min already!
			// nothing changes (except the answer) ...
			assert(endpoint.at(k) >= next(it)->f);
			auto IT = segs.find(endpoint.at(k)); assert(IT != end(segs));
			cur_ans += count_legal(k,it->f,IT->f-1)*(nval-W.at(k));
			it = IT;
		} else if (it->s[1] == k) { // one-time thing
			// it's the second min
			cur_ans -= old_contrib(it);
			swap(W.at(k),nval);
			it->s = upd_min_idx(it->s,k);
			cur_ans += old_contrib(it);
			swap(W.at(k),nval);
			set_last_dif(it);
			++it;
		} else {
			if (mp(nval,k) < get_pair(it->s[1])) {
				if (it->f < idx) {
					segs[idx] = it->s;
					++it;
				} else {
					cur_ans -= old_contrib(it);
					swap(W.at(k),nval);
					it->s = upd_min_idx(it->s,k);
					cur_ans += old_contrib(it);
					swap(W.at(k),nval);
					set_last_dif(it);
					bool yes_erase = false;
					if (it != begin(segs) && it->s == prev(it)->s) {
						yes_erase = true;
					}
					++it;
					if (yes_erase) segs.erase(prev(it));
				}
			} else break;
		}
	}
}

void process_W(int k, uint64_t nval) {
	_process_W(k,nval);
	W.at(k) = nval;
}

uint64_t get_ans() {
	return cur_ans;
	// uint64_t ans = 0;
	// for (auto it = begin(segs); next(it) != end(segs); ++it) {
	// 	if (it != begin(segs)) assert(it->s != prev(it)->s);
	// 	uint64_t illegal = count_illegal(it->s[0],it->f,next(it)->f-1);
	// 	const uint64_t len = next(it)->f-it->f;
	// 	ans += (len-illegal)*W.at(it->s.at(0));
	// 	if (illegal) ans += illegal*W.at(it->s.at(1));
	// }
	// assert(ans == cur_ans);
	// // dbg("FOUND",ans,cur_ans);
	// return cur_ans;
}

int main() {
	setIO();
	re(N,M,Q);
	D.init(N);
	W.rsz(N);  re(W);
	rep(M) {
		ints(u,v,d);
		--u,--v;
		D.ae(u,v,d);
	}
	D.gen(0);
	pre_ = vi(N,-1);
	// dbg("GENED");
	FOR(i,1,N) {
		int in_deg = 0;
		each(t,D.adj[i]) if (D.dist[t.f]+t.s == D.dist[i]) {
			++in_deg;
			pre_.at(i) = t.f;
		}
		assert(in_deg > 0);
		if (in_deg == 1) bad.pb(i);
		if (pre_.at(i) == 0) pre_.at(i) = -1;
	}
	// dbg(bad);
	sort(all(bad),[&](int x, int y) { return D.dist[x] < D.dist[y]; });
	vpi queries;
	rep(Q) {
		ints(K,X);
		--K;
		W.at(K) += X;
		queries.pb({K,X});
	}
	reverse(all(queries));
	for (int i: bad) {
		// min_idx[i] = {-1,-1};
		dist.pb(D.dist[i]);
	}
	segs[0] = {-1,-1};
	segs[sz(bad)] = {-1,-1};
	// segs.pb(Seg{{-1,-1},0,sz(bad)-1});
	pre = vi(sz(bad));
	F0R(i,sz(bad)) pre.at(i) = pre_[bad[i]];
	F0R(i,sz(bad)) if (pre.at(i) != -1) with_illegal[pre.at(i)].pb(i);
	F0R(i,N) process_W(i,W.at(i));
	V<uint64_t> ans;
	ans.pb(get_ans());
	for (auto [K,X]: queries) {
		process_W(K,W.at(K)-X);
		ans.pb(get_ans());
	}
	reverse(all(ans));
	each(t,ans) ps(t);
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/