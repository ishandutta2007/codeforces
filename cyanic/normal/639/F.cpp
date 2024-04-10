#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}
int read(){int x;read(x);return x;}
int n,m,Q,R;
void Read(int &x){
	read(x),x=(x+R)%n;
	if(x==0)x=n;
}

const int N=1000005;
namespace G{
	int dfn[N],low[N],st[N],bel[N];
	int n,clk,cnt,top;
	vi e[N];
	void init(int _n){
		rep(i,1,n)dfn[i]=low[i]=bel[i]=0;
		rep(i,1,n)e[i].clear();
		n=_n,clk=cnt=top=0;
	}
	void add(int u,int v){
		e[u].pb(v),e[v].pb(u);
	}
	void tarjan(int u,int fa){
		dfn[u]=low[u]=++clk,st[++top]=u;
		for(auto v:e[u])if(v!=fa){
			if(!dfn[v]){
				tarjan(v,u);
				low[u]=min(low[u],low[v]);
			}
			else if(!bel[v])
				low[u]=min(low[u],dfn[v]);
		}
		else fa=0;
		if(low[u]!=dfn[u])return;++cnt;
		while(st[top]!=u)bel[st[top--]]=cnt;
		bel[st[top--]]=cnt;
	}
	vector<pii> doit(){
		vector<pii> res;
		rep(u,1,n)if(!dfn[u])tarjan(u,0);
		rep(u,1,n)for(auto v:e[u])
			if(bel[u]!=bel[v]&&bel[u]<bel[v])
				res.pb(mp(bel[u],bel[v]));
		return res;
	}
	void init(vi &U){
		for(auto u:U)dfn[u]=low[u]=bel[u]=0;
		for(auto u:U)e[u].clear();
		clk=cnt=top=0;		
	}
	void solve(vi &U){
		for(auto u:U)if(!dfn[u])tarjan(u,0);
	}
}

namespace T{
	int fa[N][20],d[N],dfn[N],bel[N],n,clk;
	vi e[N],sp;
	inline int lca(int a,int b){
		if(d[a]<d[b])swap(a,b);
		per(i,19,0)if(d[fa[a][i]]>=d[b])a=fa[a][i];
		if(a==b)return a;
		per(i,19,0)if(fa[a][i]!=fa[b][i])
			a=fa[a][i],b=fa[b][i];
		return fa[a][0];
	}
	void dfs(int u,int pa){
		fa[u][0]=pa,dfn[u]=++clk;
		rep(i,1,19)fa[u][i]=fa[fa[u][i-1]][i-1];
		for(auto v:e[u])if(v!=pa)d[v]=d[u]+1,dfs(v,u);
	}
	int mark[N];
	void Mark(int u){
		mark[u]=1;
		for(auto v:e[u])
			if(v!=n&&!mark[v])Mark(v);
	}
	void build(vector<pii> E){
		n=G::cnt+1;
		for(auto pi:E)
			e[pi.fi].pb(pi.se),
			e[pi.se].pb(pi.fi);
		rep(u,1,n-1)if(!mark[u]){
			e[n].pb(u),e[u].pb(n);
			Mark(u);
		}
		d[n]=1,dfs(n,0);
	}
	vector<pii> EE;
	inline bool cmp(int a,int b){
		return dfn[a]<dfn[b];
	}
	int f[N],stk[N],top;vi now;
	void push(){
		stk[top=1]=n,now.clear();
		sort(sp.begin(),sp.end(),cmp);
		REP(i,sp.size())if(!i||sp[i]!=sp[i-1]){
			int u=sp[i],v;
			while(top>=2&&d[lca(stk[top],u)]<d[stk[top-1]])
				f[stk[top]]=stk[top-1],top--;
			if(top>=2&&(v=lca(stk[top],u))!=stk[top]){
				f[stk[top]]=v,top--;
				if(stk[top]!=v) stk[++top]=v,now.pb(v);
			}
			if(stk[top]!=u)
				stk[++top]=u,now.pb(u);
		}
		while(top>=2)f[stk[top]]=stk[top-1],top--;
		G::init(now);
		for(auto u:now)if(f[u]!=n)G::add(u,f[u]);
		for(auto p:EE)G::add(p.fi,p.se);
		G::solve(now);
	}
	int tim;
	int solve(){
		int t=read(),K=read(),u,v,x; vi V;
		sp.clear(),EE.clear();
		while(t--)Read(x),V.pb(bel[x]),sp.pb(bel[x]);
		while(K--){
			Read(u),Read(v);
			sp.pb(bel[u]),sp.pb(bel[v]);
			EE.pb(mp(bel[u],bel[v]));
		}
		push();
		/*
		for(int i=0;i<V.size();i++)
			printf("# (%d,%d) ",V[i],G::bel[V[i]]);
		puts("");
		*/
		for(int i=0;i+1<V.size();i++)
			if(G::bel[V[i]]!=G::bel[V[i+1]])return 0;
		return 1;
	}
}

int main(){
	n=read(),m=read(),Q=read();
	G::init(n);
	rep(i,1,m)G::add(read(),read());
	T::build(G::doit());
	rep(i,1,n)T::bel[i]=G::bel[i];
	int owo=0;
	while(Q--){
		int res=T::solve();
		++owo,R=(R+res*owo)%n;
		puts(res?"YES":"NO");
	}
	return 0;
}