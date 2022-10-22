#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=1e9+7;
inline int read()
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
int n,m,V[200001],value[200001],size[200001],son[200001],id[200001],num,tree[800001],lazy[800001],head[200001],tot;
struct sb
{
	int to,nextn;
}a[200001];
inline void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
inline void fun1(int u)
{
	size[u]=1;
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		fun1(v);
		size[u]+=size[v];
		if(size[v]>size[son[u]])
			son[u]=v;
	}
}
inline void fun2(int u)
{
	id[u]=++num;
	value[num]=V[u];
	if(!son[u])
		return;
	fun2(son[u]);
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==son[u])
			continue;
		fun2(v);
	}
}
inline void build(int l,int r,int bj)
{
	if(l==r)
	{
		tree[bj]=value[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,bj*2);
	build(mid+1,r,bj*2+1);
	tree[bj]=tree[bj*2]+tree[bj*2+1];
}
inline void down(int l,int r,int mid,int bj)
{
	if(!lazy[bj])
		return;
	tree[bj*2]=(mid-l+1)-tree[bj*2];
	tree[bj*2+1]=(r-mid)-tree[bj*2+1];
	lazy[bj*2]^=1;
	lazy[bj*2+1]^=1;
	lazy[bj]=0;
}
inline void xg(int l,int r,int L,int R,int bj)
{
	if(L<=l && r<=R)
	{
		tree[bj]=(r-l+1)-tree[bj];
		lazy[bj]^=1;
		return;
	}
	int mid=(l+r)/2;
	down(l,r,mid,bj);
	if(L<=mid)
		xg(l,mid,L,R,bj*2);
	if(mid<R)
		xg(mid+1,r,L,R,bj*2+1);
	tree[bj]=tree[bj*2]+tree[bj*2+1];
}
inline int cx(int l,int r,int L,int R,int bj)
{
	if(L<=l && r<=R)
		return tree[bj];
	int mid=(l+r)/2,bck=0;
	down(l,r,mid,bj);
	if(L<=mid)
		bck=cx(l,mid,L,R,bj*2);
	if(mid<R)
		bck+=cx(mid+1,r,L,R,bj*2+1);
	return bck;
}
int main()
{
	n=read();
	for(register int i=2;i<=n;++i)
		ADD(read(),i);
	for(register int i=1;i<=n;++i)
		V[i]=read();
	fun1(1);
	fun2(1);
	build(1,n,1);
	m=read();
	while(m--)
	{
		string type;
		cin>>type;
		if(type[0]=='g')
		{
			int u=read();
			printf("%d\n",cx(1,n,id[u],id[u]+size[u]-1,1));
		}
		else
		{
			int u=read();
			xg(1,n,id[u],id[u]+size[u]-1,1);
		}
	}
	return 0;
}