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
int T,n,map[101][101];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		memset(map,0,sizeof(map));
		for(int i=1;i<=n;++i)
			map[i][i]=map[i][i%n+1]=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				printf("%d ",map[i][j]);
			putchar('\n');
		}
	}
	return 0;
}