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


struct Edge {
    int v, flow, C, rev, cost;
};

template<int SZ> struct mcf {
    pi pre[SZ];
    ll cost[SZ], num[SZ], SC, SNC;
    ll flo, ans, ccost;
    vector<Edge> adj[SZ];

    void addEdge(int u, int v, int C, int cost) {
        Edge a{v, 0, C, sz(adj[v]), cost};
        Edge b{u, 0, 0, sz(adj[u]), -cost};
        adj[u].pb(a), adj[v].pb(b);
    }

    void reweight() {
    	F0R(i,SZ) for (auto& p: adj[i]) p.cost += cost[i]-cost[p.v];
    }
    
    bool spfa() {
        F0R(i,SZ) cost[i] = MOD, num[i] = 0;
        cost[SC] = 0, num[SC] = MOD;
        priority_queue<pl,vpl,greater<pl>> todo; todo.push({0,SC});

        while (sz(todo)) {
            pl x = todo.top(); todo.pop();
            if (x.f > cost[x.s]) continue;
            for (auto a: adj[x.s]) if (x.f+a.cost < cost[a.v] && a.flow < a.C) {
                pre[a.v] = {x.s,a.rev};
                cost[a.v] = x.f+a.cost;
                num[a.v] = min((ll)a.C-a.flow,num[x.s]);
                todo.push({cost[a.v],a.v});
            }
        }
        
        ccost += cost[SNC];
        return num[SNC] > 0;
    }

    void backtrack() {
        num[SNC] = 1;
        flo += num[SNC], ans += (ll)num[SNC]*ccost;
        for (int x = SNC; x != SC; x = pre[x].f) {
            adj[x][pre[x].s].flow -= num[SNC];
            int t = adj[x][pre[x].s].rev;
            adj[pre[x].f][t].flow += num[SNC];
        }
    }
    
    ll mincostflow(int sc, int snc, int mx) {
        SC = sc, SNC = snc;
        flo = ans = ccost = 0;
        
        //cout << "HI " << sc << " " << snc << "\n";
        ll ret = 0;
        spfa();
        //F0R(i,57) cout << i << " " << cost[i] << "\n";
        while (1) {
            reweight();
            if (spfa()) backtrack();
            if (flo <= mx) ret = min(ret,ans);
            else break;
            //cout << flo << " " << ans << " " << ret << "\n";
        }
        return ret;
    }
};

mcf<7000> M;

int n,k, c[81], a[81];

int hsh(int a, int b) {
    return (n+1)*(a-1)+b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    FOR(i,1,n+1) cin >> a[i];
    FOR(i,1,n+1) cin >> c[i];
    
    FOR(i,1,n+1) {
        M.addEdge(hsh(i,0),hsh(i+1,0),MOD,0);
        FOR(j,1,n+1) {
            if (i == n) M.addEdge(hsh(i,j),hsh(i+1,0),1,a[i] == j ? -MOD : 0);
            else M.addEdge(hsh(i,j),hsh(i+1,j),1,a[i] == j ? -MOD : 0);
            M.addEdge(hsh(i,j),hsh(i,0),1,0);
            M.addEdge(hsh(i,0),hsh(i,j),1,c[j]);
        }
    }
    
    cout << M.mincostflow(hsh(1,0),hsh(n+1,0),k)+(ll)n*MOD;
}

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/