#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,lazy[1600001],a[200001],ans;
struct data
{
	int minn,sec,cnt,value;
}tree[1600001];
void up(int bj)
{
	tree[bj].value=tree[bj*2].value+tree[bj*2+1].value;
	if(tree[bj*2].minn==tree[bj*2+1].minn)
	{
		tree[bj].minn=tree[bj*2].minn;
		tree[bj].cnt=tree[bj*2].cnt+tree[bj*2+1].cnt;
		tree[bj].sec=min(tree[bj*2].sec,tree[bj*2+1].sec);
	}
	else
	{
		if(tree[bj*2].minn<tree[bj*2+1].minn)
		{
			tree[bj].minn=tree[bj*2].minn;
			tree[bj].cnt=tree[bj*2].cnt;
			tree[bj].sec=min(tree[bj*2].sec,tree[bj*2+1].minn);
		}
		else
		{
			tree[bj].minn=tree[bj*2+1].minn;
			tree[bj].cnt=tree[bj*2+1].cnt;
			tree[bj].sec=min(tree[bj*2].minn,tree[bj*2+1].sec);
		}
	}
}
void build(int l,int r,int bj)
{
	if(l==r)
	{
		tree[bj].minn=tree[bj].value=a[l];
		tree[bj].sec=0x3f3f3f3f3f3f3f3f;
		tree[bj].cnt=1;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,bj*2);
	build(mid+1,r,bj*2+1);
	up(bj);
}
void down(int l,int r,int mid,int bj)
{
	if(!lazy[bj])
		return;
	if(lazy[bj]>=tree[bj*2].minn)
	{
		tree[bj*2].value+=tree[bj*2].cnt*(lazy[bj]-tree[bj*2].minn);
		tree[bj*2].minn=lazy[bj];
		lazy[bj*2]=lazy[bj];
	}
	if(lazy[bj]>=tree[bj*2+1].minn)
	{
		tree[bj*2+1].value+=tree[bj*2+1].cnt*(lazy[bj]-tree[bj*2+1].minn);
		tree[bj*2+1].minn=lazy[bj];
		lazy[bj*2+1]=lazy[bj];
	}
	lazy[bj]=0;
}
void xg(int l,int r,int L,int R,int v,int bj)
{
	if(tree[bj].minn>=v)
		return;
	if(L<=l && r<=R)
	{
		if(tree[bj].sec>v && v>tree[bj].minn)
		{
			tree[bj].value+=(v-tree[bj].minn)*tree[bj].cnt;
			tree[bj].minn=v;
			lazy[bj]=v;
		}
		else
		{
			int mid=(l+r)/2;
			down(l,r,mid,bj);
			xg(l,mid,L,R,v,bj*2);
			xg(mid+1,r,L,R,v,bj*2+1);
			up(bj);
		}
		return;
	}
	int mid=(l+r)/2;
	down(l,r,mid,bj);
	if(L<=mid)
		xg(l,mid,L,R,v,bj*2);
	if(mid<R)
		xg(mid+1,r,L,R,v,bj*2+1);
	up(bj);
}
void cx(int l,int r,int L,int R,int &v,int bj)
{
	if(tree[bj].minn>v)
		return;
	if(L<=l && r<=R)
	{
		if(tree[bj].value<=v)
			v-=tree[bj].value,ans+=r-l+1;
		else
		{
			int mid=(l+r)/2;
			down(l,r,mid,bj);
			cx(l,mid,L,R,v,bj*2);
			cx(mid+1,r,L,R,v,bj*2+1);
		}
		return;
	}
	int mid=(l+r)/2;
	down(l,r,mid,bj);
	if(L<=mid)
		cx(l,mid,L,R,v,bj*2);
	if(mid<R)
		cx(mid+1,r,L,R,v,bj*2+1);
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int type=read();
		if(type==1)
		{
			int x=read(),v=read();
			xg(1,n,1,x,v,1);
		}
		else
		{
			int x=read(),v=read();
			ans=0;
			cx(1,n,x,n,v,1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}