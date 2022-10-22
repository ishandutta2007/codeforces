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

const int N=5e5+10,INF=1e9+10;

int n,m;
vector <int> G[N];
int deg[N];

int son[N][2],fa[N],s[N],t[N];
void Rev(int x){ t[x]^=1,swap(son[x][0],son[x][1]); }
void Down(int x){
	if(t[x]) for(int i:son[x]) if(i) Rev(i);
	t[x]=0;
}
void Up(int u){ s[u]=min(min(s[son[u][0]],s[son[u][1]]),u); }
int isroot(int x){ return !fa[x] || (son[fa[x]][0]!=x && son[fa[x]][1]!=x); }
int dir(int u){ return son[fa[u]][1]==u; }
void Rot(int u) {
	int d=dir(u),f=fa[u],ff=fa[f];
	fa[u]=ff; if(!isroot(f)) son[ff][dir(f)]=u; 
	son[f][d]=son[u][!d]; if(son[u][!d]) fa[son[u][!d]]=f;
	fa[f]=u,son[u][!d]=f; Up(f),Up(u);
}
void Splay(int u){ 
	static int S[N],T;
	for(int t=u;t;t=fa[t]) S[++T]=t;
	while(T) Down(S[T--]);
	for(int f;!isroot(u);Rot(u)) if(!isroot(f=fa[u])) Rot(dir(u)^dir(f)?u:f); 
}
void Access(int u) { for(int t=0;u;t=u,u=fa[u]) Splay(u),son[u][1]=t,Up(u); }
void MakeRoot(int u) { Access(u),Splay(u),Rev(u); }
void Link(int u,int v) { MakeRoot(u),Splay(u),fa[u]=v; }
void Cut(int u,int v) {
	MakeRoot(u),Access(v),Splay(v);
	assert(son[v][0]==u),fa[u]=0,son[v][0]=0,Up(v);
}
int Go(int u,int v) {
	MakeRoot(u),Access(v),Splay(u);
	while(1) {
		Down(u);
		if(s[son[u][0]]<n) u=son[u][0];
		else if(u<n) return u;
		else u=son[u][1];
	}
	return puts("WTF?"),-1;
}
int X[N],Y[N];
void dfs(int u,int f) {
	for(int v:G[u]) if(v!=f) dfs(v,u);
	if(!f) return;
	int i=Go(u+n,f+n);
	Cut(X[i]+n,i),Cut(Y[i]+n,i),Link(u+n,f+n);
	printf("%d %d %d %d\n",u,f,X[i],Y[i]);
}

int main() {
	n=rd(),s[0]=INF;
	rep(i,1,n-1) {
		int u=rd(),v=rd();
		G[u].pb(v),G[v].pb(u),deg[u]++,deg[v]++;
	}
	rep(i,1,n-1) {
		int u=X[i]=rd(),v=Y[i]=rd();
		Link(i,u+n),Link(i,v+n);
	}
	printf("%d\n",n-1);
	rep(i,1,n) if(deg[i]>1 || n==2) return dfs(i,0),0;
}