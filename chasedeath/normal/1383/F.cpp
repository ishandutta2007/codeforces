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

const int N=1e4+10,INF=1e9+10;
typedef unsigned short US;

bool Mbe;
int n,m,k,q;
int dis[N],pre[N],Q[N],L,R;
struct Min_Cut{
	int to[N<<1],nxt[N<<1];
	US w[N<<1];
	int head[N],ecnt;
	void AddEdge(int u,int v,US wi){
		to[++ecnt]=v,nxt[ecnt]=head[u],w[ecnt]=wi;
		head[u]=ecnt;
	}
	void Link(int u,int v,US w){ AddEdge(u,v,w),AddEdge(v,u,0); }
	void chk(int u){
		if(dis[u]) return;
		dis[u]=1;
		for(int i=head[u];i;i=nxt[i]) if(w[i]==(US)-1) chk(to[i]);
	}
	int Checkinf(){
		rep(i,1,n) dis[i]=0;
		chk(1);
		return dis[n];
	}
	int Bfs(){
		static queue <int> que;
		rep(i,1,n) dis[i]=INF;
		Q[L=R=1]=1,dis[1]=0;
		for(int u;L<=R;) for(int i=head[u=Q[L++]];i;i=nxt[i]) {
			int v=to[i];
			if(!w[i] || dis[v]<=dis[u]+1) continue;
			dis[v]=dis[u]+1,Q[++R]=v;
		}
		return dis[n]<INF;
	}
	int Dfs(int u,int in){
		if(u==n) return in;
		int out=0;
		for(int i=head[u];i;i=nxt[i]) {
			int v=to[i];
			if(!w[i] || dis[v]!=dis[u]+1) continue;
			int t=Dfs(v,min((int)w[i],in-out));
			out+=t,w[i]-=t,w[i^1]+=t;
			if(in==out) break;
		}
		if(!out) dis[u]=0;
		return out;
	}
	int Dinic(){
		int ans=0;
		while(Bfs()) ans+=Dfs(1,INF);
		return ans;
	}
	int EK(){
		int ans=0;
		while(1) {
			rep(i,1,n) dis[i]=0;
			Q[L=R=1],dis[1]=INF;
			for(int u;L<=R;) {
				for(int i=head[u=Q[L++]];i;i=nxt[i]){
					int v=to[i];
					if(!w[i] || dis[v]) continue;
					dis[v]=min(dis[u],(int)w[i]),Q[++R]=v,pre[v]=i;
				}
			}
			if(!dis[n]) break;
			int e=dis[n]; ans+=e;
			for(int i=n;i>1;i=to[pre[i]^1]) w[pre[i]]-=e,w[pre[i]^1]+=e;
		}
		return ans;
	}
	int Dfser(int u,int in){
		if(u==n) return in;
		//cout<<"Dfser "<<u<<' '<<in<<endl;
		dis[u]=1;
		int out=0;
		for(int i=head[u];i;i=nxt[i]) {
			int v=to[i];
			if(!w[i] || dis[v]) continue;
			//cout<<v<<' '<<w[i]<<endl;
			int t=Dfser(v,min((int)w[i],in-out));
			out+=t,w[i]-=t,w[i^1]+=t;
			if(in==out) break;
		}
		//dis[u]=0;
		if(out) dis[u]=0;
		return out;
	}
	int Brute(){
		int ans=0;
		while(1) {
			rep(i,1,n) dis[i]=0;
			int t=Dfser(1,INF);
			if(!t) break;
			ans+=t;
		}
		return ans;
	}
} F[1<<10];
int G[1<<10];
int U[N],V[N],W[N],I[N];
int S[1<<10];

bool Med;
int main(){
	//fprintf(stderr,"%.2lf\n",(&Med-&Mbe)/1024.0/1024.0);
	n=rd(),m=rd(),k=rd(),q=rd();
	F[0].ecnt=1;
	rep(i,0,m-1) U[i]=rd(),V[i]=rd(),W[i]=rd();
	rep(i,k,m-1) I[i]=i;
	random_shuffle(I+k,I+m);
	rep(i,k,m-1) F[0].Link(U[I[i]],V[I[i]],W[I[i]]);
	G[0]=F[0].Dinic();
	int A=(1<<k)-1;
	rep(S,1,A) {
		int i=__lg(S&-S),T=S&(S-1);
		F[S]=F[T],F[S].Link(U[i],V[i],-1);
		if(F[S].Checkinf()) G[S]=INF;
		else G[S]=G[T]+F[S].Brute();
	}
	while(q--) {
		rep(i,0,k-1) W[i]=rd();
		rep(i,1,A) S[i]=S[i&(i-1)]+W[__lg(i&-i)];
		int ans=1e9;
		rep(i,0,A) cmin(ans,G[i]+S[A^i]);
		printf("%d\n",ans);
	}
}