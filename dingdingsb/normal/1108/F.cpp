#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
const int N=2e5+100,M=20;
int n,m,fa[N];
vector<tuple<int,int,int>>g,kl;
int f[N][M],mx[N][M],dep[N];
vector<pair<int,int>>e[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int u){
	dep[u]=dep[f[u][0]]+1;
	for(int i=1;i<M;i++)
		f[u][i]=f[f[u][i-1]][i-1],
		mx[u][i]=max(mx[u][i-1],mx[f[u][i-1]][i-1]);
	int v,w;
	for(auto E:e[u]){
		tie(v,w)=E;
		if(v==f[u][0])continue;
		f[v][0]=u;mx[v][0]=w;
		dfs(v);
	}
}
int get(int x,int y){
	int res=0;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=M-1;~i;i--)
		if(dep[f[x][i]]>=dep[y])
			chkmx(res,mx[x][i]),
			x=f[x][i];
	if(x==y)return res;
	for(int i=M-1;~i;i--)
		if(f[x][i]!=f[y][i])
			chkmx(res,mx[x][i]),
			chkmx(res,mx[y][i]),
			x=f[x][i],y=f[y][i];
	return max(max(mx[x][0],mx[y][0]),res);
}
signed main(){
	read(n,m);
	for(int i=1,u,v,w;i<=m;i++)
		read(u,v,w),g.pb({w,u,v});
	sort(g.begin(),g.end());
	for(int i=1;i<=n;i++)fa[i]=i;
	for(auto E:g){
		int v,u,w;tie(w,u,v)=E;
		if(find(u)!=find(v)){
			e[u].pb(mp(v,w));
			e[v].pb(mp(u,w));
			fa[find(u)]=find(v);
		}else kl.pb(E);
	}
	dfs(1);
	ll res=0;
	for(auto E:kl){
		int v,u,w;tie(w,u,v)=E;
		res+=max(0,get(u,v)+1-w);
	}
	write(res);
}