#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

vi adj[100000];
int par[100000], depth[100000], n;
double ans = 0;

void dfs(int node) {
	depth[node] = depth[par[node]]+1;
	ans += 1.0/depth[node];
	for (int i: adj[node]) if (i != par[node]) {
		par[i] = node; 
		dfs(i);
	}	
}

int main() {
	cin >> n;
	F0R(i,n-1) {
		int a,b; cin >> a >> b; a--, b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	dfs(0);
	cout << fixed << setprecision(9) << ans;
}