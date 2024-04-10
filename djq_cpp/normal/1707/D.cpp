#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, MOD;
vector<int> T[2005];
int dp[2005][2005], pf[2005][2005], sf[2005][2005];

void dfs(int v, int p)
{
	rep(i, T[v].size()) if(T[v][i] == p) {
		T[v].erase(T[v].begin() + i); break;
	}
	int l = T[v].size();
	rep(i, l) dfs(T[v][i], v);
	rep1(i, n) pf[0][i] = sf[l][i] = 1;
	rep(i, l) {
		int u = T[v][i], s = 0;
		rep1(j, n) {
			s = (s + dp[u][j]) % MOD;
			pf[i + 1][j] = 1ULL * pf[i][j] * s % MOD;
		}
	}
	for(int i = l - 1; i >= 0; i --) {
		int u = T[v][i], s = 0;
		rep1(j, n) {
			s = (s + dp[u][j]) % MOD;
			sf[i][j] = 1ULL * sf[i + 1][j] * s % MOD;
		}
	}
	rep1(i, n) dp[v][i] = sf[0][i];
	rep(i, l) {
		int u = T[v][i], s = 0;
		rep1(j, n) {
			dp[v][j] = (dp[v][j] + 1ULL * s * dp[u][j]) % MOD;
			s = (s + 1ULL * pf[i][j] * sf[i + 1][j]) % MOD;
		}
	}
}

int ans[2005], comb[2005][2005];
int main()
{
	scanf("%d%d", &n, &MOD);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		T[u].push_back(v); T[v].push_back(u);
	}
	
	dfs(1, 0);
	comb[0][0] = 1;
	rep1(i, n - 1) {
		comb[i][0] = MOD - comb[i - 1][0];
		rep1(j, n - 1) comb[i][j] = (comb[i - 1][j - 1] - comb[i - 1][j] + MOD) % MOD;
	}
	rep1(i, n - 1) {
		int s = 0;
		rep1(j, i) s = (s + 1ULL * comb[i][j] * sf[0][j]) % MOD;
		printf("%d ", s);
	}
	return 0;
}