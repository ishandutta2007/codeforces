#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=998244353;
typedef long long ll;
int qpow(int x,int y)  //caution inv(0)  ok
{
	int res=1;
	while (y)
	{
		if (y&1) res=(ll)res*x%Mod;
		x=(ll)x*x%Mod;
		y>>=1;
	}
	return res;
}

int n,K,l;
int dp[4002][2001][2];
int main()
{
	scanf("%d%d%d",&n,&K,&l);
	dp[0][0][0]=1;
	for (int i=0;i<(n<<1|1);i++)
		for (int j=0;j<=n&&j<=i;j++)
			for (int u=0;u<2;u++)
			{
				if (j+1<=n&&i+j+1-u<(n<<1|1)) dp[i+1][j+1][u]=(dp[i+1][j+1][u]+dp[i][j][u])%Mod;
				if (j>=1) dp[i+1][j-1][u]=(dp[i+1][j-1][u]+(ll)dp[i][j][u]*j)%Mod;
				if (!u&&j>=K) dp[i+1][j][1]=(dp[i+1][j][1]+dp[i][j][u])%Mod;
			}
	int ans=(ll)l*dp[n<<1|1][0][1]%Mod*qpow(2,n)%Mod,tmp=1;
	for (int i=n+1;i<=(n<<1|1);i++) tmp=(ll)tmp*i%Mod;
	ans=(ll)ans*qpow(tmp,Mod-2)%Mod;
	printf("%d\n",ans);
	return 0;
}