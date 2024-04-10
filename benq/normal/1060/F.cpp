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

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 51;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    
	// pair
	template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
	    is >> p.f >> p.s;
	    return is;
	}
	template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
	    os << '{' << a.f << ", " << a.s << '}';
	    return os;
	}
	
    // vector
	template<class T> istream& operator>>(istream& is, vector<T>& a) {
	    int sz; is >> sz; a.resize(sz);
	    F0R(i,sz) is >> a[i];
	    return is;
	}
	template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	    os << "{";
	    F0R(i,sz(a)) {
	        if (i) os << ", ";
	        os << a[i];
	    }
	    os << "}";
	    return os;
	}
}

using namespace io;

int n;
vi adj[MX];
ld com[MX][MX], fac[MX];

void comb(vd& a, vd b) {
    vd c(sz(a)+sz(b)-1);
    F0R(i,sz(a)) F0R(j,sz(b)) c[i+j] += com[i][j]*com[sz(a)-1-i][sz(b)-1-j]*a[i]*b[j];
    a = c;
}

vd addOne(vd tmp) {
    vd res(sz(tmp)+1);
    F0R(j,sz(tmp)) F0R(i,sz(tmp)+1) {
        if (j < i) {
            res[i] += tmp[i-1];
        } else {
            res[i] += 0.5*tmp[j];
        }
    }
    return res;
}

vd gen(int x, int y) {
    // get the number of possibilities which work if there are exactly k edges before parent edge added
    vd tmp = {1};
    for (int i: adj[x]) if (i != y) comb(tmp,gen(i,x));
    tmp = addOne(tmp);
    return tmp;
}

ld solve(int x) {
    ld res = 1;
    for (int i: adj[x]) {
        vd v = gen(i,x);
        res *= v[0]/fac[sz(v)-1];
    }
    return res;
}

int main() {
    F0R(i,MX) com[i][0] = com[0][i] = 1;
    FOR(i,1,MX) FOR(j,1,MX) com[i][j] = com[i-1][j]+com[i][j-1];
    fac[0] = 1;
    FOR(i,1,MX) fac[i] = i*fac[i-1];
    
    setIO(); re(n);
    F0R(i,n-1) {
        int u,v; re(u,v);
        adj[u].pb(v), adj[v].pb(u);
    }
    cout << fixed << setprecision(10);
    //cout << solve(1);
    FOR(i,1,n+1) cout << solve(i) << "\n";
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/