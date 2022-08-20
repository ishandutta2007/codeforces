#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 
#define mp make_pair
#define f first
#define s second

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi; 
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back() 
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 
const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0}; 

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 
// change null_type for map
#define ook order_of_key
#define fbo find_by_order

void treeExample() {
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).f; assert(it == t.lb(9));
	assert(t.ook(10) == 1); assert(t.ook(11) == 2);
	assert(*t.fbo(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) { 
		re(t); re(ts...); 
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	}
	
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

struct mi {
	typedef decay<decltype(MOD)>::type T;
	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(ll v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
	friend void pr(const mi& a) { pr(a.val); }
	friend ostream& operator<<(ostream& os, const mi& a) { 
		return os << a.val; }
   
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }

	mi& operator*=(const mi& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(!(a == 0)); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

struct DSU {
	vi e; void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x;
		return 1;
	}
};

struct Element {
	pi black, white;
	bool in_indep_set = 0;
	int indep_set_pos;
	Element(pi b, pi w) { black = b, white = w; }
};

vi indep_set;
vector<Element> ground_set;
vector<DSU> D;

int N,M,lim[20][20],LIM[20][20];
str g[20], ans[40];

bool blk(pi a) {
	return (a.f+a.s)%2 == 0;	
}

bool colorful_oracle(int ins) {
	pi p = ground_set[ins].black;
	// ps("COLORFUL",p,LIM[p.f][p.s],lim[p.f][p.s]);
	return LIM[p.f][p.s] < lim[p.f][p.s];
}
bool colorful_oracle(int ins, int rem) {
	return colorful_oracle(ins) || ground_set[rem].black == ground_set[ins].black;
}

int h(pi p) {
	return M*p.f+p.s;
}

bool graph_oracle(int ins) {
	// cout << "OH " << ins << endl;
	D[ins].init(N*M);
	F0R(i,sz(ground_set)) if (!ground_set[i].in_indep_set && i != ins) {
		D[ins].unite(h(ground_set[i].black),h(ground_set[i].white));
	}
	// cout << "HUH " << endl;
	F0R(i,N) F0R(j,M) if (g[i][j] == 'O' && !D[ins].sameSet(0,h({i,j}))) return 0;
	return 1;
}

bool graph_oracle(int ins, int rem) {
	return !D[ins].sameSet(h(ground_set[rem].black),h(ground_set[rem].white));
}

bool augment() {
	F0R(i,N) F0R(j,M) LIM[i][j] = 0;
	trav(t,indep_set) LIM[ground_set[t].black.f][ground_set[t].black.s] ++;
	F0R(i,N) F0R(j,M) assert(LIM[i][j] <= lim[i][j]);
	// cout << "HA " << sz(indep_set) << endl;
	/*F0R(i,N) {
		F0R(j,M) pr(LIM[i][j],' ');
		ps();
	}
	ps("----");*/
	vi par(sz(ground_set),MOD);
	queue<int> q;
	F0R(i,sz(ground_set)) 
		if (!ground_set[i].in_indep_set && colorful_oracle(i)) {
			par[i] = -1; q.push(i);
		}
	// cout << "OOPS" << endl;
	int lst = -1;
	while (sz(q)) {
		int cur = q.ft; q.pop(); assert(0 <= cur && cur < sz(ground_set));
		// cout << "DOING " << cur << endl;
		if (ground_set[cur].in_indep_set) {
			// cout << "A" << endl;
			F0R(to,sz(ground_set)) if (par[to] == MOD && !ground_set[to].in_indep_set) {
				if (!colorful_oracle(to,cur)) continue;
				// ps("WUT",to,ground_)
				par[to] = cur; q.push(to);
			}
		} else {
			// cout << "B" << endl;
			if (graph_oracle(cur)) { lst = cur; break; }
			// cout << "C" << endl;
			trav(to,indep_set) if (par[to] == MOD) {
				if (!graph_oracle(cur,to)) continue;
				par[to] = cur; q.push(to);
			}
		}
	}
	// cout << "NEX" << endl;
	if (lst == -1) return 0;
	do {
		ground_set[lst].in_indep_set ^= 1;
		lst = par[lst];
	} while (lst != -1);
	indep_set.clear();
	F0R(i,sz(ground_set)) if (ground_set[i].in_indep_set) {
		ground_set[i].indep_set_pos = sz(indep_set);
		indep_set.pb(i);
	}
	return 1;
}

void solve() {
	indep_set.clear(); ground_set.clear();
	re(N,M); 
	F0R(i,N) F0R(j,M) lim[i][j] = 0;
	F0R(i,N) re(g[i]);
	F0R(i,N) F0R(j,M-1) if (g[i][j] == 'O' && g[i][j+1] == 'O') {
		pi a = {i,j}, b = {i,j+1};
		if (!blk(a)) swap(a,b);
		lim[a.f][a.s] ++;
		ground_set.pb(Element(a,b));
	}
	F0R(i,N-1) F0R(j,M) if (g[i][j] == 'O' && g[i+1][j] == 'O') {
		pi a = {i,j}, b = {i+1,j};
		if (!blk(a)) swap(a,b);
		lim[a.f][a.s] ++;
		ground_set.pb(Element(a,b));
	}
	int num = 0;
	F0R(i,N) F0R(j,M) if (g[i][j] == 'O') {
		num ++;
		if (blk({i,j}) && i+j) {
			lim[i][j] -= 2;
			if (lim[i][j] < 0) {
				ps("NO");
				return;
			}
		}
	}
	D.rsz(sz(ground_set));
	while (augment());
	// exit(0);
	// F0R(i,N) F0R(j,M) ps(i,j,lim[i][j]);
	// ps("??",sz(indep_set));
	if (sz(indep_set) != sz(ground_set)-(num-1)) {
		ps("NO");
		return;
	}
	ps("YES");
	F0R(i,2*N-1) ans[i] = str(2*M-1,' ');
	F0R(t,sz(ground_set)) if (!ground_set[t].in_indep_set) {
		// ps("??",t);
		ans[ground_set[t].black.f+ground_set[t].white.f][ground_set[t].black.s+ground_set[t].white.s] = 'O';
	}
	F0R(i,N) F0R(j,M) ans[2*i][2*j] = g[i][j];
	F0R(i,2*N-1) ps(ans[i]);
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); 
	int T; re(T);
	F0R(i,T) solve();
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/