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
const int N = 600066,inf=0x3f3f3f3f;
int n,val[N];Vi e[N];
Pii a[N];
namespace lct{
	int ch[N][2],fa[N],sum[N];bool rev[N];
	inline void upd(int x){
		sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+val[x];
	}
	inline void pushdown(int x){
		if(rev[x]){
			rev[ch[x][0]]^=1;rev[ch[x][1]]^=1;
			swap(ch[x][0],ch[x][1]);
			rev[x]=0;
		}
	}
	inline bool getid(int x){return ch[fa[x]][1]==x;}
	inline bool isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
	inline void rotate(int x){
		int y=fa[x],z=fa[y],k=getid(x),c=ch[x][k^1];
		fa[x]=z;if(!isroot(y))ch[z][getid(y)]=x;
		fa[y]=x;ch[x][k^1]=y;
		fa[c]=y;ch[y][k]=c;
		upd(y);upd(x);
	}
	inline void splay(int x){
		static int sta[N];int top=0;
		for(int u=x;u;u=fa[u]){sta[++top]=u;if(isroot(u))break;}
		while(top)pushdown(sta[top--]);
		while(!isroot(x)){
			int y=fa[x];
			if(isroot(y)){rotate(x);break;}
			if(getid(x)==getid(y))rotate(y);else rotate(x);
			rotate(x);
		}
	}
	inline void access(int x){
		int y=0;
		while(x){
			splay(x);ch[x][1]=y;upd(x);
			y=x;x=fa[x];
		}
	}
	inline void makeroot(int u){
		access(u);splay(u);rev[u]^=1;
	}
	inline void link(int u, int v){
		makeroot(u);fa[u]=v;
	}
	inline void cut(int u, int v){
		makeroot(u);access(v);splay(v);
		ch[v][0]=fa[u]=0;upd(v);
	}
	inline int findroot(int u){
		access(u);splay(u);while(ch[u][0])u=ch[u][0];
		splay(u);return u;
	}
	inline int findone(int u, int v){
		makeroot(u);access(v);splay(v);
		while(v){
			pushdown(v);
			if(sum[ch[v][0]])v=ch[v][0];
			else if(val[v])return v;
			else v=ch[v][1];
		}
		assert(0);
	}
	inline void mdy(int x){splay(x);upd(x);}
}
vector<Pii>A,B;
void dfs(int u, int fa){
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)dfs(e[u][i],u);
	if(!fa)return;
	int x=lct::findone(u,fa);assert(x>=n+1&&x<=n+n-1);
	A.pb(Pii(u,fa));B.pb(a[x]);
	lct::cut(x,a[x].fi);lct::cut(x,a[x].se);
	a[x]=Pii(u,fa);lct::link(u,fa);//.;val[x]=0;lct::mdy(x);lct::link(x,a[x].fi);lct::link(x,a[x].se);
}
int main() {
	read(n);
	rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	rep(i,1,n-1){
		int u,v;read(u);read(v);
		a[n+i]=Pii(u,v);lct::link(u,n+i);lct::link(v,n+i);
	}
	rep(i,1,n-1)val[n+i]=1,lct::mdy(n+i);
	dfs(1,0);
	assert(SZ(A)==n-1);
	printf("%d\n",SZ(A));
	rep(i,0,SZ(A)-1)printf("%d %d %d %d\n",A[i].fi,A[i].se,B[i].fi,B[i].se);
	return 0;
}