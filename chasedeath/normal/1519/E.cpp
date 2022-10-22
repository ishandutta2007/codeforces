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

const int N=4e5+10,P=998244353;

int n,m;
struct Edge{
	int to,nxt;
} e[N*2];
int head[N];

struct Node{
	ll a,b;
	bool operator < (const Node __) const { return a<__.a || (a==__.a && b<__.b); } 
};
vector <int> G[N];

map <Node,int> M;
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
int Div(int a,int b,int c,int d){
	ll x=1ll*a*d,y=1ll*b*c,g=gcd(x,y);
	x/=g,y/=g;
	Node t=(Node){x,y};
	int &u=M[t];
	if(!u) u=++m;
	return u;
}

int vis[N],s[N],dfn;
void dfs(int u){
	vis[u]=++dfn,s[u]=0;
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to;
		if(vis[v] && vis[v]<vis[u]) continue;
		if(!vis[v]) dfs(v);
		if(!s[v]) s[u]^=1,G[u].pb(i/2);
		else s[v]^=1,G[v].pb(i/2);
	}
}

int main(){
	n=rd();
	rep(i,1,n) {
		int a=rd(),b=rd(),c=rd(),d=rd();
		int u=Div(a+b,b,c,d),v=Div(a,b,c+d,d);
		//cout<<u<<' '<<v<<endl;
		e[i*2]=(Edge){u,head[v]},head[v]=i*2;
		e[i*2+1]=(Edge){v,head[u]},head[u]=i*2+1;
	}
	rep(i,1,m) if(!vis[i]) dfs(i);
	int ans=0;
	rep(i,1,m) ans+=G[i].size()/2;
	printf("%d\n",ans);
	rep(i,1,m) {
		rep(j,0,G[i].size()/2-1) 
			printf("%d %d\n",G[i][j*2],G[i][j*2+1]);
	}
}