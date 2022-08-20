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
const int MX = 501;
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

namespace modOp {
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }
    
    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }
    
    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }
    
    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a); 
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}

using namespace modOp;

int n, sz[MX];
vpi ans;

void prVec(vi s) {
    cout << sz(s) << endl;
    for (int i: s) cout << i << " ";
    cout << endl;
}

int query(vi s, vi t, int v) {
    if (!sz(s) || !sz(t)) return 0;
    prVec(s); prVec(t);
    cout << v << endl;
    int ret; re(ret); return ret;
}

vi lef;

void divi(int x, vi y) {
    if (!sz(y)) return;
    int t = query({1},y,x);
    if (!t) {
        trav(i,y) lef.pb(i);
        return;
    }
    if (sz(y) == 1) {
        ans.pb({x,y[0]});
        return;
    }
    int m = sz(y)/2;
    divi(x,vi(y.begin(),y.begin()+m));
    divi(x,vi(y.begin()+m,y.end()));
}

int main() {
    re(n);
    // you should actually read the stuff at the bottom
    sz[1] = n;
    vi tmp; FOR(i,2,n+1) tmp.pb(i);
    FOR(i,2,n+1) sz[i] = query({1},tmp,i);
    vi v; FOR(i,1,n+1) v.pb(i);
    vi needPar;
    sort(all(v),[](int a, int b) { return sz[a] < sz[b]; });
    trav(i,v) {
        divi(i,needPar); 
        needPar.clear(); swap(needPar,lef);
        needPar.pb(i);
    }
    cout << "ANSWER" << endl;
    trav(a,ans) cout << a.f << " " << a.s << endl;
    
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/