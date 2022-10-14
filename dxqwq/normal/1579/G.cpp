// Problem: G. Minimal Coverage
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/G
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
const int d=10001;
int a[10003];
bitset<10003> bs,t;
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int l=0,r=0,ans=0;
		for(int i=1; i<=n; ++i) l=max(l,a[i]);
		r=l*2,ans=r+1;
		while(l<=r)
		{
			t.reset();
			int mid=(l+r)>>1;
			for(int i=0; i<=mid; ++i)
				t[i]=1;
			bs=t;
			for(int i=1; i<=n; ++i)
			{
				bs=((bs<<a[i])|(bs>>a[i]))&t;
				if(bs.none()) break;
			}
			if(bs.any())
				ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}