#include <cstdio>
#include <algorithm>
#define N 1005
int T, n, fac[N], prime[N], top, cnt[12], a[N], ans[N];
void gp(int n)
{
	for(int i=2; i<=n; ++i)
	{
		if(!fac[i]) prime[++top]=i, fac[i]=top;
		for(int j=1; j<=top&&j<=fac[i]&&prime[j]*i<=n; ++j) fac[i*prime[j]]=j;
	}
}
int main()
{
	scanf("%d", &T);
	gp(1000);
	while(T--)
	{
		scanf("%d", &n);
		std::fill(cnt+1, cnt+12, 0);
		std::fill(ans+1, ans+12, 0);
		for(int i=1; i<=n; ++i) scanf("%d", a+i), ++cnt[fac[a[i]]];
		for(int i=1; i<=11; ++i) ans[i]=ans[i-1]+(cnt[i]?1:0);
		printf("%d\n", ans[11]);
		for(int i=1, cur=1; i<=n; ++i) printf("%d ", ans[fac[a[i]]]);
		puts("");
	}
	return 0;
}