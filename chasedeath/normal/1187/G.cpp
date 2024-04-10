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

const int N=110,INF=1e9+10;

int n,m,k,C,D;
int a[N];
struct Edge{
	int to,nxt;
} e[N<<1];
int head[N],ecnt=1;
void AddEdge(int u,int v){
	e[++ecnt]=(Edge){v,head[u]};
	head[u]=ecnt;
}

int dis[N][N],pre[N][N],inq[N][N],G[N][N],W[N][N];
static queue <Pii> que;
void Upd(int x,int y,int d,int p){
	if(dis[x][y]>d) {
		dis[x][y]=d,pre[x][y]=p;
		if(!inq[x][y]) inq[x][y]=1,que.push(mp(x,y));
	}
}

int cnt[N][N];

int main(){
	n=rd(),m=rd(),k=rd(),C=rd(),D=rd();
	rep(i,1,k) a[i]=rd();
	rep(i,1,m) {
		int u=rd(),v=rd();
		AddEdge(u,v),AddEdge(v,u);
		rep(j,1,n+k) G[j][i*2]=G[j][i*2+1]=1;
	}
	int ans=0;
	rep(_,1,k) {
		int u=a[_];
		rep(i,1,n+k) rep(j,1,n) dis[i][j]=INF;
		dis[1][u]=0,que.push(mp(1,u));
		int tu=1,ti=-1,mi=1e9;
		//puts("!");
		while(!que.empty()) {
			int t=que.front().first,u=que.front().second; que.pop();
			//cout<<u<<' '<<t<<' '<<dis[t][u]<<endl;
			inq[t][u]=0;
			if(u==1 && dis[t][u]<mi) mi=dis[t][u],ti=t,tu=u;
			if(t>1 && W[t-1][u]) Upd(t-1,u,dis[t][u]-C,1001);
			if(t<n+k) Upd(t+1,u,dis[t][u]+C,1002);
			for(int i=head[u];i;i=e[i].nxt) {
				int v=e[i].to;
				if(G[t-1][i^1]>1) Upd(t-1,v,dis[t][u]-(G[t-1][i^1]-2)*D-C,-(i^1));
				if(t<n+k) Upd(t+1,v,dis[t][u]+G[t][i]*D+C,i);
			}
		}
		ans+=mi;
		//cout<<tu<<' '<<ti<<' '<<mi<<endl;
		//puts("---");
		while(tu!=u || ti!=1) {
			int t=pre[ti][tu];
			//cout<<tu<<' '<<ti<<' '<<t<<endl;
			if(t==1001) --W[ti++][tu];
			else if(t==1002) W[--ti][tu]++;
			else if(t<0) G[ti][-t]-=2,tu=e[-t].to,ti++;
			else G[ti-1][t]+=2,tu=e[t^1].to,ti--;
		}
	}
	printf("%d\n",ans);
}