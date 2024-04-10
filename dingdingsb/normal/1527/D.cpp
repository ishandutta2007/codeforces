#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=2e5+100,M=18;
int t,n;
vector<int>e[N];
int fa[N][M];
int dep[N],sz[N],ans[N];
void dfs(int u){
	sz[u]=1;dep[u]=dep[fa[u][0]]+1;
	for(int i=1;i<M;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u])if(v!=fa[u][0])
		fa[v][0]=u,dfs(v),sz[u]+=sz[v];
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=M-1;~i;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=M-1;~i;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int go(int x,int y){
	//xy
	for(int i=M-1;~i;i--)
		if(dep[fa[x][i]]>dep[y])
			x=fa[x][i];
	return x;
}
void solve(){
	read(n);
	for(int i=0;i<=n+10;i++)
		memset(fa[i],0,sizeof fa[i]),
		e[i].clear(),ans[i]=0,dep[i]=0,sz[i]=0;
	for(int i=1;i<n;i++){
		int u,v;read(u,v);u++,v++;
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1);
	int now=1;
	for(auto v:e[1])
		ans[0]+=sz[v]*now,now+=sz[v];
	for(int i=2,x=1,y=1;i<=n;i++){
		//printf("%d\n",i);
		int z=i;
		int mx=max(dis(x,y),max(dis(z,x),dis(z,y)));
		if(dis(z,x)==mx)swap(y,z);
		else if(dis(z,y)==mx)swap(x,z);
		if(dis(x,y)!=dis(x,z)+dis(z,y))
			break;
		if(lca(x,y)==x)ans[i-1]=sz[y]*(n-sz[go(y,x)]);
		else if(lca(x,y)==y)ans[i-1]=sz[x]*(n-sz[go(x,y)]);
		else ans[i-1]=sz[x]*sz[y];
	}
	write(n*(n-1)/2-ans[0]);putchar(' ');
	for(int i=0;i<n;i++)write(ans[i]-ans[i+1]),putchar(' ');
	putchar('\n');
}
signed main(){
	read(t);while(t--)solve();
}