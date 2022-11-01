#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=500005;
int head[maxn],ne[maxn<<1],t[maxn<<1],dfn[maxn],low[maxn];
int num,clk,cnt=0,n,m,q;bool vis[maxn],flag[maxn];
int bl[maxn];
int faq[maxn],block;
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
inline void dfs(int x,int y){
	dfn[x]=low[x]=++clk;vis[x]=1;faq[x]=block;
	forE(i,x)if(i!=(y^1)){
		if(!vis[t[i]]){
			dfs(t[i],i);low[x]=min(low[x],low[t[i]]);
		}else low[x]=min(low[x],dfn[t[i]]);
	}if(y!=-1&&low[x]==dfn[x])flag[y>>1]=1;
}
inline void calc(int x){
	bl[x]=cnt;vis[x]=1;
	forE(i,x)if((!vis[t[i]])&&(!flag[i>>1]))
		calc(t[i]);
}
vector<int> son[maxn];
int fa[maxn][18],deep[maxn];
inline void dfs(int x){
	rep(i,1,17)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int v:son[x])if(v!=fa[x][0]){
		deep[v]=deep[x]+1;fa[v][0]=x;dfs(v);
	}
}
inline int lca(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	int dep=deep[x]-deep[y];
	rep(i,0,17)if((1<<i)&dep)x=fa[x][i];if(x==y)return x;
	per(i,17,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline void Fail(){
	puts("No");exit(0);
}
namespace ltree{
	pin v[maxn];
	int l[maxn],r[maxn],d[maxn];
	inline int merge(int x,int y){
		if(!x||!y)return x+y;
		if(deep[v[x].w1]<deep[v[y].w1])swap(x,y);
		r[x]=merge(r[x],y);
		if(d[l[x]]<d[r[x]])swap(l[x],r[x]);
		d[x]=d[r[x]]+1;
		return x;
	}
	inline int pop(int x){
		return merge(l[x],r[x]);
	}
};int tot=0;
vector<int> a[maxn];
int root[maxn];
inline void Getans(int x){
	vis[x]=1;
	for(int v:son[x])if(v!=fa[x][0]){
		Getans(v);
		while(root[v]&&ltree::v[root[v]].w1==x)root[v]=ltree::pop(root[v]);
		if(root[x]&&root[v]){
			if(ltree::v[root[x]].w2!=ltree::v[root[v]].w2)Fail();
		}
		root[x]=ltree::merge(root[x],root[v]);
	}
	while(root[x]&&ltree::v[root[x]].w1==x)root[x]=ltree::pop(root[x]);
	for(int w:a[x]){
		if(root[x]&&ltree::v[root[x]].w2!=ltree::v[w].w2)Fail();
		root[x]=ltree::merge(root[x],w);
	}
	while(root[x]&&ltree::v[root[x]].w1==x)root[x]=ltree::pop(root[x]);
}
int main(){
//	judge();
	read(n);read(m);read(q);rep(i,1,n)head[i]=-1;num=1;
	rep(i,1,m){int x,y;read(x);read(y);assert(x!=y);addedge(x,y);}
	rep(i,1,n){
		if(!vis[i])block++,dfs(i,-1);
	}
	rep(i,1,n)assert(vis[i]);
	memset(vis,0,sizeof(vis));
	rep(i,1,n)if(!vis[i]){
		cnt++;calc(i);
	}
	rep(i,1,m)if(flag[i]){
		if(bl[t[i<<1]]==bl[t[(i<<1)|1]])continue;
		son[bl[t[i<<1]]].pb(bl[t[(i<<1)|1]]);
		son[bl[t[(i<<1)|1]]].pb(bl[t[i<<1]]);
	}rep(i,1,n)if(!fa[i][0])dfs(i);
	rep(i,1,q){
		int x,y;read(x);read(y);if(faq[x]!=faq[y])Fail();
		int u=lca(bl[x],bl[y]);
		if(bl[x]==bl[y])continue;
		if(u!=bl[x])ltree::v[++tot]=mk(u,0),a[bl[x]].pb(tot);
		if(u!=bl[y])ltree::v[++tot]=mk(u,1),a[bl[y]].pb(tot);
	}memset(vis,0,sizeof(vis));
	rep(i,1,n)if(!vis[i])Getans(i);
	printf("Yes\n");
	return 0;
}