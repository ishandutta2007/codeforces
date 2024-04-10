#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
#define int long long
using namespace std;
const int MAXN=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[MAXN],tree[MAXN*4],lazy[MAXN*4];
int gcd(int x,int y)
{
	int z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void change(int x,int v)
{
	if(!lazy[x]) lazy[x]=v,tree[x]=gcd(tree[x],v);
	else lazy[x]=gcd(lazy[x],v),tree[x]=gcd(tree[x],v);
}
void down(int x)
{
	if(!lazy[x]) return;
	change(ls(x),lazy[x]);
	change(rs(x),lazy[x]);
	lazy[x]=0;
}
void xg(int l,int r,int L,int R,int v,int x)
{
	if(L<=l && r<=R)
	{
		change(x,v);
		return;
	}
	int mid=(l+r)>>1;
	down(x);
	if(L<=mid) xg(l,mid,L,R,v,ls(x));
	if(mid<R) xg(mid+1,r,L,R,v,rs(x));
}
void xg_zone(int l,int r,int zone,int v,int x)
{
	if(l==r) {tree[x]=v;return;}
	int mid=(l+r)>>1;
	down(x);
	if(zone<=mid) xg_zone(l,mid,zone,v,ls(x));
	else xg_zone(mid+1,r,zone,v,rs(x));
}
int cx(int l,int r,int zone,int x)
{
	if(l==r) return tree[x];
	int mid=(l+r)>>1;
	down(x);
	if(zone<=mid) return cx(l,mid,zone,ls(x));
	else return cx(mid+1,r,zone,rs(x));
}
void build(int l,int r,int x)
{
	lazy[x]=tree[x]=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,ls(x));
	build(mid+1,r,rs(x));
}
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		int ans=0;
		build(1,n,1);
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1,lim=1;i<=n;++i)
		{
			if(i!=1) xg(1,n,1,i-1,abs(a[i]-a[i-1]),1);
			while(lim<i && cx(1,n,lim,1)==1) ++lim;
			ans=max(ans,i-lim+1);
			xg_zone(1,n,i,abs(a[i+1]-a[i]),1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//ore no turn,draw!