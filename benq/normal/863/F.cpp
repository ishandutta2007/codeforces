#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

const int MOD = 1000000007;
const int SZ = 102;
  
struct Edge {
    int v, flow, C, rev, cost;
};
 
pii pre[SZ];
int cost[SZ], SC, SNC;
vector<Edge> adj[SZ]; 
 
void addEdge(int u, int v, int C, int cost) {
    Edge a{v, 0, C, (int)adj[v].size(), cost};
    Edge b{u, 0, 0, (int)adj[u].size(), -cost};
    adj[u].pb(a);
    adj[v].pb(b); 
} 

bool bfs() {
    F0R(i,SZ) cost[i] = MOD;
    cost[0] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> todo; todo.push({0,SC}); 
    // doesn't handle negative edges very well
    // no negative cycles
    
    while (todo.size()) {
        pii x = todo.top(); todo.pop();
        for (auto a: adj[x.s]) if (x.f+a.cost < cost[a.v] && a.flow < a.C) {
            pre[a.v] = {x.s,a.rev};
            cost[a.v] = x.f+a.cost;
            todo.push({cost[a.v],a.v});
        }
    }
    
    return cost[SNC] != MOD;
}

pii mincostflow(int sc, int snc) {
    SC = sc, SNC = snc;
    
    int flo = 0, ans = 0;
    while (bfs()) {
        flo ++, ans += cost[SNC];
        for (int x = SNC; x != SC; x = pre[x].f) {
            adj[x][pre[x].s].flow --;
            int t = adj[x][pre[x].s].rev;
            adj[pre[x].f][t].flow ++;
        }
    }
    
    return {flo,ans};
}

int n,q, lo[51], hi[51];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	FOR(i,1,n+1) lo[i] = 1, hi[i] = n;
	F0R(i,q) {
	    int t,l,r,v; cin >> t >> l >> r >> v;
	    if (t == 1) {
	        FOR(j,l,r+1) lo[j] = max(lo[j],v);
	    } else {
	        FOR(j,l,r+1) hi[j] = min(hi[j],v);
	    }
	}
	FOR(i,1,n+1) if (lo[i] > hi[i]) {
	    cout << -1;
	    return 0;
	}
	FOR(i,1,n+1) addEdge(0,i,1,0);
	FOR(i,1,n+1) FOR(j,lo[i],hi[i]+1) addEdge(i,j+n,1,0);
	FOR(j,n+1,2*n+1) FOR(i,1,n+1) addEdge(j,2*n+1,1,2*i-1);
	pii x = mincostflow(0,2*n+1);
	cout << x.s;
}

// read!
// ll vs. int!