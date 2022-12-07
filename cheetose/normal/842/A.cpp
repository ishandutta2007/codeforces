#include<cstdio>
typedef long long ll;
int main() {
	ll l, r, x, y, k;
	scanf("%I64d%I64d%I64d%I64d%I64d", &l, &r, &x, &y, &k);
	for (ll b = x; b <= y; b++)
	{
		ll a = k*b;
		if (a >= l && a <= r)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}