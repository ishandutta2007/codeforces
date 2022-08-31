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

template<int SZ> struct Dinic {
    struct Edge {
        int v;
        ll flow, cap;
        int rev;
    };
 
    vector<Edge> adj[SZ]; 
     
    void addEdge(int u, int v, ll cap) {
        Edge a{v, 0, cap, sz(adj[v])};
        Edge b{u, 0, 0, sz(adj[u])};
        adj[u].pb(a), adj[v].pb(b); 
    } 
     
    int level[SZ], st[SZ];
    
    bool bfs(int s, int t) {
        F0R(i,SZ) level[i] = -1, st[i] = 0;
        level[s] = 0;  
      
        queue<int> q; q.push(s);
        while (sz(q)) {
            int u = q.front(); q.pop();
            for (auto e: adj[u]) 
                if (level[e.v] < 0 && e.flow < e.cap) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
        }
     
        return level[t] >= 0;
    }
      
    ll sendFlow(int s, int t, ll flow) {
        if (s == t) return flow;
      
        for (  ; st[s] < sz(adj[s]); st[s] ++) {
            Edge &e = adj[s][st[s]]; 
                                          
            if (level[e.v] != level[s]+1 || e.flow == e.cap) continue;
            ll temp_flow = sendFlow(e.v, t, min(flow, e.cap - e.flow));

            if (temp_flow > 0) {
                e.flow += temp_flow;
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
      
        return 0;
    }
     
    ll maxFlow(int s, int t) {
        if (s == t) return -1;
        ll total = 0;  
        while (bfs(s, t))  while (ll flow = sendFlow(s, t, INT_MAX)) total += flow;
        return total;
    } 
    
    bool vis[SZ];
    
    void dfs(int x) {
        if (vis[x]) return;
        vis[x] = 1;
        for (auto a: adj[x]) if (a.flow < a.cap) dfs(a.v);
    }
};

Dinic<2002> D;
map<int,vi> X, Y;
map<int,vpi> XX,YY;
vector<pair<pi,pi>> edgex, edgey;
int n;

bool inter(pair<pi,pi> a, pair<pi,pi> b) {
    return b.f.f < a.f.f && a.f.f < b.s.f && a.f.s < b.f.s && b.f.s < a.s.s;
}

int maxIndependent() {
    F0R(i,sz(edgex)) D.addEdge(0,i+1,1);
    F0R(j,sz(edgey)) D.addEdge(j+sz(edgex)+1,sz(edgex)+sz(edgey)+1,1);
    
    F0R(i,sz(edgex)) F0R(j,sz(edgey)) if (inter(edgex[i],edgey[j]))
        D.addEdge(i+1,j+sz(edgex)+1,MOD);
    
    int ans = sz(edgex)+sz(edgey)-D.maxFlow(0,sz(edgex)+sz(edgey)+1);
    
    //cout << ans << "\n";
    D.dfs(0);
    
    set<int> bad;
    F0R(i,2002) for (auto a: D.adj[i]) if (a.flow == a.cap && a.cap == 1)
        if (D.vis[i] && !D.vis[a.v]) {
            bad.insert(i);
            bad.insert(a.v);
        }
    
    F0R(i,sz(edgex)) if (!bad.count(i+1)) {
        //cout << "ZZ " << edgex[i].f.f << "\n";
        XX[edgex[i].f.f].pb({edgex[i].f.s,edgex[i].s.s});
    }
    F0R(i,sz(edgey)) if (!bad.count(i+sz(edgex)+1)) {
        YY[edgey[i].f.s].pb({edgey[i].f.f,edgey[i].s.f});
    }
    return ans;
}

int main() {
    setIO(); re(n);
    F0R(i,n) {
        pi x; re(x);
        X[x.f].pb(x.s);
        Y[x.s].pb(x.f);
    }
    for (auto& a: X) {
        sort(all(a.s));
        F0R(i,sz(a.s)-1) edgex.pb({{a.f,a.s[i]},{a.f,a.s[i+1]}});
    }
    for (auto& a: Y) {
        sort(all(a.s));
        F0R(i,sz(a.s)-1) edgey.pb({{a.s[i],a.f},{a.s[i+1],a.f}});
    }
    maxIndependent();
    vector<vi> hor, ver;
    for (auto a: X) {
        auto v = XX[a.f];
        int ind = 0;
        for (int i = 0; i < sz(a.s); ) {
            int I = i;
            while (ind < sz(v) && v[ind].f == a.s[i]) {
                i++;
                ind ++;
            }
            ver.pb({a.f,a.s[I],a.f,a.s[i]});
            i++;
        }
    }
    for (auto a: Y) {
        auto v = YY[a.f];
        int ind = 0;
        for (int i = 0; i < sz(a.s); ) {
            int I = i;
            while (ind < sz(v) && v[ind].f == a.s[i]) {
                i++;
                ind ++;
            }
            hor.pb({a.s[I],a.f,a.s[i],a.f});
            i++;
        }
    }
    cout << sz(hor) << "\n";
    for (auto a: hor) {
        for (int b: a) cout << b << " ";
        cout << "\n";
    }
    cout << sz(ver) << "\n";
    for (auto a: ver) {
        for (int b: a) cout << b << " ";
        cout << "\n";
    }
    
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/