#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 200010
int n,m,head[MAXN],to[MAXN],nxt[MAXN],tree[MAXN<<2],tag[MAXN<<2],
size[MAXN],top[MAXN],son[MAXN],t,sums[MAXN],deep[MAXN],
t0t,dfn[MAXN],tar[MAXN],tot,fa[MAXN];
void addedge(int b,int e){nxt[++tot]=head[b];head[b]=tot;to[tot]=e;}
void pushdown(int u,int v){
	if(tag[u]==0)return;
	tag[u<<1]^=1;tag[u<<1|1]^=1;
	tree[u<<1]=(v+1>>1)-tree[u<<1];
	tree[u<<1|1]=(v>>1)-tree[u<<1|1];
	tag[u]=0;
}
void build(int u,int l,int r){
	if(l==r){
		tree[u]=sums[tar[l]];
		return;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	tree[u]=tree[u<<1]+tree[u<<1|1];
}
void change(int u,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		tree[u]=r-l+1-tree[u];
		tag[u]^=1;
		return;
	}
	pushdown(u,r-l+1);
	int mid=l+r>>1;
	if(mid>=L)change(u<<1,l,mid,L,R);
	if(mid<R)change(u<<1|1,mid+1,r,L,R);
	tree[u]=tree[u<<1]+tree[u<<1|1];
}
int query(int u,int l,int r,int L,int R){
	if(L<=l&&r<=R)return tree[u];
	pushdown(u,r-l+1);
	int ans=0,mid=l+r>>1;
	if(mid>=L)ans+=query(u<<1,l,mid,L,R);
	if(mid<R)ans+=query(u<<1|1,mid+1,r,L,R);
	return ans;
}
void dfs(int u){
	size[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		if(to[i]==fa[u])continue;
		dfs(to[i]);
		size[u]+=size[to[i]];
		if(son[u]==0||size[son[u]]<size[to[i]])
			son[u]=to[i];
	}
}
void dFs(int u){
	dfn[u]=++t0t;
	if(son[u])top[son[u]]=top[u],dFs(son[u]);
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=son[u])
			top[to[i]]=to[i],dFs(to[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
		scanf("%d",&fa[i]),addedge(fa[i],i);
	for(int i=1;i<=n;++i)
		scanf("%d",&sums[i]);
	dfs(1);top[1]=1;dFs(1);
	for(int i=1;i<=n;++i)tar[dfn[i]]=i;
	build(1,1,n);
	scanf("%d",&m);
	char buf[20];int x;
	while(m--){
		scanf("%s%d",buf,&x);
		if(buf[0]=='p'){
			change(1,1,n,dfn[x],dfn[x]+size[x]-1);
		}else{
			printf("%d\n",query(1,1,n,dfn[x],dfn[x]+size[x]-1));
		}
	}
	return 0;
}