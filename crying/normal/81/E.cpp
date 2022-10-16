#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10,MAXM=2e5+10;
int n,u,v,color[MAXN],vis[MAXN],fa[MAXN],depth[MAXN];
int pre[MAXN];
pi f[MAXN],g[MAXN],ans;
set<int>e[MAXN];
vector<pi>sol;
pi operator+(const pi& p1,const pi& p2){return mp(p1.fr+p2.fr,p1.se+p2.se);}
pi operator-(const pi& p1,const pi& p2){return mp(p1.fr-p2.fr,p1.se-p2.se);}
struct Dsu{
	int fa[MAXN];
	pi info[MAXN];
	void Init(){
		rep(i,1,n)fa[i]=i;
	}
	int Find(int x){
		if(fa[x]==x)return x;
		return fa[x]=Find(fa[x]);
	}
	void Merge(int x,int y){
		if(!info[Find(y)].fr)info[Find(y)]=info[Find(x)];
		fa[Find(x)]=Find(y);
	}
}dsu;
void predfs(int u){
	vis[u]=1;
	depth[u]=depth[fa[u]]+1;
	for(sit it=e[u].begin();it!=e[u].end();it++){
		if(vis[*it])continue;
		fa[*it]=u;predfs(*it);
	}
}
void clr(int u,int fa){
	f[u]=g[u]=mp(0,0);pre[u]=0;
	for(sit it=e[u].begin();it!=e[u].end();it++){
		if(fa==*it)continue;
		clr(*it,u);
	}
}
void dfs(int u,int fa){
	for(sit it=e[u].begin();it!=e[u].end();it++){
		if(fa==*it)continue;
		dfs(*it,u);
		g[u]=g[u]+f[*it];
	}
	f[u]=g[u];
	for(sit it=e[u].begin();it!=e[u].end();it++){
		if(fa==*it)continue;
		if(g[u]-f[*it]+g[*it]+mp(1,color[u]!=color[*it]) > f[u]){
			pre[u]=*it;
			f[u]=g[u]-f[*it]+g[*it]+mp(1,color[u]!=color[*it]);
		}
	}
}
pi dp(int u){
	clr(u,u); //	
	dfs(u,u);
	return f[u];
}
void solve(int u,int fa){
	if(pre[u]){
		sol.pb(mp(u,pre[u]));
		for(sit it=e[pre[u]].begin();it!=e[pre[u]].end();it++){
			if(*it == pre[u] || *it==u)continue;
			solve(*it,pre[u]); 
		}
	}
	for(sit it=e[u].begin();it!=e[u].end();it++){
		if(*it==pre[u] || *it==fa)continue;
		solve(*it,u);
	}
}
int main(){
	cin>>n;
	dsu.Init();
	rep(u,1,n){
		cin>>v>>color[u];
		if(dsu.Find(u)!=dsu.Find(v)){
			dsu.Merge(u,v);
			e[u].is(v),e[v].is(u);
		}else{
			dsu.info[dsu.Find(u)]=mp(u,v); //(u,v) 
		}
	}
	rep(i,1,n){
		if(vis[i])continue;
		//
		vis[i]=1;predfs(i);
		pi p=dsu.info[dsu.Find(i)],ret=mp(0,0),tmp=mp(0,0);
		int u,v,w;
		if(depth[p.fr]>depth[p.se])u=p.fr,v=fa[p.fr],w=p.se;
		else u=p.se,v=fa[p.se],w=p.fr;
		//1.(u,v)(u,w)
		e[u].erase(v),e[v].erase(u);
		e[u].is(w),e[w].is(u);
		ret=dp(i);
		//2.(u,w)(u,v) 
		e[u].erase(w),e[w].erase(u);
		e[u].is(v),e[v].is(u);
		tmp=dp(i); 
		ans=ans+Max(ret,tmp);
		if(tmp<ret){
			e[u].erase(v),e[v].erase(u);
			e[u].is(w),e[w].is(u);
		}
		dp(i);
		solve(i,i);
	}
	printf("%d %d\n",ans.fr,ans.se);
	int sz=sol.size();
	rep(i,0,sz-1){
		printf("%d %d\n",sol[i].fr,sol[i].se);
	}
	return 0;
}