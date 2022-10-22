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

const int N=2e5+10,INF=1e9+10;

int n1,n2,S,T,V,m,r,b;
struct Edge{
	int to,nxt,w,c;
} e[N];
int head[N],ecnt=1;
void AddEdge(int u,int v,int w,int c){
	e[++ecnt]=(Edge){v,head[u],w,c};
	head[u]=ecnt;
}
void Link(int u,int v,int w,int c){ AddEdge(u,v,w,c),AddEdge(v,u,0,-c); }

ll ans,dis[N];
char s[N];
int inq[N],pre[N],w[N];

int main(){
	n1=rd(),n2=rd(),m=rd(),r=rd(),b=rd(),S=n1+n2+1,T=S+1,V=T;
	scanf("%s",s+1);
	rep(i,1,n1) {
		if(s[i]=='R') Link(i,T,1,-INF),ans+=INF,Link(i,T,INF,0);
		if(s[i]=='B') Link(S,i,1,-INF),ans+=INF,Link(S,i,INF,0);
		if(s[i]=='U') Link(S,i,INF,0),Link(i,T,INF,0);
	}
	scanf("%s",s+1);
	rep(i,1,n2) {
		if(s[i]=='B') Link(i+n1,T,1,-INF),ans+=INF,Link(i+n1,T,INF,0);
		if(s[i]=='R') Link(S,i+n1,1,-INF),ans+=INF,Link(S,i+n1,INF,0);
		if(s[i]=='U') Link(S,i+n1,INF,0),Link(i+n1,T,INF,0);
	}
	rep(i,1,m) {
		int u=rd(),v=rd()+n1;
		Link(S,++V,2,-INF),ans+=2*INF;
		Link(V,u,1,0),Link(V,v,1,0);
		Link(V,u,1,r),Link(V,v,1,b);
		Link(u,T,1,-INF),ans+=INF;
		Link(v,T,1,-INF),ans+=INF;
	}
	while(1) {
		static queue <int> que;
		rep(i,1,V) dis[i]=1e18;
		dis[S]=0,que.push(S),w[S]=INF;
		while(!que.empty()) {
			int u=que.front(); que.pop();
			inq[u]=0;
			//cout<<"bfs "<<u<<' '<<dis[u]<<' '<<e[pre[u]].to<<' '<<e[pre[u]^1].to<<endl;
			for(int i=head[u];i;i=e[i].nxt) {
				int v=e[i].to,c=e[i].c;
				if(!e[i].w || dis[v]<=dis[u]+c) continue;
				dis[v]=dis[u]+c,w[v]=min(e[i].w,w[u]),pre[v]=i;
				if(!inq[v]) que.push(v),inq[v]=1;
			}
		}
		if(dis[T]>0) break;//==1e18) break;
		int c=w[T]; ans+=dis[T]*c;
		//cout<<c<<' '<<dis[T]<<endl;
		for(int u=T;u!=S;u=e[pre[u]^1].to) {
			//cout<<u<<endl;
			e[pre[u]].w-=c,e[pre[u]^1].w+=c;
		}
	}
	if(ans>INF) puts("-1");
	else {
		printf("%lld\n",ans);
		rep(u,T+1,T+m) {
			int c=0;
			for(int i=head[u];i;i=e[i].nxt) if(e[i].to<=n1) c+=e[i^1].w;
			putchar("BUR"[c]);
		}
	}
}