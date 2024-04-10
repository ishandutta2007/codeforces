#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 10007;

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
char ch[205];

int dp[205][205][605];
int od[605], ev[605];
int fra[605];

void mul1(int cur[], int x)
{
	for(int i = 604; i >= 1; i --) cur[i] = (cur[i] + 1LL * (MOD - x) * cur[i - 1]) % MOD;
}
void div1(int cur[], int x)
{
	rep1(i, 604) cur[i] = (cur[i] + 1LL * x * cur[i - 1]) % MOD;
}
void add(int cur[], int from[], int x, int y)
{
	rep(i, 605 - y) cur[i + y] = (cur[i + y] + 1LL * from[i] * x) % MOD;
}

int ccf[405], csp[805];
int solve(int cur[], int d)
{
	if(d < 605) return cur[d];
	
	int deg = 2 * n + 1, pos = 605 - deg;
	d -= pos;
	
	rep(i, deg) ccf[i] = 0;
	ccf[0] = 1;
	for(int i = 29; i >= 0; i --) {
		rep(j, deg * 2) csp[j] = 0;
		rep(j, deg) rep(k, deg) csp[j + k + (d >> i & 1)] = (csp[j + k + (d >> i & 1)] + 1LL * ccf[j] * ccf[k]) % MOD;
		for(int j = deg * 2 - 1; j >= deg; j --) {
			rep1(k, deg) csp[j - k] = (csp[j - k] + 1LL * (MOD - csp[j]) * fra[k]) % MOD;
			csp[j] = 0;
		}
		rep(j, deg) ccf[j] = csp[j];
	}
	
	int ret = 0;
	rep(i, deg) ret = (ret + 1LL * cur[i + pos] * ccf[i]) % MOD;
	return ret;
}

int main()
{
	scanf("%s%d", ch + 1, &m);
	n = strlen(ch + 1);
	m += n;
	
	dp[0][n + 1][0] = 1;
	for(int i = 0; i <= n; i ++) for(int j = n + 1; j - i >= 2; j --)
	if(ch[i + 1] == ch[j - 1]) {
		div1(dp[i][j], 25);
		add(dp[i + 1][j - 1], dp[i][j], 1, 1);
	} else {
		div1(dp[i][j], 24);
		add(dp[i + 1][j], dp[i][j], 1, 1);
		add(dp[i][j - 1], dp[i][j], 1, 1);
	}
	for(int i = 0; i <= n; i ++) for(int j = min(n + 1, i + 2); j >= i; j --)
	if(j - i == 2) add(od, dp[i][j], 1, 0);
	else {
		div1(dp[i][j], 26);
		add(ev, dp[i][j], 1, 0);
		add(od, dp[i][j], 26, 0);
	}
	
	fra[0] = 1;
	rep(i, n) mul1(fra, 24);
	rep(i, n) mul1(fra, 25);
	mul1(fra, 26);
	
	int ans = m % 2 == 0 ? solve(ev, m / 2) : solve(od, (m - 1) / 2);
	printf("%d\n", ans);
	return 0;
}