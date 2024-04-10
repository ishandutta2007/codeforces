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
int n,L,a[51],b[51],c[51];
int main()
{
	n=read(),L=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=n;++i)
		b[i]=read();
	for(int i=0;i<L;++i)
	{
		for(int j=1;j<=n;++j)
			c[j]=(b[j]+i)%L;
		sort(c+1,c+n+1);
		int flag=0;
		for(int j=1;j<=n;++j)
			if(a[j]!=c[j])
			{
				flag=1;
				break;
			}
		if(!flag)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}