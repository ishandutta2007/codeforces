#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
inline int lowbit(int x){return x&-x;}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,p,minn[101],dp[500001],tree[110],DP[10001][101],a[500001];
inline int MOD(int x){return x+((x>>31)&p);}
void sbsolve()
{
	memset(DP,0x3f,sizeof(DP));
	DP[0][0]=0;
	for(int j=1;j<=K;++j)
	{
		memset(minn,0x3f,sizeof(minn));
		for(int i=j-1;i<=n;++i)
		{
			for(int k=0;k<p;++k) DP[i][j]=min(DP[i][j],minn[k]+MOD(a[i]-k));
			minn[a[i]]=min(minn[a[i]],DP[i][j-1]);
		}
	}
	printf("%d\n",DP[n][K]);
}
void xg(int zone,int v)
{
	while(zone<=p)
	{
		tree[zone]=max(tree[zone],v);
		zone+=lowbit(zone);
	}
}
int cx(int zone)
{
	int bck=0;
	while(zone)
	{
		bck=max(tree[zone],bck);
		zone-=lowbit(zone);
	}
	return bck;
}
int main()
{
	n=read(),K=read(),p=read();
	for(int i=1;i<=n;++i) a[i]=MOD(a[i-1]+read()%p-p);
	if(n<K*p)
	{
		sbsolve();
		return 0;
	}
	int ans=a[n];
	for(int i=1;i<=n;++i) a[i]+=1;
	dp[1]=1;
	xg(a[1],dp[1]);
	for(int i=2;i<=n;++i)
	{
		dp[i]=cx(a[i])+1;
		xg(a[i],dp[i]);
	}
	if(dp[n]>=K) printf("%d\n",ans);
	else printf("%d\n",ans+p);
	return 0;
}