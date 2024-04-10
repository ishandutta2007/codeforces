// Problem: D. Cute number
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/contest/1687/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
int a[1000003],l[1000003],r[1000003];
int pre[1000003],nxt[1000003];
vector<int> f[2000003];
int fr(int x)//valid or next valid
{
	int t=sqrt(x);
	if(t*t<=x&&x<=t*(t+1)) return t;
	return t+1;
}
signed main()
{
	int n=read();
	nxt[0]=1;
	for(int i=1; i<=n; ++i) 
		l[i]=r[i]=a[i]=read(),pre[i]=i-1,nxt[i]=i+1;
	for(int i=1; i<n; ++i) 
		f[a[i+1]-a[i]].push_back(i);
	for(int i=0; i<=2000000; ++i)
	{
		for(int j:f[i])
			l[nxt[j]]=l[j],
			nxt[pre[j]]=nxt[j],
			pre[nxt[j]]=pre[j];
		int L=max(0ll,i*i-a[1]),R=i*(i+1)-a[1];
		for(int j=nxt[0],x,tl,tr; L<=R&&j<=n; j=nxt[j])
			x=fr(l[j]+L),tl=max(0ll,x*x-l[j]),
			tr=x*(x+1)-r[j],L=max(L,tl),R=min(R,tr);
		if(L<=R) printf("%lld\n",L),exit(0);
	}
	puts("-1");
	return 0;
}