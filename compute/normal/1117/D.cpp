#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "the " << #x << " -> "; err(x); } while (0)
void err() { cout << "" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
const int mod=1e9+7;
struct Matrix{
	long long a[100][100];
	void init()
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<100;i++)
			a[i][i]=1;
	}
	Matrix operator*(Matrix b)
	{
		Matrix ret;
		memset(ret.a,0,sizeof(ret.a));
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<100;j++)
			{
				for(int k=0;k<100;k++)
				{
					ret.a[i][j]=(ret.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
				}
			}
		}
		return ret;
	}
};
Matrix quick(Matrix a,long long b)
{
	Matrix ret;
	ret.init();
	while(b)
	{
		if(b&1) ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}
Matrix base;
int main()
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	if(n<m) {puts("1");return 0;}
	memset(base.a,0,sizeof(base.a));
	base.a[0][0]=1;
	base.a[0][m-1]=1;
	for(int i=1;i<m;i++) base.a[i][i-1]=1;
	base=quick(base,n-m+1);
	long long ans=0;
	for(int i=0;i<m;i++) ans=(ans+base.a[0][i])%mod;
	printf("%lld\n",ans);
}