#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1220, M = 240030, inf = 0x3f3f3f3f;
int A[N],B[N],C[N],res;bool vis[N];//vector<Pii>e[N];
int n,m,S,T,head[N],cur[N],nxt[M],cap[M],to[M],edgenum=1; //1.WA--edgenum=1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void addedge(int u, int v, int c){
	to[++edgenum]=v;cap[edgenum]=c;nxt[edgenum]=head[u];head[u]=edgenum;
}
void add(int u, int v, int c){
	addedge(u,v,c);addedge(v,u,0);
}
int dis[N],q[N];
inline bool bfs() {
	memset(dis,inf,4*(n+2));//2.memsetsizeof()
	int f=0,r=1; q[f]=T; dis[T]=0;
	while (f!=r) {
		int u=q[f++];
		L(i,u) if (cap[i^1]&&dis[to[i]]==inf){
			q[r++]=to[i];dis[to[i]]=dis[u]+1;if(to[i]==S)return 1;//3.
		}
	}
	return dis[S]<inf;
}
inline int dfs(int u, int flow) {
	if (u==T||!flow)return flow;int res=0;
	for(register int &i=cur[u];i;i=nxt[i])if(cap[i]&&dis[u]==dis[to[i]]+1){//4. 
		int tmp=dfs(to[i],min(flow,cap[i]));
		res+=tmp;flow-=tmp;cap[i]-=tmp;cap[i^1]+=tmp;if(!flow)break;
	}
	return res;
}
inline int dinic() {
	int res=0;
	while (bfs()) {
		memcpy(cur,head,4*(n+2)); res+=dfs(S,inf);
	}
	return res;
}

void getpart(){
	memset(vis,0,n+2);
	static int q[N];int f=0,r=1;q[f]=S;vis[S]=1;
	while(f!=r){
		int u=q[f++];
		L(i,u)if(cap[i]&&!vis[to[i]])
			vis[to[i]]=1,q[r++]=to[i];
	}
}
int D[N],E[N],F[N],sz;
int solve(Vi s){
	if(SZ(s)<=1)return 0;
	int x=s.back(),y=s[SZ(s)-2];
	edgenum=1;memset(head,0,4*(n+2));
	S=x;T=y;rep(i,1,m)addedge(A[i],B[i],C[i]),addedge(B[i],A[i],C[i]);
	int res=dinic();getpart();Vi zuo,you;
	D[++sz]=x;E[sz]=y;F[sz]=res;
//	e[x].pb(Pii(y,res));e[y].pb(Pii(x,res));
	rep(i,0,SZ(s)-1)if(vis[s[i]])zuo.pb(s[i]);else you.pb(s[i]);
	return res+solve(zuo)+solve(you);
}
bool gg[N];int pos;
void dfs1(int u, int fa){
	L(i,u)if(!gg[i>>1]&&to[i]!=fa){
		dfs1(to[i],u);
		if(!pos||cap[i]<cap[pos])pos=i;
	}
}
Vi solve(int u){
	pos=0;dfs1(u,0);if(!pos)return{u};
	int x=to[pos],y=to[pos^1];gg[pos>>1]=1;
	Vi ans=solve(x),you=solve(y);
	rep(i,0,SZ(you)-1)ans.pb(you[i]);
	return ans;
}
int main() {
	read(n);read(m);
	rep(i,1,m)read(A[i]),read(B[i]),read(C[i]);
	Vi s;rep(i,1,n)s.pb(i);
	printf("%d\n",solve(s));
	edgenum=1;memset(head,0,sizeof(head));
//	cerr<<sz<<endl;
	rep(i,1,sz)addedge(D[i],E[i],F[i]),addedge(E[i],D[i],F[i]);//,cerr<<D[i]<<' '<<E[i]<<' '<<F[i]<<endl;
	Vi ans=solve(1);
	rep(i,0,SZ(ans)-1)printf("%d ",ans[i]);
	return 0;
}