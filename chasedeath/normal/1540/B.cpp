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

bool Mbe;
const int N=210,INF=1e9+10,P=1e9+7;

ll qpow(ll x,ll k=P-2) {
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

int n;
struct Edge{
	int to,nxt;
} e[N<<1];
int head[N],ecnt;
void AddEdge(int u,int v) {
	e[++ecnt]=(Edge){v,head[u]};
	head[u]=ecnt;
} 
int W[N][N],dep[N],L[N],R[N],dfn,I[N];
int ans;
void dfs(int u,int f) {
	dep[u]=dep[f]+1,I[L[u]=++dfn]=u;
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to;
		if(v==f) continue;
		dfs(v,u);
		rep(a,L[u],L[v]-1) rep(b,L[v],R[v]) {
			int x=I[a],y=I[b];
			if(x<y) swap(x,y);
			ans+=W[dep[x]-dep[u]][dep[y]-dep[u]],Mod1(ans);
		}
	}
	R[u]=dfn;
}

int main(){ 
	n=rd();
	rep(i,2,n) {
		int u=rd(),v=rd();
		AddEdge(u,v),AddEdge(v,u);
	}
	rep(i,0,n) rep(j,0,n) {
		if(!i) W[i][j]=1;
		else if(!j) W[i][j]=0;
		else W[i][j]=1ll*(W[i-1][j]+W[i][j-1])*(P+1)/2%P;
	}
	rep(i,1,n) dfn=0,dfs(i,0);
	ans=ans*qpow(n)%P;
	printf("%d\n",ans);
}