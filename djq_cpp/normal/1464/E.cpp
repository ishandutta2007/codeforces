#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int power(int x, int t)
{
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1LL * ret * x % MOD;
		x = 1LL * x * x % MOD;
		t >>= 1;
	}
	return ret;
}

int n, m;
vector<int> G[100005];
bool vis[100005];
int dp[100005];
int sum[131072];

bool hv[100005];
void dfs(int v)
{
	vis[v] = true;
	rep(i, G[v].size()) if(!vis[G[v][i]]) dfs(G[v][i]);
	
	rep(i, (int)G[v].size() + 1) hv[i] = false;
	rep(i, G[v].size()) hv[dp[G[v][i]]] = true;
	rep(i, (int)G[v].size() + 1) if(!hv[i]) {
		dp[v] = i; break;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	
	rep1(i, n) if(!vis[i]) dfs(i);
	
	rep1(i, n) sum[dp[i]] ++;
	rep(i, 17) rep(j, 131072) if(!(j >> i & 1)) {
		int ev = sum[j], od = sum[j | 1 << i];
		sum[j] = ev + od;
		sum[j | 1 << i] = ev - od;
	}
	
	int ans = 0;
	rep(i, 131072) ans = (ans + power(n + 1 - sum[i], MOD - 2)) % MOD;
	ans = (1 + 1LL * ans * (MOD - power(131072, MOD - 2))) % MOD;
	
	printf("%d\n", ans);
	return 0;
}