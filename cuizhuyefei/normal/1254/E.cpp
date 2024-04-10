#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 505050,mo=1e9+7;
int n,a[N],fa[N][20],dep[N],res=1,Fa[N],f[N],g[N],pre[N],nxt[N];Vi mn[N],mx[N];
Vi e[N];vector<Pii>cons[N];
int find(int x){return Fa[x]==x?x:Fa[x]=find(Fa[x]);}
void dfs1(int u, int Fa, int Dep){
	fa[u][0]=Fa;dep[u]=Dep;
	for(int v:e[u])if(v!=Fa)dfs1(v,u,Dep+1);
}
void dfs2(int u, int Fa){
	for(int v:e[u])if(v!=Fa)dfs2(v,u),f[u]+=f[v],g[u]+=g[v];
	if(Fa&&f[u]){
		cons[Fa].pb(Pii(u,fa[Fa][0]));
	}
	if(Fa&&g[u]){
		cons[Fa].pb(Pii(fa[Fa][0],u));
	}
}
int kthfa(int u, int del){rep(i,0,19)if(del>>i&1)u=fa[u][i];return u;}
int getlca(int u, int v){
	if(dep[u]<dep[v])swap(u,v);int del=dep[u]-dep[v];
	rep(i,0,19)if(del>>i&1)u=fa[u][i];
	if(u==v)return u;
	per(i,19,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

bool gg;
void link(int u, int v){
	if(nxt[u]==v&&pre[v]==u)return;
	if(nxt[u]||pre[v]||u==v||find(u)==find(v)){gg=1;return;}
	nxt[u]=v,pre[v]=u;Fa[find(u)]=find(v);
}
int solve(int u){
	sort(ALL(mn[u]));sort(ALL(mx[u]));
	if(SZ(mn[u])&&mn[u][0]!=mn[u].back())return 0;
	if(SZ(mx[u])&&mx[u][0]!=mx[u].back())return 0;
	for(int v:e[u])pre[v]=nxt[v]=0,Fa[v]=v;
	pre[n+1]=nxt[n+1]=pre[n+2]=nxt[n+2]=0;Fa[n+1]=n+1;Fa[n+2]=n+2;
	gg=0;
	if(SZ(mn[u]))link(n+1,mn[u][0]);
	if(SZ(mx[u]))link(mx[u][0],n+2);
	for(auto x:cons[u])link(x.fi,x.se);
	if(gg)return 0;
	for(int x=n+1,cnt=1;x;x=nxt[x],cnt++)if(x==n+2&&cnt<SZ(e[u])+2)return 0;
	int res=0,ans=1;
	for(int v:e[u])if(!pre[v]){
		bool ok=1;
		for(int x=v;x;x=nxt[x])ok&=x!=n+2;
		if(ok)res++,ans=1ll*ans*res%mo;
	//	printf("qwq %d %d %d(%d)\n",u,v,ok,SZ(cons[u]));
	}
	return ans;
}
int main() {
	read(n);rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	rep(i,1,n)read(a[i]);dfs1(1,0,0);
	rep(j,1,19)rep(i,1,n)fa[i][j]=fa[fa[i][j-1]][j-1];
	rep(i,1,n)if(a[i]==i){puts("0");return 0;}
	rep(j,1,19)rep(i,1,n)fa[i][j]=fa[fa[i][j-1]][j-1];
	rep(j,1,n)if(a[j]){
		int u=a[j],v=j,l=getlca(u,v);
	//	printf("%d %d %d\n",u,v,l);
		if(v==l){
			mn[u].pb(fa[u][0]);mx[v].pb(kthfa(u,dep[u]-dep[v]-1));
			f[u]++;f[kthfa(u,dep[u]-dep[v]-1)]--;
		}
		else if(u==l){
			mn[u].pb(kthfa(v,dep[v]-dep[u]-1));mx[v].pb(fa[v][0]);
			g[v]++;g[kthfa(v,dep[v]-dep[u]-1)]--;
		}
		else{
			mn[u].pb(fa[u][0]);mx[v].pb(fa[v][0]);
			f[u]++;f[kthfa(u,dep[u]-dep[l]-1)]--;
			g[v]++;g[kthfa(v,dep[v]-dep[l]-1)]--;
			cons[l].pb(Pii(kthfa(u,dep[u]-dep[l]-1),kthfa(v,dep[v]-dep[l]-1)));
		}
	}
	dfs2(1,0);
	rep(u,1,n){
		res=1ll*res*solve(u)%mo;
	}
	cout<<res;
	return 0;
}