#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
int depth[MN];
vector<int> adj[MN];
void dfs (int cur) {
	for (int i : adj[cur]) if (!depth[i]) {
		depth[i] = depth[cur] + 1;
		dfs(i);
	}
}
void solve () {
	int n,m;
	scanf ("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) depth[i] = 0, adj[i].clear();
	while (m--) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	depth[1] = 1;
	dfs(1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (depth[i]&1) ++cnt;
	if (cnt <= n/2) {
		printf ("%d\n",cnt);
		for (int i = 1; i<= n; i++) if (depth[i]&1) printf ("%d ",i);
		printf ("\n");
	} else {
		printf ("%d\n",n-cnt);
		for (int i = 1; i <= n; i++) if (!(depth[i]&1)) printf ("%d ",i);
		printf ("\n");
	}
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve ();
    return 0;
}