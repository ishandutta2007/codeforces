#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int a[200005];
ll sm[200005], mx;
vi G[200005];
bool vis[200005];

void dfs(int u) {
	sm[u] = a[u];
	vis[u] = 1;
	for(int v:G[u])
		if(vis[v] == 0){
			dfs(v);
			sm[u] += sm[v];
		}
}

void dfs(int u, int d) {
	vis[u] = 1;
	mx += 1LL * d * a[u];
	for(int v:G[u])
		if(vis[v] == 0)
			dfs(v, d + 1);
}

void dfs(int u, ll s) {
	vis[u] = 1;
	mx = max(mx, s);
	for(int v:G[u])
		if(vis[v] == 0)
			dfs(v, s + sm[0] - 2 * sm[v]);		
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(0);
	memset(vis, 0, sizeof(vis[0])*n);
	dfs(0, 0);
	memset(vis, 0, sizeof(vis[0])*n);
	dfs(0, mx);
	cout << mx << endl;
}