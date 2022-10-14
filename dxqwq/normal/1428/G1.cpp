// Problem: G2. Lucky Numbers (Hard Version)
// Contest: Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1428/G2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[13],f[1000003];
const int N=1000000;
signed main()
{
	int k=(read()-1)*3;
	for(int i=0; i<=5; ++i) a[i]=read();
	for(int i=0; i<N; ++i)
		for(int j=0,v=i; j<=5; ++j,v/=10)
			if((v%10)%3==0) f[i]+=a[j]*((v%10)/3);
	for(int i=0,t=k,r=3; i<=5; ++i,t=k,r*=10)
	{
		for(int j=1; j<t; t-=j,j<<=1)
			for(int l=N-1; l>=r*j; --l)
				(f[l]<f[l-r*j]+a[i]*j)&&(f[l]=f[l-r*j]+a[i]*j);
		for(int l=N-1; l>=r*t; --l)
			(f[l]<f[l-r*t]+a[i]*t)&&(f[l]=f[l-r*t]+a[i]*t);
	} 
	for(int T=read(); T--;) printf("%lld\n",f[read()]);
	return 0;
}