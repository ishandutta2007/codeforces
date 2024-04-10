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
#define N 3000004
int a[N],n;
long long A,B;
int main()
{
	n=read();for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i){
		if(i&1){
			A+=a[i]/2;
			B+=(a[i]+1)/2;
		} else {
			B+=a[i]/2;
			A+=(a[i]+1)/2;
		}
	}
	printf("%lld",min(A,B));
}