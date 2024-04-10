#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
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
const int N = 600006;
int n,head[N],s[N],to[N],nxt[N],tp[N],num[N],edgenum=1,ans[N];bool vis[N];
void add(int u, int v, int t, int c) {
	to[++edgenum]=v; tp[edgenum]=t; num[edgenum]=c;
	nxt[edgenum]=head[u]; head[u]=edgenum;
}
void GG() {puts("Impossible"); exit(0);}
void dfs(int u, int fa, int E) { //tepan root !E
	vis[u]=1;
	L(i,u) if (!vis[to[i]]) dfs(to[i],u,i);
//	printf("%d : %d\n",u,E>>1);
	if (E) {
		ans[E>>1]=-s[u]*tp[E]; s[fa]=s[u]+s[fa]; s[u]=0;
	}
	if (s[u]) GG();
}
int main() {
	read(n);rep(i,1,n)read(s[i]),s[i]=-s[i];int m; read(m);
	rep(i,1,m){
		int u,v;read(u);read(v); add(u,v,1,i); add(v,u,-1,i);
	}
	rep(i,1,n) if (!vis[i]) dfs(i,0,0);
	rep(i,1,n) if (s[i]) GG();
	puts("Possible"); rep(i,1,m) printf("%d\n",ans[i]);
	return 0;
}