#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cmath>
using namespace std;
const int N=100010;
struct Query{int l,r,id,l_group; }query[N];
struct EDGE { int adj,next; } edge[N*2];
int n,m,top,gh[N],c[N],reorder[N],deep[N],father[N],size[N],son[N],Top[N];
int gender[N],color[N];
void addedge(int x,int y)
{
	edge[++top].adj=y;
	edge[top].next=gh[x];
	gh[x]=top;
}
void dfs(int x,int root=0)
{
	reorder[x]=++top; father[x]=root; deep[x]=deep[root]+1;
	son[x]=0; size[x]=1; int dd=0;
	for(int p=gh[x];p;p=edge[p].next)
		if (edge[p].adj!=root)
		{
			dfs(edge[p].adj,x);
			if (size[edge[p].adj]>dd)
			{
				son[x]=edge[p].adj;
				dd=size[edge[p].adj];
			}
			size[x]+=size[edge[p].adj];
		}
}
void split(int x,int tp)
{
	Top[x]=tp;
	if (son[x])split(son[x],tp);
	for(int p=gh[x];p;p=edge[p].next)
		if (edge[p].adj!=father[x]&&edge[p].adj!=son[x])
			split(edge[p].adj,edge[p].adj);
}
int lca(int x,int y)
{
	int tx=Top[x],ty=Top[y];
	while (tx!=ty)
	{
		if (deep[tx]<deep[ty])
		{
			swap(tx,ty);
			swap(x,y);
		}
		x=father[tx];
		tx=Top[x];
	}
	if (deep[x]<deep[y])swap(x,y);
	return y;
}
bool cmp(const Query &a,const Query &b)
{
	if (a.l_group!=b.l_group)return a.l_group<b.l_group;
	return reorder[a.r]<reorder[b.r];
}
int v[N];
long long tans,ans[N];
int times[100010][2],cjb[100010],b[100010],sex[100010];
void checkin(int x)
{
	times[cjb[x]][sex[x]]++;
	tans+=times[cjb[x]][sex[x]^1];
}
void checkout(int x)
{
	times[cjb[x]][sex[x]]--;
	tans-=times[cjb[x]][sex[x]^1];
}
long long answer()
{
	return tans;
}
void upd(int x) { if (!v[x])checkin(x); else checkout(x); v[x]^=1;}
void go(int &u,int taru,int v)
{
	int lca0=lca(u,taru);
	int lca1=lca(u,v); upd(lca1);
	int lca2=lca(taru,v); upd(lca2);
	for(int x=u;x!=lca0;x=father[x])upd(x);
	for(int x=taru;x!=lca0;x=father[x])upd(x);
	u=taru;
}
int main()
{
	memset(gh,0,sizeof(gh));
	scanf("%d",&n); top=0;
	for(int i=1;i<=n;i++)scanf("%d",&sex[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&cjb[i]);
		b[i]=cjb[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)cjb[i]=lower_bound(b+1,b+n+1,cjb[i])-b;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&query[i].l,&query[i].r);
	top=0; dfs(1); split(1,1);
	for(int i=1;i<=m;i++)
	{
		if (reorder[query[i].l]>reorder[query[i].r])
			swap(query[i].l,query[i].r);
		query[i].id=i;
		query[i].l_group=reorder[query[i].l]/sqrt(n);
	}
	sort(query+1,query+m+1,cmp);
	int L=1,R=1; upd(1);
	for(int i=1;i<=m;i++)
	{
		go(L,query[i].l,R);
		go(R,query[i].r,L);
		ans[query[i].id]=answer();
	}
	for(int i=1;i<=m;i++)printf("%I64d\n",ans[i]);
}