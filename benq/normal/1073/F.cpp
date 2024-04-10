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
const int MX = 200001;

namespace io {
    template<typename Test, template<typename...> class Ref>
    struct is_specialization : std::false_type {};

    template<template<typename...> class Ref, typename... Args>
    struct is_specialization<Ref<Args...>, Ref>: std::true_type {};
    // https://stackoverflow.com/questions/16337610/how-to-know-if-a-type-is-a-specialization-of-stdvector

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
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        os << '{';
        F0R(i,sz(a)) {
            if (i) {
                os << ", ";
                if (is_specialization<T, vector>::value) os << '\n';
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
}

using namespace io;

struct TreeDiameter {
    int n, dist[MX], pre[MX];
    vi adj[MX];

    void addEdge(int a, int b) {
        adj[a].pb(b), adj[b].pb(a);
    }

    void dfs(int cur) {
        for (int i: adj[cur]) if (i != pre[cur]) {
            pre[i] = cur;
            dist[i] = dist[cur]+1;
            dfs(i);
        }
    }

    void genDist(int cur) {
        memset(dist,0,sizeof dist);
        pre[cur] = -1;
        dfs(cur);
    }

    int diameterLength() {
        int cur = 0; FOR(i,1,n+1) if (sz(adj[i]) > 2) cur = i;
        genDist(cur);
        
        int bes = 0; FOR(i,1,n+1) if (dist[i] > dist[bes] && sz(adj[i]) > 2) bes = i;
        genDist(bes); FOR(i,1,n+1) if (dist[i] > dist[bes] && sz(adj[i]) > 2) bes = i;
        return dist[bes];
    }

    vi genCenter() {
        int t = diameterLength();
        int bes = 0; FOR(i,1,n+1) if (dist[i] > dist[bes] && sz(adj[i]) > 2) bes = i;
        
        vi v;
        F0R(i,t+1) {
            v.pb(bes);
            bes = pre[bes];
        }
        return v;
    }
};

TreeDiameter T;

vpi leaf[MX];
int n;

void genLeaf(int x) {
    vi cur = {x};
    while (sz(T.adj[cur.back()]) <= 2) {
        int nex = T.adj[cur.back()][0];
        if (sz(cur) > 1 && nex == cur[sz(cur)-2]) nex = T.adj[cur.back()][1];
        cur.pb(nex);
    }
    leaf[cur.back()].pb({sz(cur)-1,x});
    //cout << cur.back() << " " << x << " " << sz(cur) << "\n";
}

pair<pi,pi> dfs(int a, int b, int dist = 0) { 
    pair<pi,pi> bes = {{-1,-1},{-1,-1}};
    for (int i: T.adj[a]) if (i != b) {
        auto x = dfs(i,a,dist+1);
        bes = max(bes,x);
    }   
    if (sz(leaf[a]) > 1) {
        bes = max(bes,{{dist,leaf[a][0].f+leaf[a][1].f},{leaf[a][0].s,leaf[a][1].s}});
    }
    return bes;
}

int main() {
    setIO(); re(n);
    F0R(i,n-1) {
        int a,b; re(a,b);
        T.addEdge(a,b);
    }
    FOR(i,1,n+1) if (sz(T.adj[i]) == 1) genLeaf(i);
    FOR(i,1,n+1) sort(leaf[i].rbegin(),leaf[i].rend());
    T.n = n;
    vi v = T.genCenter();
   // cout << v;
    if (sz(v) % 2 == 1) {
        int a = v[sz(v)/2];
        vector<pair<pi,pi>> t;
        for (int i: T.adj[a]) t.pb(dfs(i,a,0));
        sort(t.rbegin(),t.rend());
        auto x = t[0], y = t[1];
        pr(x.s.f,y.s.f);
        pr(x.s.s,y.s.s);
    } else {
        int a = v[sz(v)/2-1], b = v[sz(v)/2];
        auto x = dfs(a,b), y = dfs(b,a);
        pr(x.s.f,y.s.f);
        pr(x.s.s,y.s.s);
        // cout << a << " " << b << " " << x << " " << y << "\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/