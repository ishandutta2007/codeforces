// Problem: D. Top-Notch Insertions
// Contest: Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1558/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
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
int fac[500003],ifac[500003];
int C(int n,int m)
{
	return fac[n]*ifac[n-m]%p*ifac[m]%p;
}
mt19937 rnd(114514);
struct node{int ls,rs,pri,val,tag,sz;}a[1000003];
int cnt=1;
void push_down(int x)
{
	if(!a[x].tag) return ;
	a[a[x].ls].tag+=a[x].tag,a[a[x].ls].val+=a[x].tag,
	a[a[x].rs].tag+=a[x].tag,a[a[x].rs].val+=a[x].tag,
	a[x].tag=0;
}
void update(int x)
{
	a[x].sz=a[a[x].ls].sz+a[a[x].rs].sz+1;
	return ;
}
void vsplit(int cur,int k,int &x,int &y)
{
	if(!cur) {x=0,y=0;return ;}
	push_down(cur);
	if(a[cur].val<k)
		x=cur,vsplit(a[cur].rs,k,a[x].rs,y);
	else
		y=cur,vsplit(a[cur].ls,k,x,a[y].ls);
	update(cur);
	return ;
}
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	push_down(x),push_down(y);
	if(a[x].pri>a[y].pri) 
		return a[y].ls=merge(x,a[y].ls),update(y),y;
	else
		return a[x].rs=merge(a[x].rs,y),update(x),x;
}
int fir(int x)
{
	if(!x) return -1;
	while(a[x].ls) push_down(x),x=a[x].ls;
	return a[x].val;
}
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=500000; ++i)
		fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int T=read();T--;)
	{
		int n=read(),m=read(),rt=0;
		for(int b,x,y; m--;)
		{
			read(),b=read(),vsplit(rt,b,x,y)
			,++a[y].tag,++a[y].val;
			if(fir(y)!=b+1)
				a[++cnt]=(node){0,0,rnd(),b+1,0,1},
				y=merge(cnt,y);
			rt=merge(x,y);
		}
		printf("%lld\n",C(n+n-1-a[rt].sz,n));
	}
	return 0;
}