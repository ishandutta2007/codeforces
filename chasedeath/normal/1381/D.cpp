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

int n,k,a,b;
vector <int> G[N];
int mk[N],fl=0;
int ma;
int id;

struct Node{
	int u,d;
	Node(int u=0,int d=0):u(u),d(d){ }
	Node operator + (const int x) const { return Node(u,d+x); }
	int operator < (const Node x) const { return d<x.d; }
	int operator > (const Node x) const{ return d>x.d; }
	int operator == (const Node x) const { return u==x.u; }
} dp[N][3],g[N];

int fa[N][20],dep[N],L[N],R[N],I[N],dfn,s[N];
void dfs(int u,int f) { 
	I[L[u]=++dfn]=u;
	dp[u][0]=dp[u][1]=dp[u][2]=Node(u,0);
	dep[u]=dep[fa[u][0]=f]+1;
	rep(i,1,19) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:G[u]) if(v!=f) {
		dfs(v,u);
		Node t=dp[v][0]+1;
		rep(i,0,2) if(t>dp[u][i]) swap(dp[u][i],t);
	}
	R[u]=dfn;
}

void dfs2(int u,int f){
	static int t[5];
	t[0]=dp[u][0].d;
	t[1]=dp[u][1].d;
	t[2]=dp[u][2].d;
	t[3]=g[u].d;
	sort(t,t+4,greater<int>());
	mk[u]=t[2]>=k-1;
	//cout<<"$"<<u<<' '<<mk[u]<<endl;
	for(int v:G[u]) if(v!=f) {
		//cout<<"$"<<u<<' '<<f<<' '<<v<<endl;
		g[v]=max(g[u],dp[u][dp[u][0]==dp[v][0]+1])+1;
		dfs2(v,u);
	}
}

int Jump(int u,int k){
	rep(i,0,19) if(k&(1<<i)) u=fa[u][i];
	return u;
}
int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	x=Jump(x,dep[x]-dep[y]);
	if(x==y) return x;
	drep(i,19,0) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int Go(int a,int b,int k){
	int lca=LCA(a,b);
	if(dep[a]-dep[lca]<k) k-=dep[a]-dep[lca],a=lca;
	else return Jump(a,k);
	return Jump(b,(dep[b]-dep[a])-k);
}
int Max(int a,int b){
	if(L[a]<=L[b] && L[b]<=R[a]) {
		b=Jump(b,dep[b]-dep[a]-1);
		return max(g[a],dp[a][dp[b][0]+1==dp[a][0]]).u;
	} else return dp[a][0].u;
}
void MarkTree(int a,int b){
	if(L[a]<=L[b] && L[b]<=R[a]) {
		assert(a!=b);
		//cout<<a<<' '<<b<<' '<<"$ Jump"<<b<<' '<<dep[b]-dep[a]-1<<endl;
		b=Jump(b,dep[b]-dep[a]-1);
		//cout<<b<<endl;
		s[1]++,s[L[b]]--,s[R[b]+1]++,s[n+1]--;
	} else {
		s[L[a]]++,s[R[a]+1]--;
	}
}

int A[N],C;

int main(){
	rep(_,1,rd()) {
		n=rd(),a=rd(),b=rd();
		rep(i,1,n) G[i].clear();
		rep(i,2,n) {
			int u=rd(),v=rd();
			G[u].pb(v),G[v].pb(u);
		}
		dfn=0,dfs(a,0),k=dep[b],g[a]=Node(a,0),dfs2(a,0);
		rep(i,0,n) s[i]=0;
		rep(i,1,n*2) {
			swap(a,b);
			MarkTree(a,b),MarkTree(b,a);
			int c=Max(a,b),d=Go(c,b,k-1);
			a=c,b=d;
		}
		int fl=0;
		rep(i,1,n) s[i]+=s[i-1];
		rep(i,1,n) if(s[L[i]] && mk[i]) fl=1;
		puts(fl?"YES":"NO");
	}
}