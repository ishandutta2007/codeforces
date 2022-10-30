#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,tr[2][300005],lim=300000,a[200005],sum[200005];
ll ans[200005];
int lowbit(int p){return p&-p;}
void modify(int p,int md,ll v)
{
	while(p<=lim)
	{
		tr[md][p]+=v;
		p+=lowbit(p);
	}
}
ll ask(int p,int md)
{
	ll ans=0;
	while(p)
	{
		ans+=tr[md][p];
		p-=lowbit(p);
	}
	return ans;
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		modify(lim+1-a[i],0,1);
		for(int j=a[i];j<=lim;j+=a[i])modify(j,1,a[i]);
		ans[i]=ans[i-1];
		ans[i]-=ask(a[i],1);
		for(int j=a[i];j<=lim;j+=a[i])ans[i]-=a[i]*ask(lim+1-j,0);
		ans[i]+=a[i];
	}
	for(int i=1;i<n;i++)printf("%lld ",ans[i]+1ll*i*sum[i]);
	printf("%lld\n",ans[n]+n*sum[n]);
	return 0;
}