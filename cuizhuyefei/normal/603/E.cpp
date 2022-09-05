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
const int N = 466666;
int n,m,A[N],B[N],C[N],sz[N],vir[N],fa[N],a[N],pos[N],ch[N][2],cnt,rev[N];
set<Pii>Set;
	inline void upd(int x){
		sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+(x<=n)+vir[x];
		pos[x]=x;if(a[pos[ch[x][0]]]>a[pos[x]])pos[x]=pos[ch[x][0]];
		if(a[pos[ch[x][1]]]>a[pos[x]])pos[x]=pos[ch[x][1]];
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
			splay(x);vir[x]+=sz[ch[x][1]]-sz[y];
			ch[x][1]=y;upd(x);
			y=x;x=fa[x];
		}
	}
	inline void makeroot(int u){
		access(u);splay(u);rev[u]^=1;
	}
	inline void link(int u, int v){
		makeroot(u);fa[u]=v;vir[v]+=sz[u];upd(v);//sz[v]+=sz[u];
	}
	inline void cut(int u, int v){
		makeroot(u);access(v);splay(v);
		ch[v][0]=fa[u]=0;upd(v);
	}
	inline int findroot(int u){
		access(u);splay(u);while(ch[u][0])u=ch[u][0];
		splay(u);return u;
	}
int main() {
	read(n);read(m);
	rep(i,1,m)read(A[i]),read(B[i]),read(C[i]),a[n+i]=C[i];
	cnt=n;rep(i,1,n)sz[i]=1;
	rep(i,1,m){
		int x=findroot(A[i]),y=findroot(B[i]);
		if(x!=y){
			cnt-=sz[x]&1,cnt-=sz[y]&1,cnt+=sz[x]+sz[y]&1;
			link(A[i],n+i),link(B[i],n+i),Set.insert(Pii(C[i],i));
		}
		else{
			makeroot(A[i]);access(B[i]);splay(B[i]);int e=pos[B[i]];
			assert(e>=n+1&&e<=n+m);
			if(C[i]<a[e]){
				cut(e,A[e-n]),cut(e,B[e-n]),link(A[i],n+i),link(B[i],n+i);
				Set.erase(Pii(C[e-n],e-n));Set.insert(Pii(C[i],i));
			}
		}
		if(cnt)puts("-1");
		else{
			while(!Set.empty()){
				int i=(*Set.rbegin()).se,u=A[i],v=n+i;
				makeroot(u);access(v);splay(v);
				if(sz[u]%2)break;
				cut(A[i],n+i);cut(B[i],n+i);Set.erase(Pii(C[i],i));
			}
			printf("%d\n",(*Set.rbegin()).fi);
		}
	}
	return 0;
}