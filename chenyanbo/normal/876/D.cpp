#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

//_
//INT_MAX   RAND_MAX  ///linx

int p,u,n,a[700050];

int main()
{
	n=read(); u=n;
	printf("%d ",1);
	for(int i=1; i<=n; ++i)
	{
		p=read(); a[p]=1; //
		if(p==u)
		{
			--u;
			while(a[u]&&u>0)--u;
		}
		printf("%d\n",i-(n-u)+1);
	}
}