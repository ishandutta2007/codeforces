#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int MAXN=200000;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,a[2010],dp[2][MAXN*2+10];
int check()
{
	int cur=0;
	dp[1][MAXN]=1;
	for(int i=1;i<=n;++i,cur^=1)
	{
		memset(dp[cur],0,sizeof(dp[cur]));
		for(int j=0;j<=2*MAXN;++j)
		{
			if(j+a[i]<=2*MAXN) dp[cur][j]|=dp[cur^1][j+a[i]];
			if(j-a[i]>=0) dp[cur][j]|=dp[cur^1][j-a[i]];
		}
	}
	return dp[cur^1][MAXN];
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	while(1)
	{
		int F=0;
		for(int i=1;i<=n;++i) if(a[i]&1) F=1;
		if(F) break;
		for(int i=1;i<=n;++i) a[i]>>=1;
	}
	if(!check()) {puts("0");return 0;}
	puts("1");
	for(int i=1;i<=n;++i) if(a[i]&1) {printf("%d\n",i);return 0;}
	return 0;
}