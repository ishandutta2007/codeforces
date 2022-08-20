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

bool visit[15];
int n,m,cur,dis=0, dist[1<<15];
int adj[15][15];
vector<vi> edge;

void solve() {
    priority_queue<pii,vector<pii>,greater<pii>> q; 
    dist[cur] = dis;
    q.push({dist[cur],cur});
    
    while (q.size()) {
        auto a = q.top(); q.pop();
        
        if (dist[a.s] < a.f) continue;
        F0R(i,n) F0R(j,n) if (adj[i][j] < MOD) {
            int d1 = a.f+adj[i][j], a1 = a.s^(1<<i)^(1<<j);
            if (d1 < dist[a1]) {
                dist[a1] = d1;
                q.push({d1,a1});
            }
        }
    }
}

void dfs(int x) {
    if (visit[x]) return;
    visit[x] = 1;
    F0R(i,n) if (adj[x][i] < MOD) dfs(i);
}

void test() {
    dfs(0);
    F0R(i,edge.size()) if (!visit[edge[i][0]]) {
        cout << -1;
        exit(0);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,15) F0R(j,15) adj[i][j] = MOD;
	F0R(i,m) {
	    int a,b,w; cin >> a >> b >> w; a--, b--;
	    adj[a][b] = min(adj[a][b],w);
	    adj[b][a] = min(adj[b][a],w);
	    edge.pb({a,b,w});
	    cur ^= 1<<a;
	    cur ^= 1<<b;
	    dis += w;
	}
	test();
	F0R(i,1<<n) dist[i] = MOD;
	solve();
	cout << dist[0];
}

// read!
// ll vs. int!