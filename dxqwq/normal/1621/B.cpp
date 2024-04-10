// Problem: B. Integers Shop
// Contest: Hello 2022
// URL: https://codeforces.com/contest/1621/problem/B
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
struct node
{
	int l,r,v;
	// bool operator<(const node&t)const
	// {
		// return r<t.r;
	// }
}a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		a[1].l=read(),a[1].r=read(),a[1].v=read();
		node t=a[1],tt=a[1];
		int ans=a[1].v,d=a[1].r-a[1].l+1;
		printf("%lld\n",ans);
		for(int i=2; i<=n; ++i) 
		{
			a[i].l=read(),a[i].r=read(),a[i].v=read();
			if(a[i].l<t.l||(a[i].l==t.l&&a[i].v<t.v)) t=a[i];
			if(a[i].r>tt.r||(a[i].r==tt.r&&a[i].v<tt.v)) tt=a[i];
			if(tt.r-t.l+1==d)ans=min(ans,tt.v+t.v);
			if(tt.r-t.l+1>d)d=tt.r-t.l+1,ans=tt.v+t.v;
			if(a[i].l==t.l&&a[i].r==tt.r) ans=min(ans,a[i].v);
			printf("%lld\n",ans);
		}
	}
	return 0;
}