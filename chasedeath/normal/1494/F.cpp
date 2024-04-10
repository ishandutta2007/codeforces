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

const int N=3010,INF=1e9+10;

int n,m;
struct Edge{
	int to,nxt;
} e[N*4];
int head[N],ecnt=1,D[N];
void AddEdge(int u,int v){
	e[++ecnt]=(Edge){v,head[u]};
	head[u]=ecnt,D[v]++;
}
int G[N][N];

int vis[N],A[N*N],C;
void dfs(int u) {
	for(int &i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(vis[i>>1]) continue;
		vis[i>>1]=1,dfs(v);
		//cout<<"E "<<u<<' '<<v<<endl;
		A[++C]=v;
		//return;
	}
}
int mk[N];
int U[N],V[N];
void ReInit(){
	memset(head,0,sizeof head),ecnt=1,memset(vis,0,sizeof vis);
	memset(D,0,sizeof D);
	rep(i,1,m) G[U[i]][V[i]]=G[V[i]][U[i]]=1,AddEdge(U[i],V[i]),AddEdge(V[i],U[i]);
}
int T[N];

int main(){
	n=rd(),m=rd();
	rep(i,1,m) U[i]=rd(),V[i]=rd();
	ReInit();
	int od=0;
	rep(i,1,n) od+=D[i]&1;
	if(od<=2) {
		int rt=1;
		rep(i,1,n) if(D[i]&1) rt=i;
		dfs(rt),printf("%d\n%d ",C+1,rt);
		drep(i,C,1) printf("%d ",A[i]);
		return 0;
	}
	int ti=0;
	rep(u,1,n) {
		int c=0;
		for(int i=head[u];i;i=e[i].nxt) c+=D[e[i].to]&1;
		od-=D[u]&1;
		rep(v,1,n) {
			int tod=od-(u!=v)*(D[v]&1?1:-1);
			int tc=c-G[u][v]*(D[v]&1?1:-1);
			//cout<<"$"<<u<<' '<<v<<' '<<tod<<' '<<tc<<endl;
			if(tc==tod) {
				if(++ti>n*2) return puts("0"),0;
				D[u]++,D[v]++;
				C=0;
				int c=0;
				for(int i=head[u];i;i=e[i].nxt) {
					int v=e[i].to;
					if(D[v]&1) T[++c]=v,vis[i>>1]=1;
				}
				dfs(u),A[++C]=u,A[++C]=-1;
				rep(i,1,c) A[++C]=T[i],A[++C]=u;
				int f=1;
				//cout<<"$"<<u<<' '<<v<<endl;
				//rep(i,1,C) cout<<A[i]<<' ';
				//puts("");
				rep(i,1,m) if(!vis[i]) f=0;
				if(f) {
					printf("%d\n",C);
					rep(i,1,C) printf("%d ",A[i]);
					return 0;
				}
				ReInit();
				//cout<<"Re"<<endl;
				//rep(i,1,n) cout<<D[i]<<' ';
				//puts("");
			}
		}
		od+=D[u]&1;
		/*if(c+(D[u]&1)>=od-1) {
			for(int i=head[u],p=-1;i;p=i,i=e[i].nxt) {
				int v=e[i].to;
				if(D[v]>1) {
					if(p==-1) head[u]=e[i].nxt;
					else e[p].nxt=e[i].nxt;
					vis[u][v]=vis[v][u]=1;
					dfs(v),A[++C]=v;
					break;
				}
			}
			A[++C]=u,A[++C]=-1;
			for(int &i=head[u];i;i=e[i].nxt) {
				int v=e[i].to;
				if(vis[u][v]) continue;
				vis[u][v]=vis[v][u]=1;
				A[++C]=v,A[++C]=u;
			}
			rep(u,1,n) for(int i=head[u];i;i=e[i].nxt) if(!vis[u][e[i].to]) puts("0"),exit(0);
			printf("%d\n",C);
			rep(i,1,C) printf("%d ",A[i]);
			return 0;
		}*/
	}
	puts("0");
}