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

template<int SZ> struct centroidDecomp {
    bool done[SZ];
    int sub[SZ], par[SZ], ans[SZ];
    vi dist[SZ], adj[SZ], ANS[SZ];
    pi cen[SZ];
    
    void addEdge(int a, int b) { adj[a].pb(b), adj[b].pb(a); }
    
    void dfs (int no) {
        sub[no] = 1;
        for (int i: adj[no]) if (!done[i] && i != par[no]) {
            par[i] = no;
            dfs(i);
            sub[no] += sub[i];
        }
    }
    
    void genDist(int par, int no) {
        for (int i: adj[no]) if (!done[i] && i != par) {
            cen[i] = cen[no]; 
            dist[i].pb(dist[no].back()+1);
            genDist(no,i);
        }
    }
    
    int getCentroid(int x) {
        par[x] = 0; dfs(x);
        int sz = sub[x];
        while (1) {
            pi mx = {0,0};
            for (int i: adj[x]) if (!done[i] && i != par[x]) mx = max(mx,{sub[i],i});
            if (mx.f*2 > sz) x = mx.s;
            else return x;
        }
    }
    
    void solve (int x, int y = 1) { // call solve(1) to initialize
        x = getCentroid(x); done[x] = 1;
        ans[x] = y;
        for (int i: adj[x]) if (!done[i]) solve(i,y+1);
    }
    
    void upd(int v) {
        pi V = {v,-1};
        for (int ind = sz(dist[v])-1; V.f; V = cen[V.f], ind --) {
            ans[V.f] ++;
            if (V.s != -1) ANS[V.f][V.s] ++;
        }
    }
    
    int query(int v) {
        pi V = {v,-1}; int ret = 0;
        for (int ind = sz(dist[v])-1; V.f; V = cen[V.f], ind --) {
            ret += ans[V.f];
            if (V.s != -1) ret -= ANS[V.f][V.s];
        }
        return ret;
    }
};

centroidDecomp<MX> C;

int n,m;
set<int> adj[MX];
map<pi,pi> M;
set<pi> done;
vector<vi> region;

void addEdge(int a, int b) {
    adj[a].insert(b), adj[b].insert(a);
}

int nex(int i) {
    i = (i+1)%n;
    return i == 0 ? n : i;
}

int pre(int i) {
    i = (i+n-1)%n;
    return i == 0 ? n : i;
}

map<pi,vi> M2;
vector<pair<vi,vpi>> al;

void search(pi a) {
    vpi tmp;
    vi x;
    pi cur = M[a]; tmp.pb(a); done.insert(a);
    while (cur != a) {
        x.pb(cur.f), x.pb(cur.s); 
        tmp.pb(cur); done.insert(cur);
        cur = M[cur]; 
    }
    sort(x.rbegin(),x.rend()); x.erase(unique(all(x)),x.end());
    al.pb({x,tmp});
}

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    FOR(i,1,n+1) addEdge(i,nex(i));
    F0R(i,m) {
        int a,b; cin >> a >> b;
        addEdge(a,b);
    }
    FOR(i,1,n+1) for (int j: adj[i]) if (j != pre(i)) {
        auto it = adj[j].find(i);
        if (it == adj[j].begin()) it = adj[j].end();
        M[{i,j}] = {j,*prev(it)};
    }
    for (auto a: M) if (!done.count(a.f)) search(a.f);
    sort(all(al));
    F0R(i,sz(al)) {
        for (auto b: al[i].s) {
            M2[{min(b.f,b.s),max(b.f,b.s)}].pb(i+1);
        }
    }
    for (auto a: M2) if (sz(a.s) > 1) C.addEdge(a.s[0],a.s[1]);
}

int main() {
    init();
    C.solve(1);
    FOR(i,1,m+2) cout << C.ans[i] << " ";
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/