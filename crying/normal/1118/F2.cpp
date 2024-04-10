#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=3e5+10,mod=998244353;
int power(int a,int n){
	if(!n)return 1;
	int tmp=power(a,n/2);tmp=1LL*tmp*tmp%mod;
	if(n&1)tmp=1LL*tmp*a%mod;return tmp; 
}
int n,k,u,v;
int c[MAXN],flag[MAXN];
int dfn[MAXN],ord[MAXN],depth[MAXN],sz[MAXN],son[MAXN],fa[MAXN],top[MAXN],dfntot;
ll f[MAXN][2];
vector<int>V[MAXN],e[MAXN];
int cmp(const int& a,const int& b){
	return dfn[a]<dfn[b];
}
struct SegmentTree{
	int tree[MAXN<<2],tag[MAXN<<2];
	void pushup(int x){tree[x]=max(tree[lc(x)],tree[rc(x)]);}
	void pushdown(int x){if(!tag[x])return;
		tree[lc(x)]+=tag[x];tree[rc(x)]+=tag[x];
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];tag[x]=0;
	}
	void update(int x,int l,int r,int ql,int qr,int val){
		if(ql>qr)return;
		if(ql<=l && qr>=r){tree[x]+=val;tag[x]+=val;return;}
		pushdown(x);int mid=(l+r)>>1;
		if(ql<=mid)update(lc(x),l,mid,ql,qr,val);
		if(qr>mid)update(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
	int query(int x,int l,int r,int ql,int qr){
		if(ql>qr)return 0;
		if(ql<=l && qr>=r)return tree[x];
		pushdown(x);int mid=(l+r)>>1,ret=0;
		if(ql<=mid)ret=max(ret,query(lc(x),l,mid,ql,qr));
		if(qr>mid)ret=max(ret,query(rc(x),mid+1,r,ql,qr));
		pushup(x);return ret; 
	}
}tree;
void dfs1(int u){
	depth[u]=depth[fa[u]]+1;sz[u]=1;
	for(auto v:e[u]){if(v==fa[u])continue;
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(!son[u] || sz[son[u]]<sz[v])son[u]=v;
	}
}
void dfs2(int u,int node){
	top[u]=node;dfn[u]=++dfntot;ord[dfntot]=u;
	if(son[u])dfs2(son[u],node);
	for(auto v:e[u]){if(v==fa[u] || v==son[u])continue;
		dfs2(v,v);
	}
}
int query(int u,int v){
	int ret=0;
	while(top[u]!=top[v]){
		if(depth[top[u]]<depth[top[v]])swap(u,v);
		ret=max(ret,tree.query(1,1,n,dfn[top[u]],dfn[u]));
		u=fa[top[u]]; 
	}
	if(depth[u]>depth[v])swap(u,v);
	ret=max(ret,tree.query(1,1,n,dfn[u],dfn[v]));
	return ret;
}
void update(int u,int v,int c){
	while(top[u]!=top[v]){
		if(depth[top[u]]<depth[top[v]])swap(u,v);
		tree.update(1,1,n,dfn[top[u]],dfn[u],c);
		u=fa[top[u]]; 
	}
	if(depth[u]>depth[v])swap(u,v);
	tree.update(1,1,n,dfn[u],dfn[v],c);
}
void pre(){
	dfs1(1);
	dfs2(1,1);
	rep(i,1,k){
		sort(V[i].begin(),V[i].end(),cmp);
		int sz=V[i].size();
		if(query(V[i][0],V[i][0])!=0){printf("0");exit(0);}
		rep(j,1,sz-1){if(query(V[i][j-1],V[i][j])!=0){printf("0");exit(0);}}
		update(V[i][0],V[i][0],1); 
		rep(j,1,sz-1){update(V[i][j-1],V[i][j],1);}
	}
	rep(i,1,n){if(query(i,i)!=0)flag[i]=1;}
}
void dp(int u){
	ll mult=1;
	for(auto v:e[u]){if(v==fa[u])continue;
		dp(v);
		mult=mult*(f[v][0]+f[v][1])%mod;
	}
	if(flag[u]){
		f[u][0]=mult;
	}else{
		f[u][1]=mult;
		for(auto v:e[u]){if(v==fa[u])continue;
			f[u][0]=(f[u][0]+mult*power((f[v][0]+f[v][1])%mod,mod-2)%mod*f[v][0]%mod)%mod;
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d",&c[i]);
		if(c[i])V[c[i]].pb(i);
	}
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		e[u].pb(v);e[v].pb(u);
	}
	pre();
	dp(1);
	printf("%lld",f[1][0]);
	return 0;
}