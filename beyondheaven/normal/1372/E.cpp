#include<bits/stdc++.h>
#define MaxN 123
int n,m;
int lm[MaxN][MaxN],rm[MaxN][MaxN];
int dp[MaxN][MaxN];
inline int cnt(int l,int r,int k)
{
	int res=0;
	for(int i=1;i<=n;++i)
	if(l<=lm[i][k]&&rm[i][k]<=r)++res;
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,k;i<=n;++i)
	{
		scanf("%d",&k);
		for(int j=1,l,r;j<=k;++j)
		{
			scanf("%d%d",&l,&r);
			for(int o=l;o<=r;++o)
			lm[i][o]=l,rm[i][o]=r;
		}
	}
	for(int len=1;len<=m;++len)
	for(int l=1,r=len;r<=m;++l,++r)
	for(int k=l;k<=r;++k)
	{
		int tmp=cnt(l,r,k);
		dp[l][r]=std::max(dp[l][r],dp[l][k-1]+tmp*tmp+dp[k+1][r]);
	}
	printf("%d\n",dp[1][m]);
	return 0;
}