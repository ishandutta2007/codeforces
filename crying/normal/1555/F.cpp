#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=3e5+10,MAXQ=5e5+10;
struct SegmentTree{
	int tree[MAXN<<2],tag[MAXN<<2];
	void pushup(int x){tree[x]=Max(tree[lc(x)],tree[rc(x)]);}
	void pushdown(int x){if(tag[x]==0)return;
		tree[lc(x)]+=tag[x];tree[rc(x)]+=tag[x];
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];
		tag[x]=0;
	}
	void update(int x,int l,int r,int ql,int qr,int val){
		if(ql>qr)return;
		if(ql<=l && qr>=r){
			tree[x]+=val;tag[x]+=val;
			return;
		}
		pushdown(x);
		int mid=(l+r)>>1;
		if(ql<=mid)update(lc(x),l,mid,ql,qr,val);
		if(qr>mid)update(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
	int query(int x,int l,int r,int ql,int qr){
		if(ql>qr)return 0;
		if(ql<=l && qr>=r){
			return tree[x];
		}
		pushdown(x);
		int mid=(l+r)>>1;int ret=0;
		if(ql<=mid)ret=max(ret,query(lc(x),l,mid,ql,qr));
		if(qr>mid)ret=max(ret,query(rc(x),mid+1,r,ql,qr));
		pushup(x);
		return ret;
	}
}tree;
struct Edge{
	int u,v,w;
}edge[MAXN*2];
int first[MAXN],next[MAXN*2],tot;
int n,q,u[MAXQ],v[MAXQ],w[MAXQ],tag[MAXQ];
int FA[MAXN],fa[MAXN][20],dist[MAXN][20],depth[MAXN],sz[MAXN],son[MAXN],dfn[MAXN],ord[MAXN],top[MAXN],vis[MAXN],dfntot;
void addedge(int u,int v,int w){
	edge[++tot]=(Edge){u,v,w};
	next[tot]=first[u];first[u]=tot;
}
int Find(int x){
	if(FA[x]==x)return x;
	return FA[x]=Find(FA[x]);
}
void Merge(int x,int y){
	FA[Find(x)]=Find(y);
}
void dfs1(int u){
	vis[u]=sz[u]=1;
	depth[u]=depth[fa[u][0]]+1;
	rep(j,1,18){
		fa[u][j]=fa[fa[u][j-1]][j-1];
		dist[u][j]=dist[u][j-1]^dist[fa[u][j-1]][j-1];
	}
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;if(v==fa[u][0])continue;
		fa[v][0]=u;dist[v][0]=edge[j].w;
		dfs1(v);sz[u]+=sz[v];
		if(!son[u] || sz[son[u]]<sz[v])son[u]=v;
	}
}
void dfs2(int u,int node){
	dfn[++dfntot]=u;
	ord[u]=dfntot;
	top[u]=node;
	if(son[u])dfs2(son[u],node);
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;if(v==fa[u][0] || v==son[u])continue;
		dfs2(v,v);
	}
}
void update(int x,int y,ll val){
	while(top[x]!=top[y]){
		if(depth[top[x]]<depth[top[y]])swap(x,y);
		tree.update(1,1,n,ord[top[x]],ord[x],val);
		x=fa[top[x]][0];
	}
	if(depth[x]>depth[y])swap(x,y);
	tree.update(1,1,n,ord[x]+1,ord[y],val);
}
int query(int x,int y){
	int ret=0;
	while(top[x]!=top[y]){
		if(depth[top[x]]<depth[top[y]])swap(x,y);
		ret=max(ret,tree.query(1,1,n,ord[top[x]],ord[x]));
		x=fa[top[x]][0];
	}
	if(depth[x]>depth[y])swap(x,y);
	ret=max(ret,tree.query(1,1,n,ord[x]+1,ord[y]));
	return ret;
}
int getdis(int x,int y){
	int ret=0;
	if(depth[x]<depth[y])swap(x,y);
	per(j,18,0){
		if(depth[x]-(1<<j)>=depth[y]){
			ret^=dist[x][j];
			x=fa[x][j];
		}
	} 
	if(x==y)return ret;
	per(j,18,0){
		if(fa[x][j]!=fa[y][j]){
			ret^=dist[x][j];ret^=dist[y][j];
			x=fa[x][j];y=fa[y][j];
		}
	}
	ret^=dist[x][0];ret^=dist[y][0];
	return ret;
}
il void Read(int& num){
	char ch;
	while((ch=getchar()) && (ch<'0' || ch>'9'));
	num=ch-'0';
	while((ch=getchar()) && (ch>='0' && ch<='9'))num=num*10+ch-'0';
}
int main(){
	Read(n);Read(q);
	rep(i,1,n)FA[i]=i;
	rep(i,1,q){
		Read(u[i]);Read(v[i]);Read(w[i]);
		if(Find(u[i])==Find(v[i]))continue;
		tag[i]=1;
		Merge(u[i],v[i]);
		addedge(u[i],v[i],w[i]);addedge(v[i],u[i],w[i]);
	}
	rep(i,1,n){
		if(vis[i])continue;
		dfs1(i);
	}
	rep(i,1,n){
		if(depth[i]==1){
			dfs2(i,i);
		}
	}
	rep(i,1,q){
		if(tag[i]){
			printf("YES\n");
			continue;
		}
		ll d=getdis(u[i],v[i]);
		if((d^w[i])!=1){
			printf("NO\n");
			continue;
		}
		ll maxn=query(u[i],v[i]);
		if(maxn>0){
			printf("NO\n");
			continue;
		}
		update(u[i],v[i],1);
		printf("YES\n");
	}
	return 0;
}