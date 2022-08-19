#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const int PR = 3;

int n, k, a[200005];
int p[524288];

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

void DFT(int a[], int len, int dir)
{
	int cur = 0;
	rep(i, 1 << len) {
		if(cur < i) swap(a[i], a[cur]);
		for(int j = len - 1; j >= 0; j --) {
			cur ^= 1 << j;
			if(cur >> j & 1) break;
		}
	}
	for(int d = 2; d <= (1 << len); d <<= 1) {
		int cr = power(PR, dir == -1 ? MOD - 1 - (MOD - 1) / d : (MOD - 1) / d);
		for(int i = 0; i < (1 << len); i += d) {
			int clr = 1;
			for(int j = i; j < i + (d >> 1); j ++) {
				int ev = a[j], od = 1LL * a[j + (d >> 1)] * clr % MOD;
				a[j] = (ev + od) % MOD;
				a[j + (d >> 1)] = (ev - od + MOD) % MOD;
				clr = 1LL * clr * cr % MOD;
			}
		}
	} 
	if(dir == -1) {
		int cur = power(2, MOD - 1 - len);
		rep(i, 1 << len) a[i] = 1LL * a[i] * cur % MOD;
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	rep(i, n) scanf("%d", &a[i]);
	int coef = 1, cnt = 0;
	rep(i, n) if(a[i] == a[(i + 1) % n]) coef = 1LL * coef * k % MOD;
	else cnt ++;
	
	rep(i, 524288) {
		int cur = power(PR, (MOD - 1) / 524288 * i);
		p[i] = power((1LL * cur * cur + 1LL * cur * (k - 2) + 1) % MOD, cnt);
	}
	DFT(p, 19, -1);
	int ans = 0;
	for(int i = cnt + 1; i <= cnt * 2; i ++) ans = (ans + p[i]) % MOD;
	ans = 1LL * coef * ans % MOD;
	printf("%d\n", ans);
	return 0;
}