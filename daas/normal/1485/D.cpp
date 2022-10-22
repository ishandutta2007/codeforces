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
int n,m;
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			int v=read();
			if((i+j)%2) printf("720720 ");
			else printf("%d ",720720-v*v*v*v);
		}
		putchar('\n');
	}
	return 0;
}