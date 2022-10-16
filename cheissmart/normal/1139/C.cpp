#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 1e9 + 7;

vi G[100005];
int vis[100005];

int pw(int a, int b) {
	if(b == 0)
		return 1;
	int t = pw(a, b/2);
	if(b & 1) return t*t%M*a%M;
	else return t*t%M;
}

int dfs(int u) {
	vis[u] = 1;
	int res = 1;
	for(int v:G[u])
		if(!vis[v])
			res += dfs(v);
	return res;
}

int32_t main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n-1;i++) {
		int u, v, x;
		cin >> u >> v >> x;
		if(x == 0){
			G[u].PB(v);
			G[v].PB(u);
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			ans += pw(dfs(i), k);
			ans %= M;
		}
	}
	ans = (pw(n, k) - ans + M) % M;
	cout << ans << endl;
}