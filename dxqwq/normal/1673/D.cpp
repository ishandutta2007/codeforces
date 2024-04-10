// Problem: D. Lost Arithmetic Progression
// Contest: Codeforces - Codeforces Round #785 (Div. 2)
// URL: https://codeforces.com/contest/1673/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int p=1e9+7;
int chk(int x,int y,int z,int v)
{
	v-=x;
	if(v<0) return -1;
	if(v%y) return -1;
	if(v/y>=z) return -1;
	return v/y;
}
signed main()
{
	for(int T=read();T--;)
	{
		int b=read(),q=read(),y=read();
		int c=read(),r=read(),z=read();
		if(r%q){puts("0");continue;}
		if(-1==chk(b,q,y,c)){puts("0");continue;}
		if(-1==chk(b,q,y,c+r*(z-1))){puts("0");continue;}
		int A=chk(b,q,y,c),B=chk(b,q,y,c+r*(z-1));
		if(chk(b,q,y,c-r)==-1||chk(b,q,y,c+r*z)==-1)
		{puts("-1");continue;}
		int ans=0;
		for(int ii=1; ii*ii<=r; ++ii) if(r%ii==0)
		{
			{
				int i=ii;
				if(i*q/__gcd(i,q)==r){
				ans+=(r/i)*(r/i)%p;ans%=p;}
			}
			if(ii*ii!=r)
			{
				int i=r/ii;
				if(i*q/__gcd(i,q)==r){
				ans+=(r/i)*(r/i)%p;ans%=p;}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}