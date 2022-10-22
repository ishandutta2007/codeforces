#include<bits/stdc++.h>
using namespace std;

#define reg register
#define pb push_back
typedef long long ll;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,INF=1e9+10;

int n,m,q,tn,bit;
vector <int> G[N],E[N];
int val[N],low[N],t[N],dfn,stk[N],stktop;
multiset <int> st[N];
void pre_dfs(int u,int f) {
	low[u]=t[u]=++dfn;
	stk[++stktop]=u;
	for(auto v:G[u]) {
		if(v==f) continue;
		if(!t[v]) {
			pre_dfs(v,u);
			if(low[v]>=t[u]){
				for(int t=++n;t!=v;) E[n].pb(t=stk[stktop--]);
				E[u].pb(n);
			} else cmin(low[u],low[v]);
		} else cmin(low[u],t[v]);
	}
}

int dep[N],top[N],fa[N],sz[N],son[N],L[N],R[N],id[N],mi[N];
void dfs1(int u,int f) {
	if(u<=tn) st[f].insert(val[u]);
	fa[u]=f,sz[u]=1;
	for(auto v:E[u]) {
		dep[v]=dep[u]+1;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
	mi[u]=st[u].size()?*st[u].begin():val[u];
}
void dfs2(int u,int t) {
	id[L[u]=++dfn]=u,top[u]=t;
	if(son[u]) dfs2(son[u],t);
	for(auto v:E[u]) {
		if(v==son[u]) continue;
		dfs2(v,v);
	}
	R[u]=dfn;
}

int s[N<<2];
void Build() {
	bit=1;
	while(bit<=n+1) bit<<=1;
	memset(s,127,sizeof s);
	rep(i,1,n) s[i+bit]=mi[id[i]];
	drep(i,bit,1) s[i]=min(s[i<<1],s[i<<1|1]);
}
void Upd(int p,int x){
	s[p+=bit]=x;
	while(p>1) p>>=1,s[p]=min(s[p<<1],s[p<<1|1]);
}
int Que(int l,int r) {
	if(l==r) return s[l+bit];
	int res=INF;
	for(l+=bit-1,r+=bit+1;l^r^1;l>>=1,r>>=1) {
		((~l&1)&&res>s[l^1]&&(res=s[l^1]));
		((r&1)&&res>s[r^1]&&(res=s[r^1]));
	}
	return res;
}
void Set(int u,int x) {
	Upd(L[u],x);
	if(!fa[u]) return (void)(val[u]=x);
	st[fa[u]].erase(st[fa[u]].find(val[u]));
	st[fa[u]].insert(val[u]=x);
	Upd(L[fa[u]],mi[fa[u]]=*st[fa[u]].begin());
}

int Quepath(int x,int y) {
	if(x==y) return val[x];
	int res=INF;
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		cmin(res,Que(L[top[x]],L[x]));
		x=fa[top[x]];
	}
	if(L[x]>L[y]) swap(x,y);
	cmin(res,Que(L[x],L[y]));
	if(x>tn) cmin(res,val[fa[x]]);
	return res;
}


char opt[2];
int main(){
	tn=n=rd(),m=rd(),q=rd();
	rep(i,1,n) val[i]=rd();
	rep(i,1,m) {
		int u=rd(),v=rd();
		G[u].pb(v),G[v].pb(u);
	}
	pre_dfs(1,0),dfn=0;
	dfs1(1,0),dfs2(1,1);
	Build();
	rep(i,1,q) {
		scanf("%s",opt);
		if(opt[0]=='C') {
			int x=rd(),w=rd();
			Set(x,w);
		} else printf("%d\n",Quepath(rd(),rd()));
	}
}