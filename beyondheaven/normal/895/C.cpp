#include<bits/stdc++.h>
#define MaxN 100123
typedef long long LL;
const LL Mod=1e9+7;
const int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

inline int idx(int x)
{
	int res=0;
	for(int i=0;i<4;++i)
	while(x%p[i]==0)res^=(1<<i),x/=p[i];
	return res;
}

inline int Get(int x)
{
	#ifdef Dubug
	printf("Get %d = ",x);
	#endif
	
	for(int i=0;i<4;++i)
	while(x%p[i]==0)x/=p[i];
	
	#ifdef Dubug
	printf("%d\n",x);
	#endif
	
	return x;
}

std::vector<int>v[70];
LL ans[70][16];

inline void DP(std::vector<int>&v,LL ans[],int flag)
{
	static LL dp[2][16][2];
	memset(dp,0,sizeof(dp));
	int cur=0;
	dp[cur][0][0]=1;
	
	for(int x:v)
	{
		for(int g=0;g<2;++g)
		for(int i=0;i<16;++i)dp[cur^1][i][g]=dp[cur][i][g];
		int c=idx(x);
		for(int g=0;g<2;++g)
		for(int i=0;i<16;++i)
		dp[cur^1][i^c][g^1]=(dp[cur^1][i^c][g^1]+dp[cur][i][g])%Mod;
		cur^=1;
	}
	
	if(flag)
	for(int i=0;i<16;++i)ans[i]=(dp[cur][i][0]+dp[cur][i][1])%Mod;
	else
	for(int i=0;i<16;++i)ans[i]=dp[cur][i][0];
	
	ans[0]=(ans[0]+Mod-1)%Mod;
}

int main()
{
	int n;scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		v[Get(x)].push_back(x);
	}
	
	std::vector<int>l({1});
	for(const int x:p)
	if(x>7)l.push_back(x);
	
	for(int x:l)DP(v[x],ans[x],(x==1?1:0));
	
	#ifdef Dubug
	for(int x:l)
	for(int i=0;i<16;++i)
	printf("ans[%d][%d]=%lld\n",x,i,ans[x][i]);
	#endif
	
	static LL dp[2][16];
	memset(dp,0,sizeof(dp));
	int cur=0;
	dp[cur][0]=1;
	
	for(int x:l)
	{	
		for(int i=0;i<16;++i)dp[cur^1][i]=dp[cur][i];
		for(int c=0;c<16;++c)
		for(int i=0;i<16;++i)
		dp[cur^1][i^c]=(dp[cur^1][i^c]+dp[cur][i]*ans[x][c])%Mod;
		cur^=1;
	}
	
	printf("%lld\n",(dp[cur][0]+Mod-1)%Mod);
	return 0;
}