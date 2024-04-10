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
const int N = 1020000, inf = 0x3f3f3f3f;
int to[N],nxt[N],edgenum,head[N];bool tp[N],mrk[N];
int n,k,m,f[N],dep[N],fa[N],ans[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void add(int x, int y, bool w){
	to[++edgenum]=y;nxt[edgenum]=head[x];head[x]=edgenum;tp[edgenum]=w;
	x=find(x);y=find(y);f[x]=y;
}
void dfs(int u, int Fa, int Dep){
	dep[u]=Dep;fa[u]=Fa;
	L(i,u)if(to[i]!=Fa)dfs(to[i],u,Dep+1);
}
inline void umin(int &x, int y){x=min(x,y);}
struct edge{int u,v,w;}e[N];bool cmp(edge a, edge b){return a.w<b.w;}
int main() {
	read(n);read(k);read(m);int x,y;
	rep(i,1,n)f[i]=i;
	rep(i,1,k){read(x);read(y);add(x,y,0);add(y,x,0);}
	memset(ans,inf,sizeof(ans));
	rep(i,1,m){read(e[i].u);read(e[i].v);read(e[i].w);}sort(e+1,e+m+1,cmp);
	rep(i,1,m)if(find(e[i].u)==find(e[i].v))mrk[i]=1;
	else add(e[i].u,e[i].v,1),add(e[i].v,e[i].u,1);
	dfs(1,0,0);rep(i,1,n)f[i]=i;
	rep(i,1,m)if(mrk[i]){
		int u=find(e[i].u),v=find(e[i].v);
		while(u!=v){
			if(dep[u]<dep[v])swap(u,v);
			ans[u]=e[i].w;f[u]=find(fa[u]);u=f[u];
		}
	}
	ll res=0;rep(i,1,n)if(dep[i]){
		int val=0;L(e,i)if(to[e]==fa[i])val=tp[e];if(val==1)continue;
		if(ans[i]>=inf){puts("-1");return 0;}res+=ans[i];
	}
	cout<<res;
	return 0;
}