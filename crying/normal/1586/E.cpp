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
const int MAXN=3e5+10;
int n,m,q,a[MAXN],b[MAXN],tag[MAXN];
int U[MAXN],V[MAXN];
int vis[MAXN],fa[MAXN];
vector<int>tree[MAXN],rete[MAXN];
vector<int>p;
map<pi,int>f;
int ans;
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]); 
}
int dfs(int u,int fa,int tgt){
	if(u==tgt){
		p.pb(u);
		return 1;
	}
	for(auto v:tree[u]){
		if(v==fa)continue;
		if(dfs(v,u,tgt)){
			p.pb(u);
			return 1;
		}
	}
	return 0;
}
int update(int u,int fa,int tgt){
	if(u==tgt)return 1;
	for(auto v:tree[u]){
		if(v==fa)continue;
		if(update(v,u,tgt)){
			f[mp(u,v)]++;
			f[mp(v,u)]++;
			f[mp(u,v)]%=2;
			f[mp(v,u)]%=2;
			return 1;
		}
	}
	return 0;
}
void solve(){
	rep(i,1,q){
		p.clear();
		dfs(b[i],0,a[i]);
		printf("%d\n",(int)p.size());
		for(auto u:p)printf("%d ",u);
		printf("\n");
	}
}
int qwq(int u,int fa){
	int sz=0,cnt=0;
	vis[u]=1;
	for(auto v:rete[u]){
		if(v==fa)continue;
		sz++;
		cnt+=qwq(v,u);
	}
	ans+=cnt/2;
	sz-=(cnt/2)*2;
	ans+=sz/2;
	return sz%2;
}
int main(){
	cin>>n>>m;
	rep(i,1,n)fa[i]=i;
	rep(i,1,m){
		int u,v;cin>>u>>v;
		U[i]=u,V[i]=v;
		if(Find(u)==Find(v))continue;
		tag[i]=1;
		tree[u].pb(v);tree[v].pb(u);
		fa[Find(u)]=Find(v);
	}
	cin>>q;
	rep(i,1,q){
		cin>>a[i]>>b[i];
		update(a[i],0,b[i]);
	}
	rep(i,1,m){
		if(tag[i]){
			if(f[mp(U[i],V[i])]==1){
				rete[U[i]].pb(V[i]);
				rete[V[i]].pb(U[i]);
			}
		}
	}
	rep(i,1,n){
		if(vis[i])continue;
		if(qwq(i,0))ans++;
	}
	if(ans==0){
		printf("YES\n");
		solve();
		return 0;
	}
	printf("NO\n");
	printf("%d\n",ans);
	

	return 0;
}