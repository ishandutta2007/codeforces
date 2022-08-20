#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define rsz resize
#define ins insert 

#define mp make_pair
#define pb push_back
#define eb emplace_back 
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 

const int MOD = 998244353; // = (119<<23)+1
const int MX = 2e5+5;
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 

template<class T> bool ckmin(T& a, const T& b) { 
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; }

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

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
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}

using namespace io;

template<class T> struct modular {
	T val; 
	explicit operator T() const { return val; }
	modular() { val = 0; }
	modular(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	// friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
	friend void pr(const modular& a) { pr(a.val); }
	friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
	friend bool operator==(const modular& a, const modular& b) { 
		return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { 
		return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { 
		return a.val < b.val; }

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	modular& operator-=(const modular& m) { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; }
	modular& operator*=(const modular& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; 
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) { 
		assert(a != 0); return pow(a,MOD-2); 
	}
	modular& operator/=(const modular& m) { 
		return (*this) *= inv(m); }
	
	friend modular operator+(modular a, const modular& b) { 
		return a += b; }
	friend modular operator-(modular a, const modular& b) { 
		return a -= b; }
	friend modular operator*(modular a, const modular& b) { 
		return a *= b; }
	
	friend modular operator/(modular a, const modular& b) { 
		return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int na,nb;
vector<vector<pair<ll,int>>> a, b;

void dfs(vector<pair<ll,int>>& a, ll l, ll r, int d) {
	// 6 7 0
	if (l > r) return;
	if (l%(1LL<<(d+1)) == 0 && r-l+1 == (1LL<<(d+1))) {
		a.pb({l,d+1});
		return;
	}
	/*if (d == -1) {
		ps("HUH",l,r,d); exit(0);
	}*/
	ll m = ((l+(1LL<<d)-1)>>d)<<d;
	if (m == l) {
		if (r >= l+(1LL<<d)) {
			dfs(a,l,l+(1LL<<d)-1,d-1);
			dfs(a,l+(1LL<<d),r,d-1);
			return;
		}
	}
	// ps("OH",l,r,d,m);
	// ps("HA",l,r,d,m);
	if (m > r) {
		dfs(a,l,r,d-1);
		return;
	}
	dfs(a,l,m-1,d-1);
	dfs(a,m,r,d-1);
}

vector<pair<ll,int>> gen(ll l, ll r) {
	vector<pair<ll,int>> v;
	dfs(v,l,r,59);
	// ps("RES",l,r,v);
	return v;
}

vector<pair<ll,int>> zz, ZZ;

void ins(ll l, ll r) {
	/*if (l > r) {
		ps("WUT",l,r);
		exit(0);
	}
	zz.pb({l,1}); zz.pb({r+1,-1});*/
	ZZ.pb({l,1}); ZZ.pb({l+(1LL<<r),-1});
}

void check() {
	trav(B,b) sort(all(B));
	trav(A,a) {
		sort(all(A),[](pair<ll,int> a, pair<ll,int> b) { return a.s > b.s; });
		ZZ.clear();
		trav(B,b) {
			int l = 0; while (l+1 < sz(B) && B[l+1].s > B[l].s) l ++;
			int r = l+1;
			trav(AA,A) {
				while (l >= 0 && B[l].s > AA.s) l --;
				while (r < sz(B) && B[r].s > AA.s) r ++;
				vl v;
				if (l >= 0) {
					v.pb((B[0].f^AA.f)>>AA.s<<AA.s);
					v.pb((B[l].f^AA.f)>>AA.s<<AA.s);
				}
				if (r < sz(B)) {
					v.pb((B[r].f^AA.f)>>AA.s<<AA.s);
					v.pb((B[sz(B)-1].f^AA.f)>>AA.s<<AA.s);
				}
				sort(all(v));
				F0R(i,sz(v)) {
					if (i && v[i] == v[i-1]) continue;
					ins(v[i],AA.s);
				}
			}
		}
		sort(all(ZZ));
		int sum = 0;
		trav(t,ZZ) {
			sum += t.s;
			if (t.s == -1 && sum == 0) zz.pb(t);
			if (t.s == 1 && sum == 1) zz.pb(t);
		}
	}
}

mi i2 = (MOD+1)/2;

mi ari(mi l, mi r) {
	return (r-l+1)*(l+r)*i2;
}

ll ran() { return rand()%(1<<30); }

int main() {
	cin.sync_with_stdio(0); cin.tie(0); 
	srand(9);
	re(na);
	F0R(i,na) {
		ll l,r; 
		/*l = (ran()<<30)+ran();
		r = (ran()<<30)+ran();
		if (l > r) swap(l,r);*/
		re(l,r);
		// ps("HUH",l,r);
		a.pb(gen(l,r));
	}
	// exit(0);
	re(nb);
	F0R(i,nb) {
		ll l,r; 
		/*l = (ran()<<30)+ran();
		r = (ran()<<30)+ran();
		if (l > r) swap(l,r);*/
		re(l,r);
		b.pb(gen(l,r));
	}
	check();
	swap(a,b);
	check();
	sort(all(zz));
	// ps("HA",sz(zz));
	int sum = 0;
	mi ans = 0;
	F0R(i,sz(zz)-1) {
		sum += zz[i].s;
		if (sum) ans += ari(zz[i].f,zz[i+1].f-1);
	}
	ps(ans);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), slow multiset operations
	* do smth instead of nothing and stay organized
*/