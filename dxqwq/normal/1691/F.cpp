// Problem: F. K-Set Tree
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1691/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
vector<int> e[200003];
int fac[200003],ifac[200003],sz[200003],ssz[200003];
int n=read(),k=read(),ans;
int C(int n)
{
	if(n<k) return 0;
	return fac[n]*ifac[k]%p*ifac[n-k]%p;
}
void dfs(int x,int fa=0)
{
	sz[x]=1;
	for(int y:e[x]) if(y!=fa)
		dfs(y,x),sz[x]+=sz[y];
	return ;
}
void calc(int x,int fa=0)
{
	int fsz=(n+(n-sz[x])*sz[x])%p;
	ssz[x]=n;
	for(int y:e[x]) if(y!=fa)
		fsz=(fsz+sz[y]*(n-sz[y]))%p;
	for(int y:e[x]) if(y!=fa)
		ans=(ans+(p+sz[y]*(n-sz[y])%p-(fsz+p-sz[y]*(n-sz[y])%p)%p)*C(sz[y]))%p,
		calc(y,x),ssz[x]=(ssz[x]+sz[y]*(n-sz[y]))%p,
		ans=(ans+(p+(n-sz[y])*sz[y]%p-ssz[y])*C(n-sz[y]))%p;
	return ;
}
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=fac[i-1]*i%p;
	ifac[n]=qp(fac[n],p-2);
	for(int i=n-1; i>=1; --i) ifac[i]=ifac[i+1]*(i+1)%p;
	for(int i=1,u,v; i<n; ++i)
		u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	ans=n*n%p*C(n)%p,dfs(1),calc(1),printf("%lld\n",ans);
	return 0;
}