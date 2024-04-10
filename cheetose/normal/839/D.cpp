#include<cstdio>
#define MOD 1000000007LL
typedef long long ll;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll cnt[1000001], ans[1000001];
void gg(int x)
{
	for (int i = 1; i*i <= x; i++)
	{
		if (x%i == 0)
		{
			cnt[i]++;
			if (i*i != x)cnt[x / i]++;
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d", &x);
		gg(x);
	}
	for(int i=2;i<=1000000;i++)
	{
		ll c = cnt[i];
		if (c>0)ans[i] = (c*POW(2, c - 1)) % MOD;
	}
	for(int i=1000000;i>=2;i--)
	{
		for(int j=i+i;j<=1000000;j+=i)
			ans[i] = (ans[i] + MOD - ans[j]) % MOD;
	}
	ll ANS = 0;
	for(int i=2;i<=1000000;i++)
	{
		ll t = (i*ans[i]) % MOD;
		ANS = (ANS + t) % MOD;
	}
	printf("%lld", ANS);
}