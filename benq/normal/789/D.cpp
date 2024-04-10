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

int n, m, visit[1000001];
ll co=0;
vi adj[1000001];
vector<pii> edge;

void dfs(int x) {
    if (visit[x]) return;
    visit[x] = 1;
    for (int i: adj[x]) dfs(i);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,m) {
	    int a,b; cin >> a >> b;
	    if (a == b) co++;
	    else adj[a].pb(b), adj[b].pb(a);
	    edge.pb({a,b});
	}
	dfs(edge[0].f);
	F0R(i,m) if (!visit[edge[i].f]) {
	    cout << 0;
	    return 0;
	}
	
	ll ans = 0;
	FOR(i,1,n+1) {
	    ll t = adj[i].size();
	    ans += t*(t-1)/2;
	}
	ans += co*(co-1)/2;
	ans += co*(m-co);
	cout << ans;
}

// read!
// ll vs. int!