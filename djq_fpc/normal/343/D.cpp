#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(int)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define int long long
using namespace std;
int n,m,i,j,dep[500005],lt[2000005],rt[2000005],add[2000005],ti,fi[500005],ed[500005],tp[500005],fa[500005],sz[500005],son[500005],x,y,op;
vector<int> bi[500005];
void pushdo(int x)
{
	if (add[x]!=-1)
	{
		add[x*2]=add[x];
		add[x*2+1]=add[x];
		add[x]=-1;
	}
}
void build(int x,int l,int r)
{
	lt[x]=l;
	rt[x]=r;
	add[x]=0;
	if (l==r)
	{
		return;
	}
	build(x*2,l,(l+r)/2);
	build(x*2+1,(l+r)/2+1,r);
}
void update(int x,int l,int r,int c)
{
	if (lt[x]>r||rt[x]<l) return;
	if (lt[x]>=l&&rt[x]<=r)
	{
		add[x]=c;
		return;
	}
	pushdo(x);
	update(x*2,l,r,c);
	update(x*2+1,l,r,c);
}
int query(int x,int l,int r)
{
	if (lt[x]>r||rt[x]<l) return 0;
	if (lt[x]>=l&&rt[x]<=r) return add[x];
	pushdo(x);
	return (query(x*2,l,r)+query(x*2+1,l,r));
}
void dfs1(int x,int p)
{
	fa[x]=p;
	sz[x]=1;
	ff(bi[x],it)
	{
		if (*it==p) continue;
		dep[*it]=dep[x]+1;
		dfs1(*it,x);
		sz[x]+=sz[*it];
		if (son[x]==0||sz[son[x]]<sz[*it]) son[x]=*it;
	}
}
void dfs2(int x,int t)
{
	fi[x]=++ti;tp[x]=t;
	if (!son[x])
	{
		ed[x]=ti;
		return;
	}
	dfs2(son[x],t);
	ff(bi[x],it)
	{
		if (*it==fa[x]||*it==son[x]) continue;
		dfs2(*it,*it);
	}
	ed[x]=ti;
}
void upd(int x)
{
	int i;
	while (x)
	{
		update(1,fi[tp[x]],fi[x],0);
		x=fa[tp[x]];
	}
}
int main()
{
	scanf("%d",&n);
	fz1(i,n-1)
	{
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d%d",&op,&x);
		if (op==1) update(1,fi[x],ed[x],1);
		if (op==2) upd(x);
		if (op==3) printf("%d\n",query(1,fi[x],fi[x]));
	}
	return 0;
}