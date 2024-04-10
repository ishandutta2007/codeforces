// Problem: B. Ela's Fitness and the Luxury Number
// Contest: Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/B
// Memory Limit: 256 MB
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int f(int x)
{
	int d=sqrtl(x);
	int ans=(d-1)*3+1;
	if(d*(d+1)<=x) ++ans;
	if(d*(d+2)<=x) ++ans;
	return ans;
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read()-1,m=read();
		printf("%lld\n",f(m)-f(n));
		//2*2
		//2*3
		//x*(x+2)
		//(x+1)^2-1
	}
	return 0;
}