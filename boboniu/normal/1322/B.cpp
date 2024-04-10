
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 20, M = 25;
ll pw[80], a[N], b[N], c[N], d[N];
ll x[N];
void init()
{
	pw[0] = 1;
	x[0] = 1;
	for (int i = 1; i <= M + 1; i++)
		pw[i] = pw[i - 1] * 2ll, x[i] = x[i - 1] * 2 + 1ll;
}
int main()
{
	int T, n, cas = 0;
	init();
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), b[i] = a[i];
	for (int k = 0; k <= M; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			c[i] = x[k] & a[i]; //mod
			d[i] = x[k] & b[i];
		}
		sort(c + 1, c + 1 + n);
		sort(d + 1, d + 1 + n);
		int le = n, rg = n;
		int st = n, ed = n;
		int num = 0;
		for (int i = 1; i <= n; i++)
		{
			// 2^i<=x<2^(i+1)
			while (le >= 1 && d[le] + c[i] >= pw[k])
				le--;
			while (rg >= 1 && d[rg] + c[i] >= pw[k + 1])
				rg--;
			//2^i+2^(i+1)<=x<2^(i+2)
			while (st >= 1 && d[st] + c[i] >= pw[k] + pw[k + 1])
				st--;
			while (ed >= 1 && d[ed] + c[i] >= pw[k + 2])
				ed--;
			num += rg - le;
			if (ed >= 1)
				num += ed - st;
		}
		//cout << k << " " << num << endl;
		for (int i = 1; i <= n; i++)
			if ((2 * a[i]) & (1 << k))
				num -= 1;
		num /= 2;
		if (num % 2)
			ans += pw[k];
	}
	printf("%lld\n", ans);
}