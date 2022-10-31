#include <cstdio>
#define MOD 1000000007
#define ll long long
int x, ans=1;
ll n;
int qpow(int x, int p) { int ret=1; while(p) { if(p&1) ret=(ll)ret*x%MOD; p>>=1, x=(ll)x*x%MOD; } return ret; }
int main()
{
	scanf("%d%lld", &x, &n);
	for(int i=2; i*i<=x; ++i)
	{
		ll cur=1;
		if(x%i) continue;
		while(x%i==0) x/=i;
		while(cur<=n) if(cur>n/i) break; else cur*=i, ans=(ll)ans*qpow(i, (n/(ll)cur)%(MOD-1))%MOD;
	}
	ll cur=1;
	if(x>1) while(cur<=n) if(cur>n/x) break; else cur*=x, ans=(ll)ans*qpow(x, (n/(ll)cur)%(MOD-1))%MOD;
	printf("%d\n", ans);
	return 0;
}