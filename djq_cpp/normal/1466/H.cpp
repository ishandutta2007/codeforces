#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, perm[45];
bool vis[45];
int cnt[45], val[45], vs;

int ccnt[45];
int ghash()
{
	int ret = 0;
	rep(i, vs) ret = ret * (1 + cnt[i]) + ccnt[i];
	return ret;
}

int fac[45], comb[45][45];
int coef[45][45], dp[2005];
void init_coef()
{
	fac[0] = 1;
	rep1(i, n) fac[i] = 1LL * fac[i - 1] * i % MOD;
	rep(i, n + 1) {
		comb[i][0] = 1;
		rep1(j, i) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
	}
	rep(i, n) {
		int tmp = 0, ccf = 1;
		rep(j, i + 1) tmp = (tmp + 1LL * fac[j] * fac[n - 1 - j] % MOD * comb[i][j]) % MOD;
		rep(k, n + 1) {
			coef[k][i] = ccf;
			ccf = 1LL * ccf * tmp % MOD;
		}
	}
}

bool inc(int tmp[])
{
	rep(i, vs) if(tmp[i] < ccnt[i]) {
		tmp[i] ++;
		return true;
	} else tmp[i] = 0;
	return false;
}
int solve()
{
	int hs = ghash();
	if(dp[hs] != -1) return dp[hs];
	
	int cur = hs == 0, tmp[45] = {};
	while(inc(tmp)) {
		rep(i, vs) ccnt[i] -= tmp[i];
		int ccf = MOD - 1, sum = 0;
		rep(i, vs) sum += val[i] * ccnt[i];
		rep(i, vs) {
			ccf = 1LL * ccf * comb[ccnt[i] + tmp[i]][tmp[i]] % MOD;
			rep(j, tmp[i]) ccf = 1LL * ccf * (MOD - coef[val[i]][sum]) % MOD;
		}
		cur = (cur + 1LL * ccf * solve()) % MOD;
		rep(i, vs) ccnt[i] += tmp[i];
	}
	
	return dp[hs] = cur;
}

int main()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &perm[i]);
	
	rep1(i, n) if(!vis[i]) {
		int len = 0, j = i;
		do {
			vis[j] = true;
			j = perm[j]; len ++;
		} while(j != i);
		cnt[len] ++;
	}
	
	rep1(i, n) if(cnt[i] != 0) {
		cnt[vs] = cnt[i]; val[vs] = i;
		vs ++;
	}
	
	init_coef();
	memset(dp, -1, sizeof(dp));
	rep(i, vs) ccnt[i] = cnt[i];
	printf("%d\n", solve());
	return 0;
}