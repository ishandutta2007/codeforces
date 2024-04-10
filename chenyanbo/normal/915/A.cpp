#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int n,k,a[150];

int main()
{
	n=read();k=read();
	for(int  i=1; i<=n; ++i)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=n; i; --i)if(!(k%a[i]))
	{//puts//_  \n///
		printf("%d\n",k/a[i]);
		return 0;//exit 0//
	}
}