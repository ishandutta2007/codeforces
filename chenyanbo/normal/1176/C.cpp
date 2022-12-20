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
int f[276+103+115+108],n,g[102],a[700097];
int main()
{
	f[4]=1;f[8]=2;f[15]=3;f[16]=4;f[23]=5;f[42]=6;
	n=read(); g[0]=10000000;
	for(int i=1;i<=n;++i)a[i]=f[read()];//shunxu
	for(int i=1;i<=n;++i){
		if(g[a[i]-1]){--g[a[i]-1];++g[a[i]];
		}
	}
	printf("%d\n",n-g[6]*6);
}