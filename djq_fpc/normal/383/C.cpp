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
#define int long long
using namespace std;
int n,m,i,j,dep[400005],lt[1600005],rt[1600005],sum[1600005],add[1600005],ti,fi[400005],ed[400005],a[400005],aa[400005],tp[400005],fa[400005],sz[400005],son[400005],x,y,op;
vector<int> bi[400005];
void pushup(int x)
{
	sum[x]=(sum[x*2]+sum[x*2+1]);
}
void pushdo(int x)
{
	if (add[x])
	{
		sum[x*2]+=add[x]*(rt[x*2]-lt[x*2]+1);
		sum[x*2+1]+=add[x]*(rt[x*2+1]-lt[x*2+1]+1);
		add[x*2]+=add[x];
		add[x*2+1]+=add[x];
		add[x]=0;
	}
}
void build(int x,int l,int r)
{
	lt[x]=l;
	rt[x]=r;
	add[x]=0;
	if (l==r)
	{
		sum[x]=0;
		return;
	}
	build(x*2,l,(l+r)/2);
	build(x*2+1,(l+r)/2+1,r);
	pushup(x);
}
void update(int x,int l,int r,int c)
{
	if (lt[x]>r||rt[x]<l) return;
	if (lt[x]>=l&&rt[x]<=r)
	{
		sum[x]+=(rt[x]-lt[x]+1)*c;
		add[x]+=c;
		return;
	}
	pushdo(x);
	update(x*2,l,r,c);
	update(x*2+1,l,r,c);
	pushup(x);
}
int query(int x,int l,int r)
{
	if (lt[x]>r||rt[x]<l) return 0;
	if (lt[x]>=l&&rt[x]<=r) return sum[x];
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
signed main()
{
	scanf("%I64d%I64d",&n,&m);
	fz1(i,n)
	{
		scanf("%I64d",&a[i]);
	}
	fz1(i,n-1)
	{
		scanf("%I64d%I64d",&x,&y);
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	while (m--)
	{
		scanf("%I64d",&op);
		if (op==1)
		{
			scanf("%I64d%I64d",&x,&y);
			if (dep[x]&1) y*=-1;
			update(1,fi[x],ed[x],y);
		}
		else
		{
			scanf("%I64d",&x); 
			if (dep[x]&1) printf("%I64d\n",a[x]-query(1,fi[x],fi[x])); else printf("%I64d\n",a[x]+query(1,fi[x],fi[x]));
		}
	}
	return 0;
}