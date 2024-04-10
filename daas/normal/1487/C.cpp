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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		if(n%2)
		{
			for(int i=1;i<=n;++i)
				for(int j=i+1;j<=n;++j)
				{
					if(j-i<=n/2) printf("1 ");
					else printf("-1 ");
				}
			putchar('\n');
		}
		else
		{
			for(int i=1;i<=n;++i)
				for(int j=i+1;j<=n;++j)
				{
					if(j-i<n/2) printf("1 ");
					else if(j-i==n/2) printf("0 ");
					else printf("-1 ");
				}
			putchar('\n');
		}
	}
	return 0;
}