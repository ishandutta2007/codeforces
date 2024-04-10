// Problem: E1. Abnormal Permutation Pairs (easy version)
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/E1
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int f[1000003],g[1000003];
void init(int x)
{
	int mx=0;
	for(int i=0; i<=x*(x-1)/2; ++i) f[i]=0;
	f[0]=1;
	for(int i=1; i<x; ++i)
	{
		mx+=i;
		for(int j=mx; j>=1; --j)
			for(int k=1; k<=i&&k<=j; ++k)
				f[j]=(f[j]+f[j-k])%p;
	}
	// for(int i=0; i<=mx; ++i) printf("%lld ",f[i]);
	// puts("");
	assert(mx==x*(x-1)/2);
	//total x(x-1)/2
	g[0]=1;

	for(int i=1; i<=mx; ++i) g[i]=(g[i-1]+f[i])%p;

	// for(int i=0; i<=mx; ++i) printf("%lld ",g[i]);
	// puts("");
	return ;
}
int F(int x,int y)
{
	int res=0;
	for(int i=y; i<=x*(x-1)/2; ++i) 
	{
		res=(res+g[i-y]*f[i])%p;
	}
	//printf("? %lld %lld %lld\n",res,x,y);
	return res;
}
int A[100003];
signed main()
{
	int n=read();
	p=read();
	A[0]=1;
	for(int i=n,j=1; j<=n; ++j,--i) A[j]=A[j-1]*i%p;
	if(p==1) puts("0"),exit(0);
	int ans=0;
	for(int i=2; i<=n; ++i)//position i is different
	{
		init(i-1);
		for(int j=1; j<i; ++j)
		ans=(ans+F(i-1,j+1)*(i-j)%p*A[n-i]%p)%p;
		// printf("* %lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
}