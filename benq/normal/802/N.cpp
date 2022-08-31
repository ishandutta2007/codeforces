// http://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/

#include <bits/stdc++.h>
  
using namespace std;
//using namespace __gnu_pbds;
  
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
  
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
  
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
  
const int MOD = 1000000007;
double PI = 4*atan(1);
const ll INF = 1e18;

struct Edge {
    int v, flow, C, rev, cost;
};

template<int SZ> struct mcf {
    pii pre[SZ];
    ll cost[SZ];
    int SC, SNC;
    vector<Edge> adj[SZ]; 
     
    void addEdge(int u, int v, int C, int cost) {
        Edge a{v, 0, C, (int)adj[v].size(), cost};
        Edge b{u, 0, 0, (int)adj[u].size(), -cost};
        adj[u].pb(a);
        adj[v].pb(b); 
    } 
    
    bool bfs() {
        F0R(i,SZ) cost[i] = INF;
        cost[0] = 0;
        priority_queue<pii,vector<pii>,greater<pii>> todo; todo.push({0,SC}); 
        // doesn't handle negative edges very well
        // no negative cycles
        
        while (todo.size()) {
            pii x = todo.top(); todo.pop();
            if (x.s == SNC) return 1;
            for (auto a: adj[x.s]) if (x.f+a.cost < cost[a.v] && a.flow < a.C) {
                pre[a.v] = {x.s,a.rev};
                cost[a.v] = x.f+a.cost;
                todo.push({cost[a.v],a.v});
            }
        }
        
        return 0;
    }
    
    pii mincostflow(int f, int sc, int snc) {
        SC = sc, SNC = snc;
        
        ll flo = 0, ans = 0;
        F0R(i,f) {
            bfs();
            flo ++, ans += cost[SNC];
            for (int x = SNC; x != SC; x = pre[x].f) {
                adj[x][pre[x].s].flow --;
                int t = adj[x][pre[x].s].rev;
                adj[pre[x].f][t].flow ++;
            }
        }
        
        return {flo,ans};
    }
};

mcf<2202> m;
int n,k;

int main() {
    cin >> n >> k;
    FOR(i,1,n+1) {
        int a; cin >> a;
        m.addEdge(0,i,1,a);
    }
    FOR(i,1,n+1) {
        int b; cin >> b;
        m.addEdge(i,n+1,1,b);
    }
    FOR(i,1,n) m.addEdge(i,i+1,MOD,0);
    
    pii x = m.mincostflow(k,0,n+1);
    cout << x.s;
}