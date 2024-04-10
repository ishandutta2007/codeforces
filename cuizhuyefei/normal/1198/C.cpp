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
int n,m;
int head[N],edgenum,to[N<<1],nxt[N<<1];
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
int a[N],lena;
int b[N],lenb;bool vis[N];
int main() {
	int T;read(T);while(T--){
		read(n);read(m);edgenum=1;
		rep(i,0,3*n)head[i]=0;
		while(m--){
			int u,v;read(u);read(v);
			add(u,v);add(v,u);
		}
		lena=lenb=0;
		rep(i,1,n*3)vis[i]=0;
		
		rep(u,1,n*3)if(!vis[u]){
			int x=0;L(i,u)if(!vis[to[i]])x=i;
			if(x){vis[u]=vis[to[x]]=1;a[++lena]=x>>1;}
			else vis[u]=1,b[++lenb]=u;
		}
		
		umin(lena,n);umin(lenb,n);
		if(lenb>=n){
			puts("IndSet");
			rep(i,1,n)printf("%d ",b[i]);puts("");
		}
		else{
			puts("Matching");
			rep(i,1,n)printf("%d ",a[i]);puts("");
		}
	}
	return 0;
}