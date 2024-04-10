#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
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
const int N = 333333,inf=0x3f3f3f3f;
int n,k,head[N],to[N],nxt[N],edgenum;
void add(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
int dis[N],q[N],pre[N],dep[N];bool ok=1;
int bfs(int s){
	int f=0,r=1;q[f]=s;
	memset(dis,inf,sizeof(dis));dis[s]=0;
	int res=s;
	while(f!=r){
		int u=q[f++];if(dis[u]>dis[res])res=u;
		L(i,u)if(dis[to[i]]==inf)
			dis[to[i]]=dis[u]+1,q[r++]=to[i],pre[to[i]]=u;
	}
	return res;
}
void dfs(int u, int fa, int Dep){
	int deg=0;
	L(i,u)if(to[i]!=fa)dfs(to[i],u,Dep+1),deg++;
	if(deg)ok&=deg>=3;else ok&=Dep==k;
}
int main() {
	read(n);read(k);
	rep(i,1,n-1){int u,v;read(u);read(v);add(u,v);add(v,u);}
	int S=bfs(1),T=bfs(S);
	if(dis[T]!=k*2){puts("No");return 0;}
	int u=T;rep(t,1,k)u=pre[u];//printf("u = %d\n",u);
	dfs(u,0,0);if(ok)puts("Yes");else puts("No");
	return 0;
}