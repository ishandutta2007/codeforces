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
const int MAXN=2e5+10;
map<string,int>nm;
int n,rt,col[MAXN],cnt,q;
string s;
vector<int>e[MAXN];
vector<pi>qry[MAXN];
int ans[MAXN];
int fa[MAXN],sz[MAXN],son[MAXN],depth[MAXN];
set<int>arr[MAXN];
void dfs1(int u){
	sz[u]=1;
	depth[u]=depth[fa[u]]+1;
	for(auto v:e[u]){
		if(v==fa[u])continue;
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(!son[u] || (sz[son[u]]<sz[v]))son[u]=v;
	}
} 
void clr(int u,int rt){
	arr[depth[u]].clear();
	for(auto v:e[u]){
		if(v==fa[u])continue;
		clr(v,rt);
	}
}
void add(int u,int rt){
	arr[depth[u]].is(col[u]);
	for(auto v:e[u]){
		if(v==fa[u])continue;
		add(v,rt);
	}
}
void dfs2(int u){
	for(auto v:e[u]){
		if(v==fa[u] || v==son[u])continue;
		dfs2(v); 
		clr(v,v); 
	}
	if(son[u])dfs2(son[u]);
	arr[depth[u]].is(col[u]);
	for(auto v:e[u]){
		if(v==fa[u] || v==son[u])continue;
		add(v,u);
	}
	for(auto Q:qry[u]){
		int d=Q.fr,idx=Q.se;
		ans[idx]=arr[depth[u]+d].size(); 
	}
}
void solve(){
	dfs1(0); 
	dfs2(0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int fa;
		cin>>s;scanf("%d",&fa);
		e[fa].pb(i),e[i].pb(fa);
		if(nm.count(s))col[i]=nm[s];
		else{
			cnt++;col[i]=nm[s]=cnt;
		}
	}
	scanf("%d",&q);
	rep(i,1,q){
		int v,k;scanf("%d%d",&v,&k);
		qry[v].pb(mp(k,i));
	}
	solve();
	rep(i,1,q){
		printf("%d\n",ans[i]);
	}
	
	return 0;
}