// Problem: E. Equilibrium
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int n=read(),m=read();
struct stmin
{
	int a[100003],st[100003][21],l2[100003];
	inline void init(int l)
	{
		st[l][0]=a[l];
		for(int i=1; i<=20; i++) 
		st[l][i]=max(st[l][i-1],st[min(l+(1<<(i-1)),n)][i-1]);
	}
	inline int query(int l,int r)
	{
		int L=l2[r-l+1];
		return max(st[l][L],st[min(r-(1<<L)+1,n)][L]);
	}
	void main()
	{
	    for(int i=2; i<=n; i++) l2[i]=l2[i>>1]+1;
		for(int i=n; i; --i) init(i);
		return ;
	}
}st1;
struct stmax
{
	int a[100003],st[100003][21],l2[100003];
	inline void init(int l)
	{
		st[l][0]=a[l];
		for(int i=1; i<=20; i++) 
		st[l][i]=min(st[l][i-1],st[min(l+(1<<(i-1)),n)][i-1]);
	}
	inline int query(int l,int r)
	{
		int L=l2[r-l+1];
		return min(st[l][L],st[min(r-(1<<L)+1,n)][L]);
	}
	void main()
	{
	    for(int i=2; i<=n; i++) l2[i]=l2[i>>1]+1;
		for(int i=n; i; --i) init(i);
		return ;
	}
}st0;
int a[100003];
signed main()
{
	for(int i=1; i<=n; ++i) a[i]-=read();
	for(int i=1; i<=n; ++i) a[i]+=read();
	for(int i=1; i<=n; ++i) a[i]+=a[i-1],st0.a[i]=st1.a[i]=a[i];
	st0.main(),st1.main();
	for(;m--;)
	{
		int l=read(),r=read();
		int A=st0.query(l,r)-a[l-1],B=st1.query(l,r)-a[l-1];
		if(a[r]-a[l-1]!=0) puts("-1");
		else if(A<0) puts("-1");
		else printf("%lld\n",B);
	}
	return 0;
}