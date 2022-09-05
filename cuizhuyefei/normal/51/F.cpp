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
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,m,head[N],to[N],nxt[N],edgenum=1;
void add(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
int dfn[N],low[N],num,f[N],deg[N];Vi e[N];bool iscut[N];
void tarjan(int u, int fa){
	dfn[u]=low[u]=++num;
	L(i,u)if(!dfn[to[i]]){
		tarjan(to[i],u);low[u]=min(low[u],low[to[i]]);
		iscut[i>>1]=low[to[i]]>dfn[u];
	}else if(to[i]!=fa&&dfn[to[i]]<dfn[u])low[u]=min(low[u],dfn[to[i]]);
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x, int y){x=find(x);y=find(y);f[x]=y;}
int q[N],dis[N];bool vis[N];
inline Pii bfs(int s){//WA :(dot,len)
	int f=0,r=1;q[f]=s;dis[s]=1;int mx=s;
	while(f!=r){
		int u=q[f++];if(dis[u]>dis[mx])mx=u;vis[u]=1;
		rep(i,0,SZ(e[u])-1)if(dis[e[u][i]]>dis[u]+1){
			dis[e[u][i]]=dis[u]+1;q[r++]=e[u][i];
		}
	}
	Pii res(mx,dis[mx]);
	rep(i,0,r-1)dis[q[i]]=0x3f3f3f3f;return res;
}
int main() {
	
	read(n);read(m);
	while(m--){int u,v;read(u);read(v);add(u,v);add(v,u);}
	int now=-1,res=0;rep(i,1,n)if(!dfn[i])tarjan(i,0),now++;
	rep(i,1,n)f[i]=i;
	rep(u,1,n)L(i,u)if(!iscut[i>>1])merge(u,to[i]);
	rep(u,1,n)L(i,u)if(iscut[i>>1]&&u<to[i]&&find(u)!=find(to[i]))
		deg[find(u)]++,deg[find(to[i])]++;
	rep(u,1,n)L(i,u)if(iscut[i>>1]&&u<to[i]&&find(u)!=find(to[i])&&deg[find(u)]>1&&deg[find(to[i])]>1)
		e[find(u)].pb(find(to[i])),e[find(to[i])].pb(find(u));
	memset(dis,0x3f3f3f3f,sizeof(dis));
	rep(i,1,n)if(deg[i]!=1&&find(i)==i&&!vis[i]){
		Pii j=bfs(i),k=bfs(j.fi);
		res+=k.se;
	}
	rep(i,1,n)if(deg[i]==1)res++;printf("%d",n-res+now);
	return 0;
}