// Problem: E. A Museum Robbery
// Contest: Codeforces Round #333 (Div. 1)
// URL: https://codeforces.com/contest/601/problem/E
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
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7,q=1e7+19;
int a[40003],b[40003],s[40003],t[40003];
vector<pair<int,int>> v[120003];
int f[23][1003];
void update(int nl,int nr,int l,int r,int x,int i)
{
	if(nr<l||r<nl) return ;
	if(l<=nl&&nr<=r) 
	{
		v[x].push_back(make_pair(a[i],b[i]));
		return ;
	}
	int mid=(nl+nr)>>1;
	update(nl,mid,l,r,x<<1,i),update(mid+1,nr,l,r,(x<<1)+1,i);
	return ; 
}
int n=read(),k=read();
void solve(int l,int r,int x,int dep)
{
	for(int i=0; i<=k; ++i) f[dep][i]=f[dep-1][i];
	for(auto p:v[x])
		for(int j=k; j>=p.second; --j)
			f[dep][j]=max(f[dep][j],f[dep][j-p.second]+p.first);
	if(l==r)
	{
		int s=0;
		for(int j=1,O=1; j<=k; ++j,O=1ll*O*q%p) 
			s=(1ll*f[dep][j]*O+s)%p;
		printf("%d\n",s);
		return ;
	}
	int mid=(l+r)>>1;
	solve(l,mid,x<<1,dep+1),solve(mid+1,r,(x<<1)+1,dep+1);
	return ;
}
signed main()
{
	for(int i=1; i<=n; ++i) 
		a[i]=read(),b[i]=read(),s[i]=1,t[i]=-1;
	int id=0;
	for(int T=read(),op; T--;)
	{
		op=read();
		if(op==1) a[++n]=read(),b[n]=read(),s[n]=id+1,t[n]=-1;
		else if(op==2) t[read()]=id;
		else ++id;
	}
	for(int i=1; i<=n; ++i) 
	{
		if(t[i]==-1) t[i]=id;
		if(s[i]<=t[i]) update(1,id,s[i],t[i],1,i);
	}
	solve(1,id,1,1);
	return 0;
}