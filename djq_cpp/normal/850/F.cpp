#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, a[2505];
int sa, maxa;
int ret[100005];

int inv(int x)
{
	int ret = 1;
	int t = MOD - 2;
	while(t > 0) {
		if(t & 1) ret = 1LL * ret * x % MOD;
		x = 1LL * x * x % MOD;
		t >>= 1;
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	
	rep(i, n) {
		sa += a[i];
		maxa = max(maxa, a[i]);
	}
	
	int cur = sa - 1;
	rep1(i, maxa) {
		ret[i] = cur;
		cur = (cur + 1LL * (MOD - sa) * inv(sa - i)) % MOD;
	}
	
	rep1(i, maxa) ret[i] = (ret[i] + ret[i - 1]) % MOD;
	
	int ans = 0;
	rep(i, n) ans = (ans + ret[a[i]]) % MOD;
	
	ans = 1LL * (sa - 1) * inv(sa) % MOD * ans % MOD;
	
	printf("%d\n", ans);
	return 0;
}