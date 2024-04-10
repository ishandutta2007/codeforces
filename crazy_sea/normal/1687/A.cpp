#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll f(int a,int n)
{
	ll s=0;
	for(int i=0;i<n;i++) s+=(--a);
	return s;
}
const int N=1e6+10;
int n,k,a[N],T;
ll s[N],ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		if(n<=k)
		{
			printf("%lld",s[n]+f(k,n));
		}
		else
		{
			for(int i=k;i<=n;i++)
				ans=max(ans,s[i]-s[i-k]);
			printf("%lld",ans+f(k,k-1));
		}
		printf("\n");ans=0;
	}
}