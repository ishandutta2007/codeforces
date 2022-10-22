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
struct Edge{
	int to,nxt,w;
}e[N];
int head[N],ecnt;
void AddEdge(int u,int v,int w){
	e[++ecnt]=(Edge){v,head[u],w};
	head[u]=ecnt;
}

ll G[N],S[N];
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
int t[N],low[N],dfn,stk[N],ins[N],top,id[N],scc;
ll dis[N];

void dfs(int u){
	ins[stk[++top]=u]=1,low[u]=t[u]=++dfn;
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to;
		if(!t[v]) {
			dis[v]=dis[u]+e[i].w;
			//cout<<"tree edge "<<u<<' '<<v<<endl;
			dfs(v),cmin(low[u],low[v]);
		} else if(ins[v]) {
			cmin(low[u],t[v]);
			//cout<<"Cir "<<u<<' '<<v<<' '<<dis[u]+dis[v]<<' '<<e[i].w<<endl;
			G[u]=gcd(G[u],dis[u]-dis[v]+e[i].w);
		}
	}
	if(low[u]==t[u]) {
		++scc;
		for(int v=-1;v!=u;) {
			ins[v=stk[top--]]=0;
			//cout<<"Scc "<<v<<' '<<scc<<endl;
			id[v]=scc,S[scc]=gcd(S[scc],G[v]);
		}
	}
}

int main(){
	n=rd(),m=rd();
	rep(i,1,m) {
		int u=rd(),v=rd(),w=rd();
		AddEdge(u,v,w);
	}
	rep(i,1,n) if(!t[i]) dfs(i);
	rep(_,1,rd()) {
		int u=rd(),s=rd(),t=rd();
		s=gcd(s,t),t=gcd(t,S[id[u]]);
		//cout<<"$"<<S[id[u]]<<endl;
		puts(s%t==0?"YES":"NO");
	}
}