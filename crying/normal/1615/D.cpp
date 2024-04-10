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
int T,n,m,u,v,w;
int fa[MAXN],dsu[MAXN],dis[MAXN];
map<pi,int>f;
vector<int>e[MAXN];
int Find(int x){
	if(dsu[x]==x)return x;
	int tmp=dsu[x];dsu[x]=Find(tmp);dis[x]^=dis[tmp];return dsu[x]; 
}
void dfs(int u){
	for(auto v:e[u]){
		if(v==fa[u])continue;
		fa[v]=u;dfs(v);
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	f.clear();rep(i,1,n){
		e[i].clear();
		fa[i]=0;
		dsu[i]=i;dis[i]=0;
	}
	rep(i,1,n-1){
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(v);e[v].pb(u);
		if(w!=-1)f[mp(u,v)]=f[mp(v,u)]=w;
	}
	dfs(1);
	int flag=0;
	for(auto tmp:f){
		int u=tmp.fr.fr,v=tmp.fr.se,w=tmp.se;
		w=__builtin_popcount(w)&1;
		int a=Find(u),b=Find(v);
		if(a==b){
			if((dis[u]^dis[v])!=w){
				flag=1;
			}
		}else{
			dis[a]=dis[u]^dis[v]^w;
			dsu[a]=b;
		}
	}
	rep(i,1,m){
		scanf("%d%d%d",&u,&v,&w);
		int a=Find(u),b=Find(v);
		if(a==b){
			if((dis[u]^dis[v])!=w){
				flag=1;
			}
		}else{
			dis[a]=dis[u]^dis[v]^w;
			dsu[a]=b;
		}
	}
	if(flag){printf("NO\n");return;}
	printf("YES\n");
	rep(i,2,n){
		if(f.find(mp(i,fa[i]))!=f.end()){
			printf("%d %d %d\n",i,fa[i],f[mp(i,fa[i])]);
		}else{
			int a=Find(i),b=Find(fa[i]);
			int vala=dis[i],valb=dis[fa[i]];
			printf("%d %d %d\n",i,fa[i],vala^valb);
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}