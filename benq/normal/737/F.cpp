#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
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
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,a,b;
vi s[3];
vpi v;

void mov(int x, int y) {
	// ps("ZZ",x,y);
	assert(y >= 0);
	if (!y) return;
	v.pb({x,y});
	if (x == 1) {
		if (y > a) {
			ps("NO");
			exit(0);
		}
	} else {
		if (y > b) {
			ps("NO");
			exit(0);
		}
	}
	vi v = vi(s[x].begin(),s[x].begin()+y);
	s[x].erase(s[x].begin(),s[x].begin()+y);
	if (x == 1) s[2].insert(s[2].begin(),all(v));
	else n -= y;
	FOR(i,1,sz(s[2])) if (s[2][i] > s[2][i-1]+1) {
		// ps("??",s[1],s[2]);
		ps("NO");
		exit(0);
	}
}

bool out() {
	int ind = find(all(s[1]),n)-s[1].begin();
	if (ind < sz(s[1])) {
		int cur = ind;
		while (cur && s[1][cur-1]+1 == s[1][cur]) cur --;
		if (cur) return 0;
		F0R(i,ind+1) mov(1,1);
		F0R(i,ind+1) mov(2,1);
		return 1;
	}
	ind = find(all(s[2]),n)-s[2].begin();
	if (ind < sz(s[2])) {
		int cur = ind;
		while (cur && s[2][cur-1]+1 == s[2][cur]) cur --;
		if (cur) return 0;
		mov(2,ind+1);
		return 1;
	}
	exit(5);
}

int main() {
    setIO(); re(n,a,b);
    s[1].rsz(n); re(s[1]); 
    while (n) {
    	if (out()) continue;
    	int ind = 0, mn = s[1][ind], mx = s[1][ind];
    	int maxLen = 0;
    	vi lens = {1};
    	while (ind+1 < sz(s[1]) && s[1][ind+1] <= s[1][ind]+1) {
    		ind ++;
    		ckmin(mn,s[1][ind]);
    		ckmax(mx,s[1][ind]);
    		if (s[1][ind] == mn) lens.pb(0);
    		ckmax(maxLen,++lens.back());
    	}
    	int hole = mx-mn-ind;
    	// ps("HA",seg,hole);
    	if (hole) {
    		mov(1,ind+1);
    		continue;
    	}
    	if (a >= maxLen && b >= ind+1) {
    		trav(t,lens) mov(1,t);
    		continue;
    	}
    	if (b < ind+1) {
    		if (sz(lens) == 1) {
    			F0R(i,ind+1) mov(1,1);
    			continue;
    		} else if (sz(lens) > 2) {
    			mov(1,ind+1);
    			continue;
    		} 
    	} else {
    		if (sz(lens) == 1) {
    			F0R(i,ind+1) mov(1,1);
    			continue;
    		} else if (sz(lens) > 2) {
    			ps("NO"); exit(0);
    		} 
    	}
    	assert(sz(lens) == 2); 
    	// ps("HUH",lens);
    	bool done = 0;
    	FOR(x,1,lens[0]+1) {
    		if (max(x,lens[0]-x+lens[1]) <= a && max(lens[0]-x,lens[1]+x) <= b) {
    			mov(1,x); mov(1,lens[0]-x+lens[1]);
    			done = 1;
    			break;
    		}
    	}
    	if (done) continue;
    	FOR(x,lens[0]+1,lens[0]+lens[1]+1) 
	    	if (max(x,lens[0]+lens[1]-x) <= a && max(x-lens[0],2*lens[0]+lens[1]-x) <= b) {
    			mov(1,x); mov(1,lens[0]-x+lens[1]);
    			done = 1;
    			break; // x-lens[0], 2*lens[0]+lens[1]-x
	    	}
    	if (done) continue;
    	ps("NO"); exit(0);
    	// ps("HUH",ind,s[1],s[2],hole,lens); exit(0);
    }
    ps("YES");
    ps(sz(v));
    trav(t,v) ps(t.f,t.s);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/