// Problem: G. Max Sum Array
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1612/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
int a[2000003],fac[2000003],ifac[2000003];
signed main()
{
	int C=1000000,N=2000000,s=0; 
	for(int T=read(),x;T--;)
		x=read(),++a[C-(x-1)],--a[C+(x+1)];
	for(int i=2; i<=N; ++i) a[i]+=a[i-2];
	fac[0]=ifac[0]=1;
	for(int i=1; i<=N; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int i=0; i<=N; ++i) s+=a[i];
	int ans1=0,ans2=1;
	for(int i=N; i>=0; --i) 
	{
		//(i-C)*((s-1)+(s-2)+...+(s-a[i]))
		int g=s%p*a[i]%p,g2=(a[i]*(a[i]+1)/2)%p;
		ans1=(ans1+(p+i-C)*(g+p-g2)%p)%p;
		ans2=ans2*fac[a[i]]%p,s-=a[i];
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}