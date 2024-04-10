#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
struct truck
{
	int v,l,r,c,id;
	friend operator < (truck a,truck b)
	{
		if(a.l+a.r+a.c!=b.l+b.r+b.c)return a.l+a.r+a.c<b.l+b.r+b.c;
		return a.id<b.id;
	}
}t[100010];
int n,dp[300030],from[300030],nxt[100010];
int ans[100010],cnt,mx;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d %d %d %d",&t[i].v,&t[i].c,&t[i].l,&t[i].r),t[i].id=i;
	sort(t+1,t+1+n);
	for(int i=1;i<n;++i)
		assert(t[i].l+t[i].r+t[i].c!=t[i+1].l+t[i+1].r+t[i+1].c||t[i].id<t[i+1].id);
	for(int i=1;i<=300000;++i)
		dp[i]=-0x3f3f3f3f;
	for(int i=1;i<=n;++i)
	{
		int last=i;
		while(i<n&&t[i].l+t[i].r+t[i].c==t[i+1].l+t[i+1].r+t[i+1].c)++i;
		dp[0]=0;from[0]=0;
	//	for(int j=1;j<=3000;++j)
	//		assert(from[j]==0);
		for(int j=last;j<=i;++j)
			if(dp[t[j].l]+t[j].v>dp[t[j].l+t[j].c])
			{
				dp[t[j].l+t[j].c]=dp[t[j].l]+t[j].v;
				from[t[j].l+t[j].c]=j;nxt[j]=from[t[j].l];
			}
		if(mx<dp[t[i].l+t[i].r+t[i].c])
		{
			mx=dp[t[i].l+t[i].r+t[i].c];
			int p=from[t[i].l+t[i].r+t[i].c];cnt=0;
			while(p)ans[++cnt]=t[p].id,p=nxt[p];
		}
		for(int j=last;j<=i;++j)
			from[t[j].l+t[j].c]=0,dp[t[j].l+t[j].c]=-0x3f3f3f3f;
	}
	printf("%d\n",cnt);
	for(int i=cnt;i;--i)
		printf("%d ",ans[i]);
	return 0;
}