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

const int N = 1024;

vi G[N];
int a[N];
bool vis[N];

int dfs(int u) {
	vis[u] = 1;
	int res = 1;
	for(int v:G[u]) {
		if(vis[v] == 0)
			res += dfs(v);
	}
	return res;
}

int main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0;i<k;i++) {
		cin >> a[i];
		a[i]--;
	}
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].PB(v);
		G[v].PB(u);
	}
	int ans = 0, mxnd = 0, ndct = 0;
	for(int i=0;i<k;i++) {
		memset(vis, 0, sizeof(vis[0])*n);
		int nd = dfs(a[i]);
		ndct += nd;
		mxnd = max(mxnd, nd);
		ans += (nd)*(nd-1)/2;
	}
	ans -= (mxnd)*(mxnd-1)/2;
	ans += (mxnd+n-ndct)*(mxnd+n-ndct-1)/2;
	ans -= m;
	cout << ans << endl;
}