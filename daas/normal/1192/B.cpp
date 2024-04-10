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
int n,q,W,id[MAXN],ans;
struct node
{
	int head[MAXN],tot;
	int to[MAXN*2],nextn[MAXN*2],l[MAXN*2];
	void ADD(int u,int v,int _l)
	{
		to[++tot]=v,nextn[tot]=head[u],l[tot]=_l;
		head[u]=tot;
	}
}Ed;
int st[MAXN],ed[MAXN],tim,A[MAXN*2],deep[MAXN];
void format(int u,int fa)
{
	A[st[u]=++tim]=u;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		id[i/2]=i;
		deep[v]=deep[u]+Ed.l[i];
		format(v,u);
		A[++tim]=u;
	}
	ed[u]=tim;
}
struct seg_tree
{
	int ans,lazy;
	int maxn,minn;
	int lm,rm;
}tree[MAXN*8];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void up(int x)
{
	tree[x].maxn=max(tree[ls(x)].maxn,tree[rs(x)].maxn);
	tree[x].minn=min(tree[ls(x)].minn,tree[rs(x)].minn);
	tree[x].lm=max(tree[ls(x)].lm,tree[rs(x)].lm);
	tree[x].lm=max(tree[x].lm,tree[ls(x)].maxn-2*tree[rs(x)].minn);
	tree[x].rm=max(tree[ls(x)].rm,tree[rs(x)].rm);
	tree[x].rm=max(tree[x].rm,tree[rs(x)].maxn-2*tree[ls(x)].minn);
	tree[x].ans=max(tree[ls(x)].ans,tree[rs(x)].ans);
	tree[x].ans=max(tree[x].ans,max(tree[ls(x)].lm+tree[rs(x)].maxn,tree[ls(x)].maxn+tree[rs(x)].rm));
}
void build(int l,int r,int x)
{
	if(l==r)
	{
		tree[x].maxn=tree[x].minn=deep[A[l]];
		tree[x].lm=tree[x].rm=-deep[A[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(x));
	build(mid+1,r,rs(x));
	up(x);
}
void change(int x,int val)
{
	tree[x].lm-=val;
	tree[x].rm-=val;
	tree[x].maxn+=val;
	tree[x].minn+=val;
	tree[x].lazy+=val;
}
void down(int x)
{
	if(!tree[x].lazy) return;
	change(ls(x),tree[x].lazy);
	change(rs(x),tree[x].lazy);
	tree[x].lazy=0;
}
void xg(int l,int r,int L,int R,int val,int x)
{
	if(L<=l && r<=R) {change(x,val);return;}
	int mid=(l+r)>>1;
	down(x);
	if(L<=mid) xg(l,mid,L,R,val,ls(x));
	if(mid<R) xg(mid+1,r,L,R,val,rs(x));
	up(x);
}
signed main()
{
	n=read(),q=read(),W=read();
	Ed.tot=1;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read(),l=read();
		Ed.ADD(u,v,l);
		Ed.ADD(v,u,l);
	}
	format(1,0);
	build(1,tim,1);
	while(q--)
	{
		int D=(read()+ans)%(n-1)+1,val=(read()+ans)%W;
		xg(1,tim,st[Ed.to[id[D]]],ed[Ed.to[id[D]]],val-Ed.l[id[D]],1);
		Ed.l[id[D]]=val;
		printf("%lld\n",ans=tree[1].ans);
	}
	return 0;
}
//ore no turn,draw!