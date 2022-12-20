#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int l,r,n,d,x[125],mi;

int main()
{
	n=read();
	d=read();
	for(int i=1; i<=n;++i)x[i]=read();
	sort(x+1,x+n+1);
	mi=120;
	for(int i=1; i<=n; ++i)
	{
		for(int j=n; j>=i; --j)
		{
			if(x[j]-x[i]<=d){
				mi=min(mi,n-(j-i+1)); //O n  n2 //100 1000 ^ 2
			}
		}
	}
	printf("%d\n",mi);
}