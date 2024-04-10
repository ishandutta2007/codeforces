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
typedef complex<double> cd;

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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 200001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // Source: StackOverflow
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
}

using namespace io;

template<int SZ> struct DSU {
    int par[SZ], sz[SZ], xo[SZ];
    vector<vi> cyc = {{}};
    vector<vi> mod;
    
    DSU() {
        F0R(i,SZ) par[i] = i, sz[i] = 1;
    }
    
    
    void undo() {
        if (sz(mod.back()) == 0) {
            cyc.pop_back();
        } else {
            int a0 = mod.back()[0], a1 = mod.back()[1];
            par[a1] = a1; xo[a1] = 0;
            sz[a0] -= sz[a1];
        }
        mod.pop_back();
    }
    
    pi getPar(int x) {
        int v = 0;
        while (par[x] != x) {
            v ^= xo[x];
            x = par[x];
        }
        return {x,v};
    }
    
    void ad(array<int,3> a) {
        pi a0 = getPar(a[0]), a1 = getPar(a[1]);
        int v = a0.s^a1.s^a[2];
        if (a0.f != a1.f) {
            if (sz[a0.f] < sz[a1.f]) swap(a0,a1);
            par[a1.f] = a0.f; xo[a1.f] = v;
            sz[a0.f] += sz[a1.f];
            mod.pb({a0.f,a1.f});
        } else {
            for (int i: cyc.back()) v = min(v,i^v);
            cyc.pb(cyc.back());
            for (int& i: cyc.back()) i = min(i,i^v);
            if (v) {
                bool done = 0;
                F0R(i,sz(cyc.back())) if (cyc.back()[i] < v) {
                    cyc.back().insert(cyc.back().begin()+i,v);
                    done = 1;
                    break;
                }
                if (!done) cyc.back().pb(v);
            }
            mod.pb({});
        }
    }
    
    int query(int a, int b) {
        int v = getPar(a).s^getPar(b).s;
        for (int i: cyc.back()) v = min(v,v^i);
        return v;
    }
};

DSU<MX> D;

int n,m,q,cur=0,ans[MX];
map<pi,pi> mm;
vi query[MX];
vector<array<int,3>> todo[1<<19];

void ad(array<int,3> ed, int lo, int hi, int I = 1, int L = 0, int R = MX-1) {
    if (R < lo || hi < L) return;
    if (lo <= L && R <= hi) {
        todo[I].pb(ed);
        return;
    }
    int M = (L+R)/2;
    ad(ed,lo,hi,2*I,L,M);
    ad(ed,lo,hi,2*I+1,M+1,R);
}

void finish(int I = 1, int L = 0, int R = MX-1) {
    for (auto a: todo[I]) D.ad(a);
    if (L == R) {
        if (sz(query[L])) ans[L] = D.query(query[L][0],query[L][1]);
    } else {
        int M = (L+R)/2;
        finish(2*I,L,M);
        finish(2*I+1,M+1,R);
    }
    F0R(i,sz(todo[I])) D.undo();
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,m);
    F0R(i,m) {
        int x,y,d; re(x,y,d);
        mm[{x,y}] = {d,0};
    }
    int q; re(q);
    F0R(i,q) {
        int t,x,y; re(t,x,y); 
        if (t == 1) {
            int d; re(d);
            mm[{x,y}] = {d,i};
        } else if (t == 2) {
            array<int,3> ed = {x,y,mm[{x,y}].f};
            ad(ed,mm[{x,y}].s,i);
            mm.erase({x,y});
        } else {
            query[i] = {x,y};
        }
    }
    for (auto a: mm) ad({a.f.f,a.f.s,a.s.f},a.s.s,q-1);
    finish();
    F0R(i,q) if (sz(query[i])) cout << ans[i] << "\n";
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/