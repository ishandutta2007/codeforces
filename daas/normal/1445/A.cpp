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
int T,n,X,a[51],b[51];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),X=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
			b[i]=read();
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		int flag=0;
		for(int i=1;i<=n;++i)
			if(a[i]+b[n-i+1]>X)
			{
				flag=1;
				break;
			}
		puts(flag?"No":"Yes");
	}
	return 0;
}