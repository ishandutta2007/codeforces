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

map<pi,int> m, key;

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

int n;

vpi v, c;
vi col;
vpi ans;

void addEdge(pi a, pi b) {
    ans.pb({key[a],key[b]});
}

int area(pi a, pi b, pi c) {
    b.f -= a.f, b.s -= a.s;
    c.f -= a.f, c.s -= a.s;
    return abs(b.f*c.s-b.s*c.f);
}

bool in(pi a, pi b, pi c, pi z) {
    return area(a,b,z)+area(b,c,z)+area(c,a,z) == area(a,b,c);
}

void go(pi a, pi b, pi c, vpi res) {
    for (auto t: res) if (m[t] == m[a]) {
        addEdge(a,t);
        vpi x,y,z;
        for (auto T: res) if (T != t) {
            if (in(c,a,t,T)) x.pb(T);
            else if (in(b,a,t,T)) y.pb(T);
            else z.pb(T);
        }
        go(c,a,t,x);
        go(b,a,t,y);
        go(t,b,c,z);
        return;
    }
    for (auto t: res) addEdge(b,t);
}

void solveTri(pi a, pi b, pi c) {
    vpi res;
    for (auto z: v) if (z != a && z != b && z != c && in(a,b,c,z)) res.pb(z);
    go(a,b,c,res);
}

void solveDif() {
    int cur = 0; while (col[cur] == 1) cur ++;
    while (col[cur] == 0) cur = (cur+1)%sz(col);
    while (col[cur] == 1) cur = (cur+1)%sz(col);
    rotate(c.begin(),c.begin()+cur,c.end());
    rotate(col.begin(),col.begin()+cur,col.end());
    
    cur = 0; while (col[cur] == 0) cur ++;
    FOR(i,1,cur) {
        addEdge(c[i],c[i-1]);
        solveTri(c[cur],c[i],c[i-1]);
    }
    /*cout << col << "\n";
    cout << sz(c) << "\n" << cur << "\n";
    
    cout << ans  << "\n";*/
    
    FOR(i,cur+1,sz(col)) {
        addEdge(c[i],c[i-1]);
        solveTri(c[0],c[i],c[i-1]);
    }
}

void solveEq() {
    F0R(i,sz(c)-1) addEdge(c[i],c[i+1]);
    for (auto a: v) if (m[a] != col[0]) {
        F0R(i,sz(c)) solveTri(a,c[i],c[(i+1)%sz(c)]);
        return;
    }
    map<pi,int> bad;
    for (auto a: c) bad[a] = 1;
    for (auto a: v) if (!bad[a]) addEdge(c[0],a);
}

int main() {
    setIO(); re(n);
    
    F0R(i,n) {
        int x,y,c; re(x,y,c);
        m[{x,y}] = c;
        key[{x,y}] = i;
        v.pb({x,y});
    }
    
    c = convex_hull(v);
    for (auto a: c) col.pb(m[a]);
    int dif = 0;
    F0R(i,sz(col)) if (col[i] != col[(i+1)%sz(col)]) dif ++;
    if (dif > 2) {
        cout << "Impossible";
        exit(0);
    }
    bool o = 0;
    for (int i: col) if (i != col[0]) o = 1;
    if (o) solveDif();
    else solveEq();
    cout << sz(ans) << "\n";
    for (auto a: ans) cout << a.f << " " << a.s << "\n";
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/