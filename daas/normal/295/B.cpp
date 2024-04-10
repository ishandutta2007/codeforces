#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
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
int n,dis[501][501],x[501],pd[501];
long long ans[501];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=read();
	for(int i=1;i<=n;++i)
		x[i]=read();
	for(int i=n;i>=1;--i)
	{
		pd[x[i]]=1;
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				dis[j][k]=min(dis[j][k],dis[j][x[i]]+dis[x[i]][k]);
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				if(pd[j] && pd[k])
					ans[i]+=dis[j][k];
	}
	for(int i=1;i<=n;++i)
		printf("%I64d ",ans[i]);
	return 0;
}