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
const int N = 1010000;
int n,m,a,b,head[N],fa[N],to[N<<1],nxt[N<<1],edgenum,val[N];bool shu[N],vis[N];
void adde(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
void dfs1(int u, int Fa){
	fa[u]=Fa;vis[u]=1;
	L(i,u)if(!vis[to[i]])dfs1(to[i],u),shu[i>>1]=1;
//	else 
}
int cnt;
void getMrk(int u, int fa, int tar){
	val[u]=tar;cnt++;
	L(i,u)if(shu[i>>1]&&to[i]!=fa)getMrk(to[i],u,tar);
}
int f[N],sz[N];bool ok[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x, int y){
	x=find(x);y=find(y);if(x!=y)f[x]=y,sz[y]+=sz[x];
}
int main() {
	int T;read(T);while(T--){
		read(n);read(m);read(a);read(b);
		edgenum=1;rep(i,0,n)head[i]=vis[i]=val[i]=0;rep(i,0,m)shu[i]=0;
		while(m--){
			int u,v;read(u);read(v);adde(u,v);adde(v,u);
		}
		dfs1(a,0);
		static int sta[N];int top=0;
		for(int x=b;x;x=fa[x])sta[++top]=x;
		cnt=0;getMrk(b,sta[2],1);int zuo=cnt;
		cnt=0;getMrk(a,sta[top-1],2);int you=cnt;
		/*bool gg=0;
		rep(u,1,n)if(val[u])L(i,u)gg|=val[u]!=val[to[i]];
		if(gg)puts("0");else printf("%lld\n",1ll*zuo*you);*/
		rep(i,1,n)f[i]=i,sz[i]=1;
		rep(u,1,n)if(val[u])L(i,u)if(val[to[i]]==val[u]&&u!=a&&u!=b&&to[i]!=a&&to[i]!=b)merge(u,to[i]);
		rep(i,1,n)ok[i]=0;
		rep(u,1,n)if(val[u]&&(val[u]==1&&u!=b||val[u]==2&&u!=a))L(i,u)if(val[to[i]]!=val[u])ok[find(u)]=1;
		zuo=0;you=0;
		rep(i,1,n)if(find(i)==i&&val[i]&&!ok[i]&&i!=a&&i!=b){if(val[i]==1)zuo+=sz[i];else you+=sz[i];}
		printf("%lld\n",1ll*zuo*you);
	}
	return 0;
}