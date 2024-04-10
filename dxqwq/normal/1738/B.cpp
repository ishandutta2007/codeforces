// Problem: B. Prefix Sum Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),k=read();
		for(int i=1; i<=k; ++i) a[i]=read();
		if(k==1){puts("Yes");continue;}
		bool flg=1;
		for(int i=3; i<=k; ++i)
			if(a[i]-a[i-1]<a[i-1]-a[i-2])
			{
				flg=0;
				break;
			}
		if(flg)
		{
			int v=a[2]-a[1];
			if(v*(n-k+1)<a[1]) puts("No");
			else puts("Yes");
		}
		else puts("No");
	}
	return 0;
}