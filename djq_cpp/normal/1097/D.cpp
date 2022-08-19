#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

LL n;
int k;

int inv[65]; 
int dp[10005][65][65];
//matrices? not necessary.
void gen_dp()
{
	inv[1] = 1;
	for(int i = 2; i < 60; i ++) inv[i] = MOD - 1LL * inv[MOD % i] * (MOD / i) % MOD;
	
	rep(i, 60) dp[0][i][i] = 1;
	rep1(i, k) rep(j, 60) {
		rep(j0, 60) dp[i][j][j0] = 1LL * dp[i - 1][j][j0] * inv[j0 + 1] % MOD;
		for(int j0 = 59; j0 >= 0; j0 --) dp[i][j][j0] = (dp[i][j][j0] + dp[i][j][j0 + 1]) % MOD; 
	}
}

vector<pair<LL, int> > hv;

int getans(int cur, LL cnum)
{
	if(cur == hv.size()) return cnum % MOD;
	int ret = 0;
	LL cc = 1;
	for(int i = 0; i <= hv[cur].second; i ++) {
		ret = (ret + 1LL * dp[k][hv[cur].second][i] * getans(cur + 1, cnum * cc)) % MOD;
		cc *= hv[cur].first; 
	}
	return ret;
}

int main()
{
	scanf("%I64d%d", &n, &k);
	gen_dp();
	
	for(LL p = 2; p * p <= n; p ++) {
		int tot = 0;
		while(n % p == 0) {
			tot ++;
			n /= p;
		}
		if(tot > 0) hv.push_back(MP(p, tot));
	}
	if(n > 1) hv.push_back(MP(n, 1));
	
	printf("%lld\n", getans(0, 1));
	return 0;
}