#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,map[4][MAXN],dp[MAXN][10],sum[MAXN];
signed main()
{
	n=read();
	for(int i=1;i<=3;++i)
		for(int j=1;j<=n;++j)
			map[i][j]=read();
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+map[1][i]+map[2][i]+map[3][i];
	memset(dp,-0x3f,sizeof(dp));
	dp[0][1]=0;
	int L1=-0x3f3f3f3f3f3f3f3f,L3=-0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;++i)
	{
		int v1=max(max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3])),L3+sum[i-1]);
		int v2=max(dp[i-1][4],max(dp[i-1][5],dp[i-1][6]));
		int v3=max(max(dp[i-1][7],max(dp[i-1][8],dp[i-1][9])),L1+sum[i-1]);
		L1=max(L1,v1-sum[i-1]);
		L3=max(L3,v3-sum[i-1]);
		dp[i][1]=v1+map[1][i];
		dp[i][2]=v2+map[1][i]+map[2][i];
		dp[i][3]=v3+map[1][i]+map[2][i]+map[3][i];
		dp[i][4]=v2+map[2][i];
		dp[i][5]=v3+map[2][i]+map[3][i];
		dp[i][6]=v1+map[1][i]+map[2][i];
		dp[i][7]=v3+map[3][i];
		dp[i][8]=v2+map[2][i]+map[3][i];
		dp[i][9]=v1+map[1][i]+map[2][i]+map[3][i];
	}
	printf("%lld\n",max(max(L1+sum[n],dp[n][7]),max(dp[n][8],dp[n][9])));
	return 0;
}