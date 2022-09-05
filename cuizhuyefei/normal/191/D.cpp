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
const int N = 633333;
int n,m;int fa[N],dep[N],fae[N],res,deg[N];
int head[N],to[N],nxt[N],edgenum=1,mrk[N];
void add(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
void dfs(int u, int Fa, int Dep){
	fa[u]=Fa;dep[u]=Dep;
	L(i,u)if(to[i]!=Fa)
		if(!dep[to[i]])fae[to[i]]=i,dfs(to[i],u,Dep+1);
		else if(dep[to[i]]<dep[u]){
			mrk[i>>1]=1;
			for(int v=u;v!=to[i];v=fa[v])mrk[fae[v]>>1]=1;
			int cnt=0;
			for(int v=u;;v=fa[v]){cnt+=deg[v]>2;if(v==to[i])break;}
			res+=cnt<=1;
		}
}
int main() {
	read(n);read(m);
	rep(i,1,m){int u,v;read(u);read(v);add(u,v);add(v,u);deg[u]++;deg[v]++;}
	dfs(1,0,1);
	int tot=0;rep(i,1,n)tot+=deg[i]&1;res+=tot/2;
	printf("%d %d\n",res,m);
	return 0;
}