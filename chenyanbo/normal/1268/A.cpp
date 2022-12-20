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
#define N 500003
int n,k,fl,a[N],b[N];

int main()
{
	n=read();k=read();
	for(int i=1;i<=n;++i)a[i]=getchar()-48;
	fl=0;
	for(int i=k+1;i<=n;++i){
		if(a[i]!=a[i-k]){
			fl=i; break;
		}
	}
	printf("%d\n",n);
	if(!fl){
		for(int i=1;i<=n;++i)printf("%d",a[i]);
		return 0;
	}
	if(a[fl]<a[fl-k]){
		for(int i=fl;i<=n;++i)a[i]=a[i-k];
		for(int i=1;i<=n;++i)printf("%d",a[i]);
		return 0;
	}
	++a[k]; fl=k;
	while(a[fl]==10){
		a[fl]=0; ++a[--fl];
	}
	for(int i=k+1;i<=n;++i)a[i]=a[i-k];
	for(int i=1;i<=n;++i)printf("%d",a[i]);
}