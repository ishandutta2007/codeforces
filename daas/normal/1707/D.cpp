#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,mod,sum[2010],inv[2010],ans[2010];
inline int MOD(int x) {return x+((x>>31)&mod);}
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1) z=(ll)z*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return z;
}
inline int C(int n,int m) {return (n<0 || m<0 || n<m)?0:(ll)sum[n]*inv[m]%mod*inv[n-m]%mod;}
struct node
{
	int head[2010],tot;
	int to[4010],nextn[4010];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
}Ed;
int dp[2010][2010],pre[2010][2010],suf[2010][2010],za[2010],top;
void fun(int u,int fa)
{
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		fun(v,u);
	}
	top=0;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		za[++top]=v;
	}
	for(int i=1;i<=n;++i) pre[0][i]=suf[top+1][i]=1;
	for(int i=1;i<=top;++i)
		for(int j=1;j<=n;++j)
			pre[i][j]=(ll)pre[i-1][j]*dp[za[i]][j]%mod;
	for(int i=top;i>=1;--i)
		for(int j=1;j<=n;++j)
			suf[i][j]=(ll)suf[i+1][j]*dp[za[i]][j]%mod;
	for(int i=1;i<=n;++i) dp[u][i]=pre[top][i];
	for(int i=1;i<=top;++i)
		for(int j=1,val=0;j<=n;++j)
		{
			dp[u][j]=MOD(dp[u][j]+(ll)MOD(dp[za[i]][j]-dp[za[i]][j-1])*val%mod-mod);
			val=MOD(val+(ll)pre[i-1][j]*suf[i+1][j]%mod-mod);
		}
	for(int i=2;i<=n;++i) dp[u][i]=MOD(dp[u][i]+dp[u][i-1]-mod);
}
int main()
{
	n=read(),mod=read();
	sum[0]=inv[0]=1;
	for(int i=1;i<=n;++i) sum[i]=(ll)sum[i-1]*i%mod;
	inv[n]=ksm(sum[n],mod-2);
	for(int i=n-1;i>=1;--i) inv[i]=(ll)inv[i+1]*(i+1)%mod;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		Ed.ADD(u,v);
		Ed.ADD(v,u);
	}
	fun(1,0);
	for(int i=1;i<n;++i)
	{
		ans[i]=1;
		for(int j=Ed.head[1];j!=0;j=Ed.nextn[j])
		{
			int v=Ed.to[j];
			ans[i]=(ll)ans[i]*dp[v][i]%mod;
		}
		for(int j=1;j<i;++j) ans[i]=MOD(ans[i]-(ll)ans[j]*C(i,j)%mod);
		printf("%d ",ans[i]);
	}
	putchar('\n');
	return 0;
}
//tetu no isi to hagane no tuyosa