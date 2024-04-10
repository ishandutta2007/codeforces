#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define lowbit(k) (k&-k)
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,ans,a[500010],sti[500010],tree[500010],num[500010],cnt,dp[500010];
void xg(int zone,int v)
{
	while(zone<=cnt)
	{
		tree[zone]=min(tree[zone],v);
		zone+=lowbit(zone);
	}
}
int cx(int zone)
{
	int bck=0x3f3f3f3f3f3f3f3f;
	while(zone)
	{
		bck=min(bck,tree[zone]);
		zone-=lowbit(zone);
	}
	return bck;
}
void Clear(int zone)
{
	while(zone<=cnt)
	{
		tree[zone]=0x3f3f3f3f3f3f3f3f;
		zone+=lowbit(zone);
	}
}
int calc(int l,int r,int L,int R)
{
	if(r-l+1>R-L+1)
		return -0x3f3f3f3f3f3f3f3f;
	cnt=0;
	for(int i=l-1;i<=r+1;++i)
		num[++cnt]=a[i]-i;
	sort(num+1,num+cnt+1);
	cnt=unique(num+1,num+cnt+1)-num-1;
	dp[l-1]=0;
	xg(lower_bound(num+1,num+cnt+1,a[l-1]-(l-1))-num,dp[l-1]-(l-1));
	for(int i=l;i<=r+1;++i)
	{
		int id=lower_bound(num+1,num+cnt+1,a[i]-i)-num;
		dp[i]=cx(id)+i-1;
		xg(id,dp[i]-i);
	}
	for(int i=l-1;i<=r+1;++i)
		Clear(lower_bound(num+1,num+cnt+1,a[i]-i)-num);
	return dp[r+1];
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=m;++i)
		sti[i]=read();
	a[0]=-2000000000;
	a[n+1]=2000000000;
	sti[m+1]=n+1;
	memset(tree,0x3f,sizeof(tree));
	for(int i=1;i<=m+1;++i)
	{
		ans+=calc(sti[i-1]+1,sti[i]-1,a[sti[i-1]]+1,a[sti[i]]-1);
		if(a[sti[i-1]]>=a[sti[i]])
			ans=-0x3f3f3f3f3f3f3f3f;
		if(ans<0)
		{
			puts("-1");
			return 0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}