#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
const int mod=1e9+7;
inline int MOD(int x){return x+((x>>31)&mod);}
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') x=-1,c=getchar();
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,K;
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1) z=(ll)z*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return z;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		int v=(1<<K)-1;
		printf("%d\n",ksm(n,K));
	}
	return 0;
}