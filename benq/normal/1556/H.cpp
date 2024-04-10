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
mt19937 rng(0);
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

/**
 * Description: Disjoint Set Union with path compression
 	* and union by size. Add edges and test connectivity. 
 	* Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL
 * Verification: *
 */

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

vi MAX_D;

vpi edges;
vi cost;

int N,M,K;
struct Gmat { // graphic matroid
	DSU D;
	Gmat() { D.init(N); }
	void ins(int i) { assert(D.unite(edges[i].f,edges[i].s)); }
	bool indep(int i) {
		return !D.sameSet(edges[i].f,edges[i].s);
	}
};

struct Cmat { // colorful matroid
	vi cnt;
	Cmat() { cnt = vi(K); }
	void ins(int i) {
		int a = edges[i].f, b = edges[i].s;
		if (a < K) assert((++cnt.at(a)) <= MAX_D.at(a));
		if (b < K) assert((++cnt.at(b)) <= MAX_D.at(b));
	}
	bool indep(int i) { 
		bool res = 1;
		int a = edges[i].f, b = edges[i].s;
		if (a < K) res &= cnt.at(a) < MAX_D.at(a);
		if (b < K) res &= cnt.at(b) < MAX_D.at(b);
		return res;
	}
};

bool is_special(int x) {
	assert(x < M);
	return edges[x].s < K;
}

/**
 * Description: Shortest Path w/ negative edge weights
    * Can be useful with linear programming
    * Constraints of the form x_i-x_j<k
 * Source: Own
 * Verification: 
    * https://open.kattis.com/problems/shortestpath3
    * https://probgate.org/viewproblem.php?pid=378
 */

// template<int SZ> struct BellmanFord {
//     int n;
//     vector<pair<pi,int>> ed;
//     void ae(int u, int v, int w) { 
//         ed.pb({{u,v},w}); }
//     void init(int _n, int s) {
//         n = _n; F0R(i,n) dist[i] = BIG; 
//         dist[s] = 0;
//         F0R(i,n) each(a,ed) if (dist[a.f.f] < BIG)
//             ckmin(dist[a.f.s],dist[a.f.f]+a.s);
//     }
//     vi path_to(int s, int t) {

//     }
// };

const int FACTOR = 500;

vpi adj[2500];

vi get_path(int cnt, const V<pair<pi,int>>& edges) { // N*N^2

	// F0R(i,M+2) adj[i].clear();
	// each(t,edges) adj[t.f.f].pb({t.f.s,t.s});
	// vi dist(M+2,MOD), pre(M+2,-1);
	// priority_queue<pi,vpi,greater<pi>> pq;
	// auto ad = [&](int x, int d, int p) {
	// 	// dbg("ADD",x,d,p);
	// 	if (ckmin(dist[x],d)) {
	// 		// dbg("UPDATING",x);
	// 		// dbg("ADD TO PQ",x,d,p);
	// 		pq.push({dist[x],x});
	// 		pre[x] = p;
	// 	}
	// };
	// ad(M,0,-1);
	// while (sz(pq)) {
	// 	pi p = pq.top(); pq.pop();
	// 	if (p.f != dist[p.s]) continue;
	// 	each(t,adj[p.s]) ad(t.f,p.f+t.s,p.s);
	// }


	vi pre(cnt,-1), dist(cnt,MOD); dist[cnt-2] = 0;
	bool upd = 1;
	while (upd) {
		upd = 0;
		each(t,edges) if (dist[t.f.f] != MOD)
			if (ckmin(dist[t.f.s],dist[t.f.f]+t.s)) 
				pre[t.f.s] = t.f.f, upd = 1;
	}
	assert(dist[cnt-2] >= 0);

	// // dbg("FOUND",dist[M+1]);
	if (dist[cnt-1] != MOD) {
		vi path{cnt-1};
		while (path.bk != cnt-2) path.pb(pre[path.bk]);
		reverse(all(path));
		return path;
	}
	return {};

	// return dist[M+1];
	// M,M+1
}

