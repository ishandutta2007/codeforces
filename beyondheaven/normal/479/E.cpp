#include<bits/stdc++.h>
#define MaxN 5123
const int Mod=1e9+7;
int dp[MaxN][MaxN],d[MaxN];
int main()
{
	int n,a,b,k;scanf("%d%d%d%d",&n,&a,&b,&k);
	dp[0][a]=1;
	for(int i=0;i<k;++i)
	{
		memset(d,0,sizeof(d));
		#define Add(l,r,v) (d[(r)+1]=(d[(r)+1]+Mod-(v))%Mod,d[l]=(d[l]+(v))%Mod)
		for(int j=1;j<=n;++j)
		{
			if(j==b)continue;
			int p=labs(j-b);
			Add(std::max(j-p+1,1),std::min(j+p-1,n),dp[i][j]);
		}
		#undef Add
		for(int j=1;j<=n;++j)dp[i+1][j]=(dp[i+1][j-1]+d[j])%Mod;
		for(int j=1;j<=n;++j)dp[i+1][j]=(dp[i+1][j]+Mod-dp[i][j])%Mod;
	}
	
	int ans=0;
	for(int j=1;j<=n;++j)ans=(ans+dp[k][j])%Mod;
	printf("%d\n",ans);
	return 0;
}