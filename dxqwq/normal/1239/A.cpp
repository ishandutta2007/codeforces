// Problem: CF1239A Ivan the Fool and the Probability Theory
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1239A
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003],b[1000003];
signed main()
{
	int n=read(),m=read();
	a[1]=2;
	for(int i=2; i<=1000000; ++i)
		a[i]=(a[i-1]+b[i-1])%p,
		b[i]=a[i-1];
	printf("%lld\n",(a[n]+b[n]+a[m]+b[m]+p-2)%p);
	/*
	bw
	wb
	
	wb
	bw
	
	bb
	ww
	
	bw
	bw
	
	*/
	return 0;
}