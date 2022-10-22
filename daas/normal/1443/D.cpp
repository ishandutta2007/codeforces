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
int T,n,v[30001];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			v[i]=read();
		int V=v[1],flag=0;
		for(int i=2;i<=n;++i)
		{
			int lim=min(V,V+v[i]-v[i-1]);
			if(lim<0)
			{
				flag=1;
				break;
			}
			V=min(v[i],lim);
		}
		if(flag)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}