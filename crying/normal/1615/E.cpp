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
const int MAXN=2e5+10,INF=1e9;
int n,u,v,k,sz[MAXN],dfn[MAXN],fa[MAXN],top[MAXN],depth[MAXN];
int m,leaf[MAXN],leafd[MAXN];
vector<int>e[MAXN];
void dfs(int u){
	sz[u]=1;dfn[u]=++dfn[0];
	depth[u]=depth[fa[u]]+1;
	top[u]=u;
	for(auto v:e[u]){
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
		sz[u]+=sz[v];
	}
}
int Find(int x){
	if(top[x]==x)return x;
	return top[x]=Find(top[x]); 
}
void up(pi& a,pi b){
	if(a.fr<b.fr)a=b;
}
bool cmp(int a,int b){
	return dfn[a]<dfn[b];
}
struct seg{
	int tag[MAXN<<2],maxn[MAXN<<2],pos[MAXN<<2];
	void pushup(int x){
		if(maxn[lc(x)]>maxn[rc(x)])maxn[x]=maxn[lc(x)],pos[x]=pos[lc(x)];
		else maxn[x]=maxn[rc(x)],pos[x]=pos[rc(x)];
	}
	void pushdown(int x){
		if(!tag[x])return;
		maxn[lc(x)]+=tag[x];maxn[rc(x)]+=tag[x];
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];
		tag[x]=0;
	}
	void build(int x,int l,int r){
		if(l==r){
			pos[x]=l;maxn[x]=depth[leaf[l]];
			return;
		}
		int mid=(l+r)>>1;
		build(lc(x),l,mid);build(rc(x),mid+1,r);
		pushup(x);
	}
	void upd(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l && qr>=r){
			maxn[x]+=val;tag[x]+=val;return;
		}
		pushdown(x);int mid=(l+r)>>1;
		if(ql<=mid)upd(lc(x),l,mid,ql,qr,val);
		if(qr>mid)upd(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
}t;
int ban;
void Remove(int u){
	int L=dfn[u],R=dfn[u]+sz[u]-1;
	//[L,R]
	int l=lower_bound(leafd+1,leafd+1+m,L)-leafd;
	int r=upper_bound(leafd+1,leafd+1+m,R)-leafd-1;
	if(l<=r)t.upd(1,1,m,l,r,-1);
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		e[u].pb(v);e[v].pb(u); 
	}
	dfs(1);
	rep(i,1,n)if(sz[i]==1){
		leaf[++m]=i;
	}
	sort(leaf+1,leaf+1+m,cmp);
	rep(i,1,m)leafd[i]=dfn[leaf[i]];
	if(k>=m){
		if(k<n/2){
			printf("%lld",1LL*(n-k)*k);
		}else{
			if(m<=n/2)printf("%lld",1LL*(n-n/2)*(n/2));
			else printf("%lld",1LL*(n-m)*m);
		}
		return 0; 
	}
	t.build(1,1,m);
	ll ans=-1e18;
//	memset(top,0,sizeof top);
	rep(i,1,k){
		pi tmp=mp(t.maxn[1],t.pos[1]);
		ban+=(tmp.fr-1);
		int u=leaf[tmp.se];
		while(u){
			Remove(u);
			top[Find(u)]=Find(fa[u]);
			u=Find(u);
		//	top[u]=1;u=fa[u];
		}
		/*
		int b=n-i-ban;
		ll cur=1LL*ban*(i-b);
		rep(j,-1,1){
			if(n/2+j<=b && n/2+j>=0){
				cur=min(cur,1LL*(n-i-n/2-j)*(i-n/2-j));
			}
		}
		ans=max(ans,cur);
		*/
		int b=min(n/2,n-i-ban);
		ans=max(ans,1LL*(n-i-b)*(i-b));
	}
	printf("%lld",ans);
	return 0;
}