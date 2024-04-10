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
const int N = 555555;
struct node{int x,y,z;}ans[N];int sz;
int n,m,fa[N],dep[N];Vi e[N],a[N],ch[N];bool used[N];
void dfs(int u, int Fa, int Dep){
	fa[u]=Fa;dep[u]=Dep;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa)
		if(!dep[e[u][i]])dfs(e[u][i],u,Dep+1),ch[u].pb(e[u][i]);
		else if(dep[u]>dep[e[u][i]])a[u].pb(e[u][i]);
}
void dfs1(int u){
	rep(i,0,SZ(ch[u])-1)dfs1(ch[u][i]);
	static int s[N];int len=0;
	rep(i,0,SZ(ch[u])-1)if(!used[ch[u][i]])s[++len]=ch[u][i];
	rep(i,0,SZ(a[u])-1)s[++len]=a[u][i];
	while(len>=2)ans[++sz]=(node){s[len],u,s[len-1]},len-=2;
	if(dep[u]>1&&len){
		ans[++sz]=(node){s[len],u,fa[u]};used[u]=1;
	}
}
int main() {
	read(n);read(m);
	rep(i,1,m){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	rep(i,1,n)if(!dep[i])dfs(i,0,1),dfs1(i);
	printf("%d\n",sz);rep(i,1,sz)printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
	return 0;
}