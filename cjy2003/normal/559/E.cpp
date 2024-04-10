#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline void upmax(int &x,int y){x<y?x=y:0;}
inline int qmax(int x,int y){return x<y?y:x;}
struct light
{
	int a,l,r;
	friend bool operator < (light a,light b){return a.a<b.a;}
}p[110];
int n,d[310],cnt,dp[110][310][310],ans;
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&p[i].a,&x);
		p[i].l=p[i].a-x,p[i].r=p[i].a+x;
		d[++cnt]=p[i].l,d[++cnt]=p[i].a,d[++cnt]=p[i].r;
	}
	sort(p+1,p+1+n);
	d[++cnt]=0;
	sort(d+1,d+1+cnt);
	cnt=unique(d+1,d+1+cnt)-d-1;
	for(int i=1;i<=n;++i)
	{
		p[i].a=lower_bound(d+1,d+1+cnt,p[i].a)-d;
		p[i].l=lower_bound(d+1,d+1+cnt,p[i].l)-d;
		p[i].r=lower_bound(d+1,d+1+cnt,p[i].r)-d;
	//	printf("%d %d %d\n",p[i].l,p[i].a,p[i].r);
	}
	memset(dp[1],0xc0,sizeof(dp[1]));
	upmax(dp[1][0][p[1].a],d[p[1].a]-d[p[1].l]);
	upmax(dp[1][0][p[1].r],d[p[1].r]-d[p[1].a]);
	for(int j=1;j<p[1].l;++j)upmax(dp[1][j][p[1].a],d[p[1].a]-d[j]);
	for(int j=1;j<p[1].a;++j)upmax(dp[1][j][p[1].r],d[p[1].r]-d[j]);
	for(int i=2;i<=n;++i)
	{
		memset(dp[i],0xc0,sizeof(dp[i]));
		for(int j=1;j<=cnt;++j)
			for(int k=j;k<=cnt;++k)
			{
				upmax(dp[i][j][qmax(p[i].r,k)],dp[i-1][j][k]+qmax(d[p[i].r]-d[k],0));
				if(p[i].l<=j)upmax(dp[i][0][qmax(p[i].a,k)],dp[i-1][j][k]+qmax(d[p[i].a]-d[k],0));
			}
	//	printf("%d\n",dp[i][0][4]);
		for(int k=1;k<=cnt;++k)
		{
			upmax(dp[i][0][qmax(p[i].r,k)],dp[i-1][0][k]+qmax(d[p[i].r]-d[qmax(k,p[i].a)],0));
			for(int j=k;j<p[i].a;++j)upmax(dp[i][j][p[i].r],dp[i-1][0][k]+d[p[i].r]-d[j]);
			upmax(dp[i][0][qmax(p[i].a,k)],dp[i-1][0][k]+qmax(d[p[i].a]-d[qmax(k,p[i].l)],0));
			for(int j=k;j<p[i].l;++j)upmax(dp[i][j][p[i].a],dp[i-1][0][k]+d[p[i].a]-d[j]);
		}
	//	printf("%d\n",dp[i][0][4]);
	//	for(int j=0;j<=cnt;++j)
	//	{
	//		for(int k=0;k<=cnt;++k)printf("%d ",dp[i][j][k]<0?-1:dp[i][j][k]);
	//		printf("\n");
	//	}
	//	printf("\n");
	}
	for(int i=1;i<=cnt;++i)upmax(ans,dp[n][0][i]);
	printf("%d",ans);
	return 0;
}