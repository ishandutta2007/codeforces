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

int n,m;
const int SZ = 10002;
pii edge[5000];

void init() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,m) cin >> edge[i].f >> edge[i].s;
}

struct Edge {
    int v, flow, C, rev;
};
 
int level[SZ], start[SZ];
vector<Edge> adj[SZ]; 
 
void addEdge(int u, int v, int C) {
    Edge a{v, 0, C, (int)adj[v].size()};
    Edge b{u, 0, 0, (int)adj[u].size()};
    adj[u].pb(a);
    adj[v].pb(b); 
} 
 
bool BFS(int s, int t) {
    F0R(i,SZ) level[i] = -1;
    level[s] = 0;  
  
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto e: adj[u]) 
            if (level[e.v] < 0  && e.flow < e.C) {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
    }
 
    return level[t] >= 0;
}
  
int sendFlow(int u, int flow, int t) {
    if (u == t) return flow;
  
    for (  ; start[u] < adj[u].size(); start[u] ++) {
        Edge &e = adj[u][start[u]]; 
                                      
        if (level[e.v] == level[u]+1 && e.flow < e.C) {
            int curr_flow = min(flow, e.C - e.flow);
            int temp_flow = sendFlow(e.v, curr_flow, t);

            if (temp_flow > 0) {
                e.flow += temp_flow;
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }
  
    return 0;
}
 
int DinicMaxflow(int s, int t) {
    if (s == t) return -1;
    int total = 0;  
  
    while (BFS(s, t)) {
        F0R(i,SZ) start[i] = 0;
        while (int flow = sendFlow(s, INT_MAX, t)) total += flow;
    }
 
    return total;
} 

int test(int mid) {
    F0R(i,SZ) adj[i].clear();
    F0R(i,m) {
        addEdge(0,i+n+1,1);
        addEdge(i+n+1,edge[i].f,1);
        addEdge(i+n+1,edge[i].s,1);
    }
    FOR(i,1,n+1) addEdge(i,n+m+1,mid);
    return DinicMaxflow(0,n+m+1);
}

int main() {
	init();
	int lo = 0, hi = 5000;
	while (lo < hi) {
	    int mid = (lo+hi)/2;
	    if (test(mid) == m) hi = mid;
	    else lo = mid+1;
	}
	test(lo);
	cout << lo << "\n";
	FOR(i,n+1,n+m+1) {
	    int x, y;
	    for (auto a: adj[i]) if (a.C > 0) {
	        if (a.flow == 0) y = a.v;
	        else x = a.v;
	    }
	    cout << x << " " << y << "\n";
	}
}

// read!
// ll vs. int!