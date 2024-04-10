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
const int MX = 100001;

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

ll cross(pi O, pi A, pi B) {
    return (ll)(A.f-O.f)*(B.s-O.s)
            -(ll)(A.s-O.s)*(B.f-O.f);
}

vpi convex_hull(vpi P) {
    sort(all(P)); P.erase(unique(all(P)),P.end());
    int n = sz(P);
    if (n == 1) return P;
    
    vpi bot = {P[0]};
    FOR(i,1,n) {
        while (sz(bot) > 1 && cross(bot[sz(bot)-2], bot.back(), P[i]) <= 0) bot.pop_back();
        bot.pb(P[i]);
    }
    bot.pop_back();
    
    vpi up = {P[n-1]};
    F0Rd(i,n-1) {
        while (sz(up) > 1 && cross(up[sz(up)-2], up.back(), P[i]) <= 0) up.pop_back();
        up.pb(P[i]);
    }
    up.pop_back();
    
    bot.insert(bot.end(),all(up));
    return bot;
}

int N; vpi v;
set<pi> V;

int main() {
    setIO(); re(N); v.resize(N);
    F0R(i,N) {
        re(v[i]);
        V.insert(v[i]);
    }
    v.pb({0,0});
    vpi c = convex_hull(v);
    int ind = 0; while (c[ind] != mp(0,0)) ind ++;
    rotate(c.begin(),c.begin()+ind,c.end());
    for (auto a: c) V.erase(a);
    V.insert({0,0}); c.erase(c.begin());
    vpi tmp;
    for (auto a: V) tmp.pb(a);
    vpi x[2]; x[0] = x[1] = tmp;
    F0R(i,sz(c)) x[i&1].pb(c[i]);
    vpi X[2]; X[0] = convex_hull(x[0]), X[1] = convex_hull(x[1]);
    // cout << sz(X[0]) << " " << sz(X[1])
    F0R(i,2) for (auto a: X[i]) if ((a.f&1) || (a.s&1)) {
        cout << "Ani";
        exit(0);
    }
    cout << "Borna";
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/