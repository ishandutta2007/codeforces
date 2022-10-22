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
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,a[MAXN];
struct seg_tree
{
	int maxn;
	ll sum;
}tree[MAXN*4];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void up(int x)
{
	tree[x].sum=tree[ls(x)].sum+tree[rs(x)].sum;
	tree[x].maxn=max(tree[ls(x)].maxn,tree[rs(x)].maxn);
}
void build(int l,int r,int x)
{
	if(l==r)
	{
		tree[x].maxn=tree[x].sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(x));
	build(mid+1,r,rs(x));
	up(x);
}
void fun(int l,int r,int L,int R,int val,int x)
{
	if(tree[x].maxn<val) return;
	if(l==r)
	{
		tree[x].maxn=tree[x].sum=tree[x].maxn%val;
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) fun(l,mid,L,R,val,ls(x));
	if(mid<R) fun(mid+1,r,L,R,val,rs(x));
	up(x);
}
void xg(int l,int r,int zone,int val,int x)
{
	if(l==r) {tree[x].maxn=tree[x].sum=val;return;}
	int mid=(l+r)>>1;
	if(zone<=mid) xg(l,mid,zone,val,ls(x));
	else xg(mid+1,r,zone,val,rs(x));
	up(x);
}
ll cx(int l,int r,int L,int R,int x)
{
	if(L<=l && r<=R) return tree[x].sum;
	int mid=(l+r)>>1;
	ll bck=0;
	if(L<=mid) bck=cx(l,mid,L,R,ls(x));
	if(mid<R) bck+=cx(mid+1,r,L,R,rs(x));
	return bck;
}
int main()
{
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	build(1,n,1);
	while(q--)
	{
		int type=read();
		if(type==1)
		{
			int l=read(),r=read();
			printf("%lld\n",cx(1,n,l,r,1));
		}
		if(type==2)
		{
			int l=read(),r=read(),x=read();
			fun(1,n,l,r,x,1);
		}
		if(type==3)
		{
			int x=read(),val=read();
			xg(1,n,x,val,1);
		}
	}
	return 0;
}
//ore no turn,draw!