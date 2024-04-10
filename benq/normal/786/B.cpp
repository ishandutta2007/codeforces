#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
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
const int MX = 1<<17;
const ll INF = 1e18;

int n,q,s;

vector<pii> adj[5*MX];
ll dist[5*MX];

void dijkstra() {
    F0R(i,5*MX) dist[i] = INF;
    priority_queue<pii,vector<pii>,greater<pii>> todo;
    dist[s] = 0; todo.push({0,s});
    while (todo.size()) {
        pii a = todo.top(); todo.pop();
        if (a.f > dist[a.s]) continue;
        for (pii x: adj[a.s]) if (x.s+a.f < dist[x.f]) {
            dist[x.f] = x.s+a.f;
            todo.push({dist[x.f],x.f});
        }
    }
}

// FIX
void genA() {
    FOR(i,1,2*MX) {
        if (i < MX) {
            adj[i+MX].pb({2*i+MX,0});
            adj[i+MX].pb({2*i+1+MX,0});
        } else adj[i+MX].pb({i-MX,0});
    }
}

// FIX
void genB() {
    FOR(i,1,2*MX) {
        if (i < MX) {
            adj[2*i+3*MX].pb({i+3*MX,0});
            adj[2*i+1+3*MX].pb({i+3*MX,0});
        } else adj[i-MX].pb({i+3*MX,0});
    }
}

// FIX
void processA(int v, int l, int r, int w) {
    r++;
    for (l += MX, r += MX; l != r; l >>= 1, r >>= 1) {
        if (l&1) {
            adj[v].pb({l+MX,w});
            l++;
        }
        if (r&1) {
            r--;
            adj[v].pb({r+MX,w});
        }
    }
}

// FIX
void processB(int v, int l, int r, int w) {
    r++;
    for (l += MX, r += MX; l != r; l >>= 1, r >>= 1) {
        if (l&1) {
            adj[l+3*MX].pb({v,w});
            l++;
        }
        if (r&1) {
            r--;
            adj[r+3*MX].pb({v,w});
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q >> s;
	F0R(i,q) {
	    int t; cin >> t;
	    if (t == 1) {
	        int v,u,w; cin >> v >> u >> w;
	        adj[v].pb({u,w});
	    } else if (t == 2) {
	        int v,l,r,w; cin >> v >> l >> r >> w;
	        processA(v,l,r,w); // v to [l,r]
	    } else {
	        int v,l,r,w; cin >> v >> l >> r >> w;
	        processB(v,l,r,w); // [l,r] to v
	    }
	}
	genA(), genB();
	dijkstra();
	FOR(i,1,n+1) if (dist[i] == INF) cout << "-1 ";
	else cout << dist[i] << " ";
}

// read!
// ll vs. int!