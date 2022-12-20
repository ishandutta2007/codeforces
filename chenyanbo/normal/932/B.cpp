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
int f[11][1000040],g[1000040],q,l,r,k;  //6 l  //ll
int main()
{
	for(int i=0; i<=9; ++i)g[i]=i;
	for(int i=10; i<=1000000; ++i){
		int p=i,s=1;
		while(p){
			if(p%10)s*=p%10;
			p/=10;
		}
		g[i]=g[s];  //i >s
	}
	for(int i=1; i<=1000000; ++i){
		for(int j=1; j<=9; ++j)f[j][i]=f[j][i-1];
		f[g[i]][i]=f[g[i]][i-1]+1;
	}
	q=read();//while q--
	for(int i=1; i<=q; ++i){
		l=read(); r=read(); k=read();
		printf("%d\n",f[k][r]-f[k][l-1]);
	}
}