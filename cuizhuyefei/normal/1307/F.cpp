#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666,inf=0x3f3f3f3f;
int a[N],fa[19][N],dep[N],dis[N],bel[N],n,k,r,f[N];Vi e[N];
void dfs1(int u, int Fa, int Dep){
	fa[0][u]=Fa;dep[u]=Dep;
	for(int v:e[u])if(v!=Fa)dfs1(v,u,Dep+1);
}
int kthfa(int u, int del){rep(i,0,18)if(del>>i&1)u=fa[i][u];return u;}
int getlca(int u, int v){
	if(dep[u]<dep[v])swap(u,v);int del=dep[u]-dep[v];
	u=kthfa(u,del);if(u==v)return u;
	per(i,18,0)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int jmp(int x, int y, int lca, int k){
	if(k<=dep[x]-dep[lca])return kthfa(x,k);
	return kthfa(y,dep[x]+dep[y]-2*dep[lca]-k);
}
bool ck(int x, int y){
	int lca=getlca(x,y);
	if(dep[x]+dep[y]-2*dep[lca]<=k)return 1;
	if(dis[x]>k||dis[y]>k)return 0;
	int l=0,r=k,u=bel[x];
	while(l<=r){
		int mid=(l+r)>>1,cur=jmp(x,y,lca,mid);
		if(dis[cur]+mid<=k)u=bel[cur],l=mid+1;
		else r=mid-1;
	}
	l=0,r=k;int v=bel[y];
	while(l<=r){
		int mid=(l+r)>>1,cur=jmp(y,x,lca,mid);
		if(dis[cur]+mid<=k)v=bel[cur],l=mid+1;
		else r=mid-1;
	}
//	printf("qwq %d %d\n",u,v);
	return find(u)==find(v);
}
void bfs(int cnt){
	static int q[N];int f=0,r=0;
	rep(i,1,n)dis[i]=inf;rep(i,1,cnt)dis[a[i]]=0,bel[a[i]]=a[i],q[r++]=a[i];
	while(f!=r){
		int u=q[f++];
		for(int v:e[u])if(dis[v]>dis[u]+1){
			dis[v]=dis[u]+1;bel[v]=bel[u];q[r++]=v;
		}
	}
}
int main() {
	read(n);read(k);read(r);
	rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	rep(i,1,r)read(a[i]);dfs1(1,0,0);
	rep(i,1,18)rep(j,1,n)fa[i][j]=fa[i-1][fa[i-1][j]];
	bfs(r);
	rep(i,1,n)f[i]=i;
	rep(u,1,n)for(int v:e[u])if(bel[u]!=bel[v]&&dis[u]+dis[v]+1<=k)
		f[find(bel[u])]=find(bel[v]);
//	rep(i,1,n)printf("%d:%d %d\n",i,bel[i],dis[i]);
	int Q;read(Q);
	while(Q--){
		int x,y;read(x);read(y);
		printf("%s\n",ck(x,y)?"YES":"NO");
	}
	return 0;
}