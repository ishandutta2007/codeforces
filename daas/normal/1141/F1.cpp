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
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int dp[51][51],a[51],n,jump[51][51][2],bja,bjb;
inline void fun(int x,int y)
{
	if(x==0 && y==0)
		return;
	printf("%d %d\n",x,y);
	fun(jump[x][y][0],jump[x][y][1]);
}
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
		a[i]=read()+a[i-1];
	for(register int i=1;i<=n;++i)
		for(register int j=i;j<=n;++j)
		{
			for(register int k=1;k<i;++k)
				for(register int w=k;w<i;++w)
					if(dp[k][w]>dp[i][j] && a[w]-a[k-1]==a[j]-a[i-1])
					{
						dp[i][j]=dp[k][w];
						jump[i][j][0]=k;
						jump[i][j][1]=w;
					}
			++dp[i][j];
			if(dp[i][j]>dp[bja][bjb])
				bja=i,bjb=j;
		}
	printf("%d\n",dp[bja][bjb]);
	fun(bja,bjb);
	return 0;
}