#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair 
#define f first
#define s second
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

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }
int pct(int x) { return __builtin_popcount(x); } 

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

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = {a,b}; }
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
		// cin.exceptions(cin.failbit); 
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

int n,m,k;
vector<vi> bel[3], abv[3];
vector<vector<vector<bool>>> ok;
vector<vector<deque<int>>> ord[3];

void bad() {
	ps(-1);
	exit(0);
}

void check(vector<vi> a, vector<vi> b) {
	F0R(i,sz(a)) F0R(j,sz(a[0])) {
		if ((a[i][j] == 0) != (b[i][j] == 0)) bad();
	}
}

set<int> col;

bool OK(int ind, int x, int y, int p) {
	if (ind == 0) return ok[p][x][y];
	if (ind == 1) return ok[x][p][y];
	return ok[x][y][p];
}

void deal(int ind, int x, int y, int p) {
	while (sz(ord[ind][x][y]) && !OK(ind,x,y,ord[ind][x][y].bk)) 
		ord[ind][x][y].pop_back();
	while (sz(ord[ind][x][y]) && !OK(ind,x,y,ord[ind][x][y].ft)) 
		ord[ind][x][y].pop_front();
	if (sz(ord[ind][x][y])) {
		if (ord[ind][x][y].ft == p) col.insert(bel[ind][x][y]);
		if (ord[ind][x][y].bk == p) col.insert(abv[ind][x][y]);
	}
}

array<int,3> DEAL(int ind, int x, int y, int p) {
	if (p == ord[ind][x][y].ft) {
		deal(ind,x,y,p);
		if (!sz(ord[ind][x][y])) bad();
		return {x,y,ord[ind][x][y].ft};
	}
	if (p == ord[ind][x][y].bk) {
		deal(ind,x,y,p);
		if (!sz(ord[ind][x][y])) bad();
		return {x,y,ord[ind][x][y].bk};
	}
	return {-1,-1,-1};
}

int main() {
	setIO(); re(n,m,k);
	bel[0] = vector<vi>(m,vi(k)); F0R(b,m) F0R(c,k) re(bel[0][b][c]);
	abv[0] = vector<vi>(m,vi(k)); F0R(b,m) F0R(c,k) re(abv[0][b][c]);
	bel[1] = vector<vi>(n,vi(k)); F0R(b,n) F0R(c,k) re(bel[1][b][c]);
	abv[1] = vector<vi>(n,vi(k)); F0R(b,n) F0R(c,k) re(abv[1][b][c]);
	bel[2] = vector<vi>(n,vi(m)); F0R(b,n) F0R(c,m) re(bel[2][b][c]);
	abv[2] = vector<vi>(n,vi(m)); F0R(b,n) F0R(c,m) re(abv[2][b][c]);
	F0R(i,3) check(bel[i],abv[i]);
	queue<array<int,3>> q;
	ok.assign(n,vector<vector<bool>>(m,vector<bool>(k)));
	ord[0].rsz(m); F0R(i,m) ord[0][i].rsz(k);
	ord[1].rsz(n); F0R(i,n) ord[1][i].rsz(k);
	ord[2].rsz(n); F0R(i,n) ord[2][i].rsz(m);
	F0R(a,n) F0R(b,m) F0R(c,k) {
		if (!bel[0][b][c] || !abv[0][b][c]) continue;
		if (!bel[1][a][c] || !abv[1][a][c]) continue;
		if (!bel[2][a][b] || !abv[2][a][b]) continue;
		ok[a][b][c] = 1;
		q.push({a,b,c});
		ord[0][b][c].pb(a);
		ord[1][a][c].pb(b);
		ord[2][a][b].pb(c);
	}
	array<int,3> ID = {-1,-1,-1};
	while (sz(q)) {
		auto a = q.ft; q.pop(); 
		if (!ok[a[0]][a[1]][a[2]]) continue;
		col.clear();
		deal(0,a[1],a[2],a[0]);
		deal(1,a[0],a[2],a[1]);
		deal(2,a[0],a[1],a[2]);
		if (sz(col) > 1) {
			ok[a[0]][a[1]][a[2]] = 0;
			auto A = DEAL(0,a[1],a[2],a[0]);
			if (A != ID) q.push({A[2],A[0],A[1]});
			auto B = DEAL(1,a[0],a[2],a[1]);
			if (B != ID) q.push({B[0],B[2],B[1]});
			auto C = DEAL(2,a[0],a[1],a[2]);
			if (C != ID) q.push({C[0],C[1],C[2]});
		}
	}
	F0R(x,n) F0R(y,m) F0R(z,k) {
		if (!ok[x][y][z]) pr(0);
		else {
			col.clear();
			array<int,3> a = {x,y,z};
			col.clear();
			deal(0,a[1],a[2],a[0]);
			deal(1,a[0],a[2],a[1]);
			deal(2,a[0],a[1],a[2]);
			assert(sz(col) <= 1);
			if (sz(col)) pr(*begin(col));
			else pr(0);
		}
		pr(' ');
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
*/