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
const int MX = 30001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace io {
    // TYPE ID (StackOverflow)
    
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
    
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest);
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
    
    // OUTPUT 
    
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
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {
        os << vector<T>(all(a)); return os;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {
        os << vector<pair<T1,T2>>(all(a)); return os;
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
}

using namespace io;

int n,k; // tmp[MX];
vi dist[MX]; // ADJ[MX];
vpi adj[MX], ans;

void bad() {
    pr(-1); exit(0);
}



namespace buildTree {
    vi tree;
    bool inTree[MX];
    int shortest[MX], pre[MX], root = -1;
    map<pi,vpi> m;
    bool mode = 0;
    
    int process(pi a) {
        if (!m.count(a)) bad();
        auto x = m[a]; sort(all(x));
        if (x[0].f != 0 || (sz(x) > 1 && x[1].f == 0)) bad();
        int lst = 0;
        FOR(i,1,sz(x)) {
            while (x[lst+1].f < x[i].f) lst ++;
            if (x[lst].f+1 != x[i].f) bad();
            ans.pb({x[lst].s,x[i].s});
        }
        return x[0].s;
    }
    
    void delEdge(int a, int b, int c) {
        adj[a].erase(find(all(adj[a]),mp(b,c)));
        adj[b].erase(find(all(adj[b]),mp(a,c)));
    }
    
    void addTree(int x) {
        inTree[x] = 1; tree.pb(x);
    }
    
    void addEdge(int a, int b, int c) {
        adj[a].pb({b,c}), adj[b].pb({a,c});
    }
    
    void genDist(int x, int y) {
        shortest[x] = y;
        trav(z,adj[x]) if (shortest[z.f] == MOD) {
            pre[z.f] = x;
            genDist(z.f,y+z.s);
        }
    }
    
    bool on(int a, int b, int i) {
        return dist[a][i]+dist[b][i] == dist[a][b];
    }
    
    int common(int a, int b, int c) {
        F0R(i,n) if (on(a,b,i) && on(b,c,i) && on(c,a,i)) return i;
        bad();
    }
    
    void ad(array<int,3> bes, int x) {
        int j = bes[1], d = bes[2];
        trav(t,tree) shortest[t] = MOD;
        genDist(root,0);
        
        while (j != root && shortest[pre[j]] >= d) j = pre[j];
        /*if (x == 58) {
            pr(bes,x,j,shortest[j],pre[j],shortest[pre[j]]);
            exit(0);
        }*/
        if (mode == 0) {
            int t;
            if (shortest[j] > d) {
                if (!sz(dist[bes[1]])) exit(5);
                t = common(root,bes[1],x); 
                /*if (x == 58) {
                    
                    pr("HUH",t,dist[root][t],d);
                    exit(0);
                }*/
                addTree(t);
                delEdge(pre[j],j,dist[root][j]-dist[root][pre[j]]);
                addEdge(pre[j],t,dist[root][t]-shortest[pre[j]]);
                addEdge(t,j,dist[root][j]-dist[root][t]);
            } else t = j;
            
            if (bes[0]) {
                addEdge(t,x,bes[0]);
                addTree(x);
            }
        } else {
            m[{d,j}].pb({bes[0],x});
        }
    }
    
    void addVertex(int x) {
        array<int,3> bes = {MOD,MOD,MOD};
        trav(j,tree) if (sz(dist[j])) {
            int d = dist[root][x]+dist[root][j]-dist[j][x]; if (d&1) bad();
            d /= 2; if (d < 0 || d > dist[root][j] || d > dist[root][x]) bad();
            ckmin(bes,{dist[root][x]-d,j,d});
        }
        ad(bes,x);
    }
    
    void init() {
        setIO(); re(n,k);
        F0R(i,k) {
            vi d(n); re(d);
            int id = -1;
            F0R(j,n) if (d[j] == 0) id = j;
            if (id == -1) bad();
            if (sz(dist[id]) && dist[id] != d) bad();
            dist[id] = d;
        }
        int co = 0;
        F0R(i,n) if (sz(dist[i]) && !inTree[i]) {
            co ++;
            /*if (co == 5) {
                F0R(i,n) if (sz(adj[i])) pr(i,adj[i]);
                pr(i);
                exit(0);
            }*/
            if (sz(tree) == 0) {
                root = i;
                addTree(i);
            } else addVertex(i);
        }
    }
    
    void finish() {
        genDist(root,0);
        trav(x,tree) {
            if (x == root) process({0,x});
            else {
                vi cur; cur.pb(pre[x]);
                FOR(i,shortest[pre[x]]+1,shortest[x]+1) cur.pb(process({i,x}));
                F0R(i,sz(cur)-1) ans.pb({cur[i],cur[i+1]});
            }
        }
    }
}

vi DIST, ADJ[MX];

void dfs2(int a, int b) {
    if (DIST[a] != MOD) return;
    DIST[a] = b;
    for (int i: ADJ[a]) dfs2(i,b+1);
}

int main() {
    buildTree::init();
    buildTree::mode = 1;
    /*F0R(i,n) pr(i,adj[i]);
    exit(0);*/
    F0R(i,n) buildTree::addVertex(i);
    // exit(0);
    buildTree::finish();
    // pr(buildTree::m);
    
    // pr("HI",ans); exit(0);
    trav(x,ans) ADJ[x.f].pb(x.s), ADJ[x.s].pb(x.f);
    F0R(i,n) if (sz(dist[i])) {
        DIST.resz(n);
        F0R(j,n) DIST[j] = MOD;
        dfs2(i,0);
        if (DIST != dist[i]) bad();
    }
    trav(x,ans) pr(x.f+1,x.s+1);
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/