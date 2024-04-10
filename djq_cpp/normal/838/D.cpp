#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

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

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 1LL * power(n + 1, m - 1) * power(2, m) % MOD * (n + 1 - m) % MOD;
	printf("%d\n", ans);
	return 0;
}