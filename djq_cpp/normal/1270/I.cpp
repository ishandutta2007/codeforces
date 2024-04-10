#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef unsigned int uint;
typedef long long LL;
const uint MOD = 998244353;

int k, t;
LL a[515][515], b[515][515];
int x[105], y[105];
int main()
{
	scanf("%d", &k);
	rep(i, 1 << k) rep(j, 1 << k) scanf("%lld", &a[i][j]);
	scanf("%d", &t);
	rep(i, t) scanf("%d%d", &x[i], &y[i]);
	
	rep(i, k) {
		memset(b, 0, sizeof(b));
		int r = (1 << k) - 1;
		rep(j, t) rep(l, 1 << k) rep(m, 1 << k)
		b[(l + (x[j] << i)) & r][(m + (y[j] << i)) & r] ^= a[l][m];
		rep(l, 1 << k) rep(m, 1 << k) a[l][m] = b[l][m];
	}
	
	int ans = 0;
	rep(i, 1 << k) rep(j, 1 << k) ans += a[i][j] != 0;
	printf("%d\n", ans);
	return 0;
}