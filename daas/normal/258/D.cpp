#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<bitset>
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
int n,m,a[1010];
double dp[1010][1010],ans;
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(a[i]>a[j])
				dp[i][j]=1;
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		if(x>y) swap(x,y);
		dp[x][y]=0.5;
		for(int j=1;j<x;++j) dp[j][x]=dp[j][y]=(dp[j][x]+dp[j][y])/2;
		for(int j=x+1;j<y;++j)
		{
			double px=dp[x][j],py=dp[j][y];
			dp[x][j]=px/2+(1-py)/2;
			dp[j][y]=py/2+(1-px)/2;
		}
		for(int j=y+1;j<=n;++j) dp[x][j]=dp[y][j]=(dp[x][j]+dp[y][j])/2;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			ans+=dp[i][j];
	printf("%.9lf\n",ans);
	return 0;
}
//ore no turn,draw