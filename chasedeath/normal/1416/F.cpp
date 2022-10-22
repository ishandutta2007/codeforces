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

const int N=2e5+10,INF=1e9+7;
const int dx[5]={0,0,-1,1};
const int dy[5]={-1,1,0,0};
const char dir[]="LRUD";

int n,m,S,T,a[N],f[N],b[N];
int I(int i,int j){ return (i-1)*m+j; }
int& A(int i,int j){ return a[I(i,j)]; }
int& F(int i,int j){ return f[I(i,j)]; }
int& B(int i,int j){ return b[I(i,j)]; }

struct Edge{
	int to,nxt,w;
} e[N*16];
int head[N],ecnt;
void AddEdge(int u,int v,int w){
	e[++ecnt]=(Edge){v,head[u],w};
	head[u]=ecnt;
}
void Link(int u,int v,int w){ AddEdge(u,v,w),AddEdge(v,u,0); }

int dis[N];
int Bfs() {
	rep(i,1,T) dis[i]=INF; 
	queue <int> que;
	que.push(S),dis[S]=0;
	while(!que.empty()) {
		int u=que.front();que.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			//cout<<"$Bfs"<<u<<' '<<v<<' '<<e[i].w<<endl;
			if(!e[i].w || dis[v]<=dis[u]+1) continue;
			dis[v]=dis[u]+1,que.push(v);
		}
	}
	return dis[T]<INF;
}

int Dfs(int u,int in){
	if(u==T) return in;
	int out=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!e[i].w || dis[v]!=dis[u]+1) continue;
		int t=Dfs(v,min(e[i].w,in-out));
		out+=t,e[i].w-=t,e[i^1].w+=t;
		if(in==out) break;
	}
	if(!out) dis[u]=0;
	return out;
}
	
void Dinic(){
	while(Bfs()) Dfs(S,INF);
}

int main() {
	rep(_,1,rd()) {
		n=rd(),m=rd(),ecnt=1;
		rep(i,1,n) rep(j,1,m) A(i,j)=rd();
		rep(i,1,n*m) b[i]=0;
		S=n*m+3,T=n*m+4;
		rep(i,1,T) head[i]=0;
		int X=0,Y=0;
		rep(i,1,n) rep(j,1,m) {
			int f=0;
			rep(d,0,3) {
				int x=i+dx[d],y=j+dy[d];
				if(x<1 || y<1 || x>n || y>m) continue;
				if((i+j)&1 && A(i,j)==A(x,y)) Link(I(i,j),I(x,y),1);
				if(A(i,j)>A(x,y)) F(i,j)=d,f=1,B(i,j)=A(i,j)-A(x,y);
			}
			//if(!f) cout<<"$"<<i<<' '<<j<<endl;
			if((i+j)&1) {
				if(f) Link(S-2,I(i,j),1);
				else X++,Link(S,I(i,j),1);
			} else {
				if(f) Link(I(i,j),T-2,1);
				else Y++,Link(I(i,j),T,1);
			}
		}
		Link(T-2,S-2,2*max(X,Y));
		Link(S-2,T,X),Link(S,T-2,Y);
		Dinic();
		int fl=1;
		//for(int i=head[S];i;i=e[i].nxt) cout<<e[i].w<<endl;
		//puts("#");
		//for(int i=head[T];i;i=e[i].nxt) cout<<e[i].w<<endl;
		for(int i=head[S];i;i=e[i].nxt) fl&=!e[i].w;
		for(int i=head[T];i;i=e[i].nxt) fl&=!e[i^1].w;
		if(!fl) { puts("NO"); continue; }
		puts("YES");
		rep(i,1,n*m) {
			int u=i;
			for(int i=head[u];i;i=e[i].nxt) if(~i&1) {
				int v=e[i].to;
				if(v<=n*m && !e[i].w) {
					b[u]=1,b[v]=a[u]-1;
					//cout<<"Link "<<u<<' '<<v<<endl;
					if(u>v) swap(u,v);
					if(v==u+m) f[u]=3,f[v]=2;
					else f[u]=1,f[v]=0;
					break;
				}
			}
		}
		rep(i,1,n) {
			rep(j,1,m) printf("%d ",B(i,j));
			puts("");
		}
		rep(i,1,n) {
			rep(j,1,m) putchar(dir[F(i,j)]),putchar(' ');
			puts("");
		}
	}
}