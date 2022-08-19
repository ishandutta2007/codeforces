#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int INV2 = (MOD + 1) / 2;

int n, k;
vector<int> G[100005];

int dp[100005][205];
int siz[100005];

int tmp[205];
void poly_mul(int dp0[], int sz0, int dp1[], int sz1)
{
	for(int i = 0; i <= min(sz0 + sz1, k); i ++) tmp[i] = 0;
	
	for(int i = 0; i <= min(sz0, k); i ++) for(int j = 0; j <= min(sz1, k); j ++)
	if(i + j <= k) tmp[i + j] = (tmp[i + j] + 1LL * dp0[i] * dp1[j]) % MOD;
	
	for(int i = 0; i <= min(sz0 + sz1, k); i ++) dp0[i] = tmp[i]; 
}

int inv[205];
int fac[205], ifac[205]; 
int S[205][205];
int pw2[100005], ipw2[100005];
void gen_comb()
{
	inv[1] = 1;
	for(int i = 2; i <= k; i ++) inv[i] = MOD - 1LL * inv[MOD % i] * (MOD / i) % MOD;
	fac[0] = ifac[0] = 1;
	rep1(i, k) {
		fac[i] = 1LL * fac[i - 1] * i % MOD;
		ifac[i] = 1LL * ifac[i - 1] * inv[i] % MOD;
	}
	
	pw2[0] = ipw2[0] = 1;
	rep1(i, n) {
		pw2[i] = pw2[i - 1] * 2 % MOD;
		ipw2[i] = 1LL * ipw2[i - 1] * INV2 % MOD;
	}
	
	S[0][0] = 1;
	rep1(i, k) rep1(j, i)
	S[i][j] = (S[i - 1][j - 1] + 1LL * S[i - 1][j] * j) % MOD;
}

int comb(int n, int m)
{
	return fac[n] * (1LL * ifac[m] * ifac[n - m] % MOD) % MOD;
}

void gen_dp(int v, int par)
{
	siz[v] = 0;
	dp[v][0] = 1;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par) continue;
		gen_dp(u, v);
		
		poly_mul(dp[v], siz[v], dp[u], siz[u]);
		siz[v] += siz[u];
	}
	
	siz[v] ++;
	for(int i = min(siz[v], k); i > 0; i --) {
		dp[v][i] = (dp[v][i] + dp[v][i - 1]) % MOD;
		if(i == 1) dp[v][i] = (dp[v][i] - 1LL * dp[v][i - 1] * ipw2[siz[v]] % MOD + MOD) % MOD;
	}
}

int getans(int k)
{
	int ans = 0;
	if(k == 1) {
		rep1(i, n) {
			ans = (ans + pw2[n] + G[i].size() - 1) % MOD;
			rep(j, G[i].size()) {
				int nj = G[i][j];
				if(siz[nj] > siz[i]) ans = (ans - pw2[n - siz[i]] + MOD) % MOD;
				else ans = (ans - pw2[siz[nj]] + MOD) % MOD;
			}
		}
	} else {
		ans = dp[1][k];
		rep1(i, n) rep(j, G[i].size())
		if(siz[G[i][j]] < siz[i]) ans = (ans - 1LL * dp[G[i][j]][k - 1] * ipw2[n - siz[G[i][j]]] % MOD + MOD) % MOD;
		ans = 1LL * pw2[n] * ans % MOD; 
	}
	return ans;
}

int cans[205], pans[205];

int main()
{
	scanf("%d%d", &n, &k);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	gen_comb();
	gen_dp(1, -1);
	
	cans[0] = pw2[n] - 1;
	rep1(i, k) cans[i] = getans(i);
	
	for(int i = 0; i <= k; i ++) for(int j = 0; j <= i; j ++)
	pans[i] = (pans[i] + 1LL * S[i][j] * fac[j] % MOD * cans[j]) % MOD;
	
	int ans = 0;
	for(int i = 0; i <= k; i ++)
	ans = (ans + 1LL * comb(k, i) * pans[i] % MOD * (k - i & 1 ? MOD - 1 : 1)) % MOD;
	printf("%d\n", ans);
	return 0;
}