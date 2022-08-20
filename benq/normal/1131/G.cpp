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
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 10000001;
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
        bool fst = 1; trav(a,x) pr(!fst?", ":"",a), fst = 0; 
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    template<class Arg> void ps(const Arg& first) { pr(first,"\n"); } // print w/ spaces
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); 
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

int n,m,ri[MX];
vpl beg, dom, en;
vpi c[250000];
ll ans[MX];

void init() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,m);
    F0R(i,n) {
        int k; re(k); c[i].resz(k);
        F0R(j,k) re(c[i][j].f);
        F0R(j,k) re(c[i][j].s);
    }
    int q; re(q);
    F0R(i,q) {
        int id, mul; re(id,mul); id --;
        F0R(j,sz(c[id])) dom.pb({c[id][j].f,(ll)mul*c[id][j].s});
    }
    vpl st;
    FORd(i,1,m+1) {
        ll right = i;
        while (sz(st) && st.back().f < i+dom[i-1].f) {
            ckmax(right,st.back().s);
            st.pop_back();
        }
        st.pb({i,ri[i] = right});
    }
}

int main() {
    init(); beg.pb({0,0});
    F0R(i,m) {
        int ind = i+1-dom[i].f; // ind -> i 
        ll ret = INF;
        while (sz(beg) && beg.back().f >= ind) {
            ckmin(ret,beg.back().s);
            beg.pop_back();
        } 
        
        beg.pb({i,ret}); ans[i+1] = ret+dom[i].s;
        ll des = ans[i]+dom[i].s;
        while (sz(en) && en.back().f <= ri[i+1]) {
            ckmin(des,en.back().s); en.pop_back();
        }
        if (sz(en) && des >= en.back().s) {
            
        } else {
            en.push_back({ri[i+1],des});
        }
        // ri[i+1], ans[i]+dom[i].s
        
        while (sz(en)) {
            assert(en.back().f >= i+1);
            ckmin(ans[i+1],en.back().s);
            if (en.back().f == i+1) en.pop_back();
            else break;
        }
        beg.pb({i+1,ans[i+1]}); // drop it left 
        
        // drop this one right 
    }
    ll zz = ans[m];
    while (sz(en)) {
        ckmin(zz,en.back().s);
        en.pop_back();
    }
    ps(zz);

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/