#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,m,a[200020],w[200020];
int dp[2][101][51],t,inv[3030],sum1,sum0;
int ans;
int main()
{
	scanf("%d %d",&n,&m);
	inv[1]=1;
	for(int i=2;i<=3000;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]),a[i]?sum1+=w[i]:sum0+=w[i];
	for(int i=1;i<=n;++i)
	{
		memset(dp,0,sizeof(dp));
		dp[0][w[i]][0]=1;
		t=0;
		for(int j=0;j<m;++j)
		{
			t^=1;
			memset(dp[t],0,sizeof(dp[t]));
			if(a[i])
			{
				for(int k=w[i];k<=w[i]+j;++k)
					for(int l=0;l+k-w[i]<=j;++l)
					{
						int res0=sum0-l,res1=sum1+j-l;
						if(res0<0||res1<0)continue;
						add(dp[t][k+1][l],1ll*dp[t^1][k][l]*k%mod*inv[res0+res1]%mod);
						add(dp[t][k][l],1ll*dp[t^1][k][l]*(res1-k)%mod*inv[res0+res1]%mod);
						add(dp[t][k][l+1],1ll*dp[t^1][k][l]*res0%mod*inv[res0+res1]%mod);
					}
			}
			else
			{
				for(int k=w[i];k>=w[i]-j&&k>=0;--k)
					for(int l=w[i]-k;l<=j;++l)
					{
						int res0=sum0-l,res1=sum1+j-l;
						if(res0<0||res1<0)continue;
						if(k)add(dp[t][k-1][l+1],1ll*dp[t^1][k][l]*k%mod*inv[res0+res1]%mod);
						add(dp[t][k][l+1],1ll*dp[t^1][k][l]*(res0-k)%mod*inv[res0+res1]%mod);
						add(dp[t][k][l],1ll*dp[t^1][k][l]*res1%mod*inv[res0+res1]%mod);
					}
			}
		} 
		ans=0;
		if(a[i])
		{
			for(int j=w[i];j<=w[i]+m;++j)
				for(int k=0;k+j-w[i]<=m;++k)
					add(ans,1ll*dp[t][j][k]*j%mod);
		}
		else
		{
			for(int j=w[i];j>=w[i]-m&&j;--j)
				for(int k=0;k<=m;++k)
					add(ans,1ll*dp[t][j][k]*j%mod);
		}
		printf("%d\n",ans);
		
	}
	return 0;
}