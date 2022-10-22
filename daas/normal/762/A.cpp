#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
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
int n,K,z[10000001],top;
signed main()
{
	n=read(),K=read();
	for(int i=1;i<=sqrt(n);++i) if(n%i==0)
	{
		--K;
		if(!K) {printf("%lld\n",i);return 0;}
		if(n/i!=i) z[++top]=n/i;
	}
	if(K<=top) printf("%lld\n",z[top-K+1]);
	else puts("-1");
	return 0;
}