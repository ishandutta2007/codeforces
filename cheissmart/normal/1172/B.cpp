#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 998244353;

int vis[200005], f[200005];
vi G[200005];

int dfs(int u) {
	vis[u] = 1;
	int ans = 1, ct = 1;
	for(int v:G[u]) {
		if(!vis[v]) {
			ct++;
			ans *= dfs(v);
			ans %= M;
		}
	}
	ans *= f[ct];
	ans %= M;
	return ans;
}

int32_t main()
{
	IO_OP;
	
	f[0] = 1;
	for(int i=1;i<200005;i++)
		f[i] = f[i-1] * i % M;
	
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	vis[1] = 1;
	int ans = f[G[1].size()] * n % M;
	for(int v:G[1]) {
		ans *= dfs(v);
		ans %= M;
	}
	cout << ans << endl;
	
}