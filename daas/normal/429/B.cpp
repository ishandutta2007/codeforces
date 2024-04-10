#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		x=-1,c=getchar();
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,map[1010][1010],dp[1010][1010][4],ans;
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
			map[i][j]=read();
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
			dp[i][j][0]=max(dp[i-1][j][0],dp[i][j-1][0])+map[i][j];
	for(register int i=n;i>=1;--i)
		for(register int j=1;j<=m;++j)
			dp[i][j][1]=max(dp[i+1][j][1],dp[i][j-1][1])+map[i][j];
	for(register int i=1;i<=n;++i)
		for(register int j=m;j>=1;--j)
			dp[i][j][2]=max(dp[i-1][j][2],dp[i][j+1][2])+map[i][j];
	for(register int i=n;i>=1;--i)
		for(register int j=m;j>=1;--j)
			dp[i][j][3]=max(dp[i+1][j][3],dp[i][j+1][3])+map[i][j];
	for(register int i=2;i<n;++i)
		for(register int j=2;j<m;++j)
			ans=max(ans,max(dp[i-1][j][0]+dp[i+1][j][3]+dp[i][j-1][1]+dp[i][j+1][2],dp[i-1][j][2]+dp[i+1][j][1]+dp[i][j-1][0]+dp[i][j+1][3]));
	printf("%d\n",ans);
	return 0;
}