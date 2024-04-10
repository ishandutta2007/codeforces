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

const int N=1544,INF=1e9+7;

int n,m,d;
int a[N];
struct Edge{
	int to,nxt,w,c;
} e[N*4];
int head[N],ecnt=1;
void AddEdge(int u,int v,int w,int c){
	e[++ecnt]=(Edge){v,head[u],w,c};
	head[u]=ecnt;
}
void Link(int u,int v,int w,int c){ AddEdge(u,v,w,c),AddEdge(v,u,0,-c); }
int S=1,T=2,V=2;

ll ans=0;
struct Tree{
	vector <int> G[N];
	int Rt,sz[N],lim[N],fa[N];
	void dfs(int u,int f) {
		//cout<<"pre dfs "<<u<<endl;
		sz[u]=1,lim[u]=-1,fa[u]=f;
		for(int v:G[u]) if(v!=f) {
			dfs(v,u);
			sz[u]+=sz[v];
		}
	}
	void ReadTree(){
		rep(i,2,n){
			int u=rd(),v=rd();
			G[u].pb(v),G[v].pb(u);
		}
		dfs(Rt,0);
	}
	void ReadLimit(){
		rep(_,1,rd()) {
			int u=rd(),x=rd();
			//cout<<"$"<<sz[u]<<endl;
			if(sz[u]<x) puts("-1"),exit(0);
			lim[u]=x;
		}
	}
	void Init(int k){
		fa[Rt]=T-V;
		if(k==0) {
			rep(i,1,n) {
				Link(T+i,V+i,1,a[i]);
				if(~lim[i]) {
					ans-=1ll*lim[i]*INF;
					Link(V+i,V+fa[i],lim[i],INF);
				} else Link(V+i,V+fa[i],n,0);
			}
		} else {
			rep(i,1,n) {
				Link(T+i,V+i,1,0);
				if(~lim[i]) {
					ans-=1ll*(sz[i]-lim[i])*INF;
					Link(V+i,V+fa[i],sz[i]-lim[i],INF);
				} else Link(V+i,V+fa[i],n,0);
			}
		}
		V+=n;
	}
} Tr[2];

ll dis[N];
int vis[N],pre[N];
int SPFA(){
	static queue <int> que;
	rep(i,1,V) dis[i]=-1e18;
	que.push(S),dis[S]=0;
	while(!que.empty()) {
		int u=que.front(); que.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,c=e[i].c;
			if(dis[v]>=dis[u]+c || !e[i].w) continue;
			dis[v]=dis[u]+e[i].c,pre[v]=i;
			//cout<<"$"<<u<<' '<<v<<' '<<e[i].c<<' '<<e[i].w<<endl;
			if(!vis[v]) vis[v]=1,que.push(v);
		}
	}
	return dis[T]>-1e18;
}

void EK(){
	while(SPFA()) {
		int w=INF;
		for(int u=T;pre[u];u=e[pre[u]^1].to) cmin(w,e[pre[u]].w);
		for(int u=T;pre[u];u=e[pre[u]^1].to) e[pre[u]].w-=w,e[pre[u]^1].w+=w;
		ans+=w*dis[T];
	}
}

int main(){
	n=rd(),Tr[0].Rt=rd(),Tr[1].Rt=rd();
	rep(i,1,n) Link(S,V+i,1,INF),ans-=INF;
	V+=n;
	rep(i,1,n) a[i]=rd();
	rep(i,0,1) Tr[i].ReadTree();
	rep(i,0,1) Tr[i].ReadLimit(),Tr[i].Init(i);
	EK();
	if(ans<0) puts("-1");
	else printf("%lld\n",ans);
}