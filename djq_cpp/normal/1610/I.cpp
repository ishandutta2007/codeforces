#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
vector<int> T[300005];
int par[300005], dp[300005], ca[300005];
bool vis[300005];
void dfs0(int v, int p)
{
	par[v] = p;
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == p) continue;
		dfs0(u, v); dp[v] ^= dp[u] + 1;
	}
}

int main()
{
	scanf("%d", &n);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		T[u].push_back(v); T[v].push_back(u);
	}
	dfs0(1, 0);
	
	rep1(i, n) ca[i] = dp[i];
	vis[1] = true;
	
	putchar(dp[1] ? '1' : '2');
	int ans = dp[1];
	for(int i = 2; i <= n; i ++) {
		int j = i, tmp = 0;
		for(; !vis[j]; j = par[j]) {
			ans ^= 1;
			vis[j] = true; ans ^= ca[j];
			ca[par[j]] ^= tmp = dp[j] + 1;
		}
		ans ^= tmp;
		putchar(ans ? '1' : '2');
	}
	putchar('\n');
	return 0;
}