#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int fac[250005];

int main()
{	
	int n, MOD;
	scanf("%d%d", &n, &MOD);
	
	fac[0] = 1;
	rep1(i, n) fac[i] = 1LL * fac[i - 1] * i % MOD;
	
	int ans = 0;
	rep1(i, n) ans = (ans + 1LL * fac[i] * fac[n - i] % MOD * (n - i + 1) % MOD * (n - i + 1)) % MOD;
	printf("%d\n", ans);
	return 0;
}