#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10;

int n,m;
struct Node{
	int u,v,w;
	bool operator < (const Node __) const { return w<__.w; }
} E[N];
int nxt[N],head[N],L[N],R[N];
int F[N],mk[N];
vector <int> G[N];
unordered_map <int,int> M[N];
int U[N],V[N],W[N],C;
int Find(int x){ return F[x]==x?x:F[x]=Find(F[x]); }
void Erase(int x) { L[R[x]]=L[x],R[L[x]]=R[x]; }
void Union(int x,int y){
	x=Find(x),y=Find(y);
	if(x==y) return;
	F[y]=x,Erase(y),nxt[y]=head[x],head[x]=head[y];
}
int fa[N][20],D[N],dis[N];
void dfs(int u,int f){
	fa[u][0]=f;
	rep(i,1,18) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:G[u]) if(v!=f) D[v]=D[u]+1,dfs(v,u);
}
void dfs(int u) { for(int v:G[u]) if(v!=fa[u][0]) dis[v]+=dis[u],dfs(v); }
int LCA(int x,int y){
	if(D[x]<D[y]) swap(x,y);
	for(int i=0,del=D[x]-D[y];(1<<i)<=del;++i) if(del&(1<<i)) x=fa[x][i];
	if(x==y) return x;
	drep(i,18,0) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int main(){
	n=rd(),m=rd();
	rep(i,1,m) {
		E[i].u=rd(),E[i].v=rd(),E[i].w=rd();
		M[E[i].u][E[i].v]=M[E[i].v][E[i].u]=1;
	}
	rep(i,0,n+1) L[i]=i-1,R[i]=i+1;
	rep(i,1,n) head[i]=i,F[i]=i;
	int d=0;
	rep(i,1,n) {
		int u=Find(i);
		for(int t=R[0];t<=n;t=R[t]) {
			if(t==u) continue;
			for(int j=head[t];j;j=nxt[j]) if(!M[i].count(j)) {
				d++;
				U[++C]=i,V[C]=j;
				Union(t,u),u=Find(u);
				break;
			}
		}
	}
	sort(E+1,E+m+1);
	ll ans=0,xo=0;
	rep(i,1,m) xo^=E[i].w;
	rep(i,1,m) if(Find(E[i].u)!=Find(E[i].v)) {
		Union(E[i].u,E[i].v);
		U[++C]=E[i].u,V[C]=E[i].v,W[C]=E[i].w;
		ans+=E[i].w;
	}
	if(1ll*n*(n-1)/2-m-d>0) return printf("%lld\n",ans),0;
	int res=xo;
	rep(i,1,n) G[i].clear();
	rep(i,1,C) G[U[i]].pb(V[i]),G[V[i]].pb(U[i]);
	dfs(1,0);
	rep(i,1,C) if(!W[i]) dis[D[U[i]]<D[V[i]]?V[i]:U[i]]++;
	dfs(1);
	rep(i,1,m) if(!mk[i]) {
		int t=dis[E[i].u]+dis[E[i].v]-2*dis[LCA(E[i].u,E[i].v)];
		if(t) cmin(res,E[i].w);
	}
	printf("%lld\n",res+ans);
}