struct MatroidIsect {
	vb iset;
	bool augment() { // N^3 edges
		V<pair<pi,int>> tmp_ed;
		vi id(M+2,-1);
		int cnt = 0;
		vi rid;
		F0R(i,M) if (iset[i]) {
			id[i] = cnt++;
			rid.pb(i);
		}
		id[M] = cnt++; rid.pb(M);
		id[M+1] = cnt++; rid.pb(M+1);
		vl to(M), from(M);
		F0R(i,M+1) if (i == M || (iset.at(i) && !is_special(i))) {
			Gmat gmat; Cmat cmat;
			F0R(j,M) if (iset[j] && j != i) gmat.ins(j), cmat.ins(j);
			F0R(j,M) if (!iset[j] && !is_special(j)) {
				if (gmat.indep(j)) {
					// dbg("EDGE A",i,j);
					to[j] |= 1LL<<id[i];
					// tmp_ed.pb({{i,j},-(i == M ? 0 : cost.at(i))*FACTOR+1});
				}
				if (cmat.indep(j)) {
					// dbg("EDGE B",j,i);
					from[j] |= 1LL<<(i == M ? id[M+1] : id[i]);
					// int sink = i; if (i == M) sink = M+1;
					// tmp_ed.pb({{j,sink},cost.at(j)*FACTOR+1});
				}
			}
		}
		// dbg("CNT",cnt);
		V<vi> dist(cnt,vi(cnt,MOD));
		F0R(i,cnt) dist.at(i).at(i) = 0;
		V<vi> between(cnt,vi(cnt,-1));
		vl lef(cnt,(1LL<<cnt)-1);
		// dbg("HA1");
		F0R(i,M) {
			F0R(a,cnt) if (to[i]&(1LL<<a)) {
				while (1) {
					ll huh = lef.at(a)&from.at(i); if (huh == 0) break;
					int b = __builtin_ctzll(huh);
					assert(from[i]&(1LL<<b));
					lef.at(a) ^= 1LL<<b;
					dist.at(a).at(b) = cost.at(i);
					between[a][b] = i;
					// dbg("ADDING EDGE",a,b,cost.at(i));
				}
				// F0R(b,cnt) if (from[i]&(1LL<<b)) {
				// 	if (dist[a][b] == MOD) {
				// 		dist[a][b] = cost.at(i);
				// 		between[a][b] = i;
				// 	}
				// }
			}
		}
		// dbg("HA2");
		V<pair<pi,int>> tmp;
		F0R(i,cnt) F0R(j,cnt) 
			if (i != j) if (dist[i][j] != MOD) tmp.pb({{i,j},FACTOR*(dist[i][j]-(rid.at(j) == M+1 ? 0 : cost.at(rid.at(j))))+1});
		// dbg(tmp);
		// dbg("HA3");
		// dbg(tmp);
		vi _path = get_path(cnt,tmp); 
		if (!sz(_path)) return 0;
		vi path;
		F0R(i,sz(_path)) {
			int a = _path[i]; path.pb(rid.at(a));
			if (i+1 < sz(_path)) {
				int b = _path[i+1];
				path.pb(between.at(a).at(b));
			}
		}
		// dbg("GOT PATH",M,M+1,_path,path);
		assert(path.ft == M && path.bk == M+1);
		each(t,path) if (t < M) {
			// dbg("TOGGLE",t,iset.at(t));
			iset.at(t) = iset.at(t)^1;
		}
		return 1;
		// return path;
		// F0R(k,cnt) F0R(i,cnt) F0R(j,cnt) 
		// 	if (dist[i][k] != MOD && dist[k][j] != MOD)
		// 		ckmin(dist[i][j],dist[i][k]+dist[k][j]);
		// if (dist.at(cnt-2).at(cnt-1) == MOD) return {};

		// vi id(M+2,-1);
		// F0R(i,M) {
		// 	if (indep[i]) {

		// 	}
		// }

		// vi v = get_path(tmp_ed); // N^4
		// if (!sz(v)) return 0;
		// each(t,v) if (t < M) iset.at(t) = iset.at(t)^1;
		// return 1;
	}
	int solve(vi included) {
		iset = vb(M);
		Gmat gmat; Cmat cmat;
		each(t,included) {
			gmat.ins(t), cmat.ins(t); iset.at(t) = 1;
		}
		FOR(i,sz(included),N-1) {
			if (!augment()) return MOD;
		}
		int cnt = 0, tot_cost = 0;
		F0R(i,M) {
			cnt += iset[i];
			if (iset[i]) tot_cost += cost.at(i);
		}
		assert(cnt == N-1);
		if (cnt == N-1) return tot_cost;
		return MOD;
	}
};

pair<vi,vi> prelim(vi v) {
	Gmat gmat; Cmat cmat;
	each(t,v) {
		if (!gmat.indep(t) || !cmat.indep(t)) return {{},{}};
		gmat.ins(t), cmat.ins(t);
	}
	map<int,int> m; int cnt = 0;
	vi res;
	F0R(i,K) {
		int cur = gmat.D.get(i);
		if (!m.count(cur)) m[cur] = cnt++;
		res.pb(m[cur]);
	}
	return {res,cmat.cnt};
}

int main() {
	setIO();
	re(N,K); // M = N*(N-1)/2;
	MAX_D.rsz(K); re(MAX_D);
	V<pair<int,pi>> _edges;
	F0R(i,N) {
		FOR(j,i+1,N) {
			ints(w);
			_edges.pb({w,{i,j}});
		}
	}
	sor(_edges);
	DSU DD; DD.init(N);
	each(t,_edges) {
		if (t.s.f < K) {
			edges.pb(t.s);
			cost.pb(t.f);
		} else if (DD.unite(t.s.f,t.s.s)) {
			edges.pb(t.s);
			cost.pb(t.f);
		}
	}
	M = sz(edges);
	vi special;
	F0R(i,M) if (is_special(i)) special.pb(i);
	assert(sz(special) == K*(K-1)/2);
	int ans = MOD;
	map<pair<vi,vi>,pi> bes;
	auto sum_costs = [&](vi v) {
		int sum_cost = 0;
		each(t,v) sum_cost += cost.at(t);
		return sum_cost;
	};
	F0R(i,1<<sz(special)) {
		vi init; F0R(j,sz(special)) if (i&(1<<j)) init.pb(special[j]);
		auto a = prelim(init); if (!sz(a.f)) continue;
		if (!bes.count(a)) bes[a] = {MOD,MOD};
		ckmin(bes[a],mp(sum_costs(init),i));
	}
	dbg(sz(bes));
	each(t,bes) {
		int i = t.s.s;
		vi init; F0R(j,sz(special)) if (i&(1<<j)) init.pb(special[j]);
		MatroidIsect mi;
		ckmin(ans,mi.solve(init));
	}
	ps(ans);
	dbg_time();

}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/