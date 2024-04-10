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

template<int SZ> struct AhoCorasick {
    int link[SZ], dict[SZ], sz = 1, num = 0;
    vpi ind[SZ];
    int to[SZ][10], nex[SZ][10];
    vi oc[SZ];
    queue<int> q;

    AhoCorasick() {
        memset(link,0,sizeof link);
        memset(dict,0,sizeof dict);
    }

    int add(string s) {
        int v = 0;
        trav(C,s) {
        	int c = C-'0';
            if (!to[v][c]) to[v][c] = sz++;
            v = to[v][c];
        }
        dict[v] = v; ind[v].pb({++num,sz(s)}); return v;
    }

    void pushLinks() {
        link[0] = -1; q.push(0);
        while (sz(q)) {
            int v = q.front(); q.pop();
            F0R(i,10) {
            	if (to[v][i]) nex[v][i] = to[v][i];
            	else if (link[v] != -1) nex[v][i] = nex[link[v]][i];
            }
            F0R(i,10) if (to[v][i]) {
                int c = i; int u = to[v][i], j = link[v];
                while (j != -1 && !to[j][c]) j = link[j];
                if (j != -1) {
                    link[u] = to[j][c];
                    if (!dict[u]) dict[u] = dict[link[u]];
                }
                q.push(u);
            }
            // ps("HUH",v,link[v]);
        }
    }
};

AhoCorasick<100000> A;
string l,r;
int n;
vi cool[2001], dp[2001];

void ad(string a, int b) {
	cool[b].pb(A.add(a));
}

int main() {
    setIO(); re(l,r,n);
    if (sz(l) > sz(r) || (sz(l) == sz(r) && l > r)) {
    	ps(0);
    	F0R(i,n) pr(0);
    	exit(0);
    }
    if (sz(l) < sz(r)) {
    	ad(l,0);
    	F0R(i,sz(l)) {
    		FOR(j,l[i]-'0'+1,10) {
    			ad(l.substr(0,i)+char('0'+j),sz(l)-1-i);
    		}
    	}
    	FOR(i,sz(l)+1,sz(r)) {
    		FOR(j,1,10) {
    			string t; t += char('0'+j);
    			ad(t,i-1);
    		}
    	}
    	F0R(i,sz(r)) {
    		F0R(j,r[i]-'0') {
    			if (i == 0 && j == 0) continue;
    			ad(r.substr(0,i)+char('0'+j),sz(r)-1-i);
    		}
    	}
    	ad(r,0);
    } else {
    	int ind = 0; while (ind < sz(r) && l[ind] == r[ind]) ind ++;
    	if (ind == sz(l)) ad(l,0);
    	else {
    		ad(l,0);
	    	FOR(i,ind+1,sz(l)) {
	    		FOR(j,l[i]-'0'+1,10) {
	    			ad(l.substr(0,i)+char('0'+j),sz(l)-1-i);
	    		}
	    	}
    		FOR(i,l[ind]-'0'+1,r[ind]-'0') ad(l.substr(0,ind)+char('0'+i),sz(l)-1-ind);
	    	FOR(i,ind+1,sz(r)) {
	    		F0R(j,r[i]-'0') {
	    			if (i == 0 && j == 0) continue;
	    			ad(r.substr(0,i)+char('0'+j),sz(r)-1-i);
	    		}
	    	}
	    	ad(r,0);
    	}
    }
    A.pushLinks();
    vi val(A.sz);
    FORd(i,1,n+1) {
    	vi tmp(A.sz);
    	trav(t,cool[n-i]) tmp[t] ++;
    	FOR(j,1,A.sz) tmp[j] += tmp[A.link[j]];
    	F0R(j,sz(tmp)) val[j] += tmp[j];
    	dp[i] = val;
    	if (i < n) {
    		F0R(j,A.sz) {
    			int mx = 0;
    			F0R(k,10) ckmax(mx,dp[i+1][A.nex[j][k]]);
    			dp[i][j] += mx;
    		}
    	}
    }
    int cur = 0;
    string ans;
    F0R(i,n) {
    	int mx = 0;
    	F0R(k,10) ckmax(mx,dp[i+1][A.nex[cur][k]]);
    	if (i == 0) ps(mx);
    	F0R(k,10) if (mx == dp[i+1][A.nex[cur][k]]) {
    		ans += char('0'+k);
    		cur = A.nex[cur][k];
    		break;
    	}
    }
    ps(ans);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/