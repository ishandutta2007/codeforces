#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
struct Edge{
	int to,w;
};
struct Q{
	int id,l,r;
};
int n,q;
vector<Edge> G[maxn];
vector<Q> query[maxn];
long long ans[maxn];
long long dep[maxn];
int dfn[maxn];
int ed[maxn];
long long seg[maxn*4];
long long lazy[maxn*4];
int tot=0;
void dfs(int u,int fa,long long depth)
{
	dfn[u]=++tot;
	dep[u]=depth;
	for(int i=0;i<G[u].size();i++)
	{
		Edge& v=G[u][i];
		if(v.to==fa) continue;
		dep[u]=0x3f3f3f3f3f3f3f3f;
		dfs(v.to,u,depth+v.w);
	}
	ed[u]=tot;
}
void pushup(int rt)
{
	seg[rt]=min(seg[rt*2],seg[rt*2+1]);
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		seg[rt]=dep[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	pushup(rt);
}
void pushdown(int rt)
{
	if(lazy[rt])
	{
		seg[rt*2]+=lazy[rt];
		seg[rt*2+1]+=lazy[rt];
		lazy[rt*2]+=lazy[rt];
		lazy[rt*2+1]+=lazy[rt];
		lazy[rt]=0;
	}
}
void update(int l,int r,int val,int L,int R,int rt)
{
	if(l<=L&&r>=R)
	{
		seg[rt]+=val;
		lazy[rt]+=val;
		return;
	}
	pushdown(rt);
	int mid=L+R>>1;
	if(l<=mid)
		update(l,r,val,L,mid,rt*2);
	if(r>mid)
		update(l,r,val,mid+1,R,rt*2+1);
	pushup(rt);
}
long long answer(int l,int r,int L,int R,int rt)
{
	if(l<=L&&r>=R)
		return seg[rt];
	pushdown(rt);
	int mid=L+R>>1;
	long long ret=0x3f3f3f3f3f3f3f3f;
	if(l<=mid)
		ret=min(ret,answer(l,r,L,mid,rt*2));
	if(r>mid)
		ret=min(ret,answer(l,r,mid+1,R,rt*2+1));
	return ret;
}
void solve(int u,int fa)
{
	for(int i=0;i<query[u].size();i++)
	{
		auto cur=query[u][i];
		ans[cur.id]=answer(cur.l,cur.r,1,n,1);
	}
	for(int i=0;i<G[u].size();i++)
	{
		auto v=G[u][i];
		if(v.to==fa) continue;
		update(1,n,v.w,1,n,1);
		update(dfn[v.to],ed[v.to],-2*v.w,1,n,1);
		solve(v.to,u);
		update(dfn[v.to],ed[v.to],2*v.w,1,n,1);
		update(1,n,-v.w,1,n,1);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=2,u,w;i<=n;i++)
	{
		scanf("%d%d",&u,&w);
		G[i].push_back(Edge{u,w});
		G[u].push_back(Edge{i,w});
	}
	for(int i=1,u,l,r;i<=q;i++)
	{
		scanf("%d%d%d",&u,&l,&r);
		query[u].push_back(Q{i,l,r});
	}
	dfs(1,-1,0);
	build(1,n,1);
	solve(1,-1);
	for(int i=1;i<=q;i++)
	{
		printf("%lld\n",ans[i]);
	}

}