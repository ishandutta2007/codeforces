// Problem: C. Keshi Is Throwing a Party
// Contest: Codeforces
// URL: https://codeforces.com/contest/1610/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003],b[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read(),b[i]=read();
		int l=1,r=n,ans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			int cur=0;
			for(int i=1; i<=n; ++i) if(b[i]>=cur&&cur+1+a[i]>=mid) ++cur;
			if(cur>=mid) ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}