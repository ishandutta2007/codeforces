#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;
 
typedef double db;
typedef long long ll;
typedef long double ld;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert

const int MOD = 1e9+7; // 998244353 = (119<<23)+1
const ll INF = 1e18;
const int MX = 1e5+5;
const ld PI = 4*atan((ld)1);

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ook order_of_key
#define fbo find_by_order

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
        cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
	a %= b; if (a == 0) return b == 1 ? 0 : -1;
	T x = invGeneral(b,a); 
	return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

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
   
	friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) { 
		auto i = invGeneral(a.val,MOD); assert(i != -1);
		return i;
	} // equivalent to return exp(b,MOD-2) if MOD is prime
	modular& operator/=(const modular& m) { return (*this) *= inv(m); }
	
	friend modular operator+(modular a, const modular& b) { return a += b; }
	friend modular operator-(modular a, const modular& b) { return a -= b; }
	friend modular operator*(modular a, const modular& b) { return a *= b; }
	
	friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int n; ll ans = 0;
set<char> alpha;
char s[MX];
array<int,26> nex[MX], pre[MX];
int NEX[27][MX], PRE[27][MX];
pair<int,ll> bnex[MX][17], bpre[MX][17];
vpi preAlpha[MX], nexAlpha[MX];
pi cur[MX];

void init() {
	setIO(); str tmp; re(tmp); n = sz(tmp);
	F0R(i,n) s[i+1] = tmp[i];
}

int countAlpha(pi cur) {
	int a = 0;
	trav(t,nexAlpha[cur.f]) if (t.f <= cur.s) a ++;
	return a;
}

bool atMost(pi cur, int a) {
	return a >= sz(nexAlpha[cur.f]) || nexAlpha[cur.f][a].f > cur.s;
}

int main() {
	init();
	FOR(i,1,n+1) alpha.insert(s[i]);
	F0R(i,26) {
		pre[1][i] = -MOD;
		nex[n][i] = MOD;
	}
	FOR(i,2,n+2) {
		pre[i] = pre[i-1];
		pre[i][s[i-1]-'a'] = i-1;
	}
	ROF(i,0,n) {
		nex[i] = nex[i+1];
		nex[i][s[i+1]-'a'] = i+1;
	}
	FOR(i,1,n+1) {
		{
			vpi v;
			F0R(j,26) if (pre[i+1][j] != -MOD) v.pb({pre[i+1][j],j});
			sort(rall(v));
			preAlpha[i] = v;
			int r = i;
			FOR(z,1,27) {
				if (z-1 < sz(v)) ckmax(r,min(n,nex[i][v[z-1].s]));
				NEX[z][i] = r;
				// ps("HA",z,i,r);
			}
		}
		{
			vpi v;
			F0R(j,26) if (nex[i-1][j] != MOD) v.pb({nex[i-1][j],j});
			sort(all(v));
			nexAlpha[i] = v;
			int l = i;
			FOR(z,1,27) {
				if (z-1 < sz(v)) ckmin(l,max(pre[i][v[z-1].s],1));
				PRE[z][i] = l;
			}
		}
	}
	FOR(i,1,n+1) cur[i] = {i,i};
	FOR(k,1,sz(alpha)+1) {
		FOR(i,1,n+1) {
			bnex[i][0] = {NEX[k][i],i};
			bpre[i][0] = {PRE[k][i],i};
		}
		FOR(j,1,17) FOR(i,1,n+1) {
			bnex[i][j] = bnex[bnex[i][j-1].f][j-1];
			bnex[i][j].s += bnex[i][j-1].s;
			bpre[i][j] = bpre[bpre[i][j-1].f][j-1];
			bpre[i][j].s += bpre[i][j-1].s;
		}
		FOR(i,1,n+1) if (atMost(cur[i],k)) {
			pi& p = cur[i];
			R0F(j,17) {
				if (atMost({bpre[p.f][j].f,bnex[p.s][j].f},k)) {
					ans += (ll)(n-1)<<j;
					ans -= bnex[p.s][j].s;
					ans += bpre[p.f][j].s;
					p = {bpre[p.f][j].f,bnex[p.s][j].f};
				}
			}
			ans += (ll)(n-1)<<0;
			ans -= bnex[p.s][0].s;
			ans += bpre[p.f][0].s;
			p = {bpre[p.f][0].f,bnex[p.s][0].f};
		}
	}
	ps(ans);
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?), set tle
	* do smth instead of nothing and stay organized
*/