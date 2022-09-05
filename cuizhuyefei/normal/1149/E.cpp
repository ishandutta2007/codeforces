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
const int N = 233333;
int n,m,a[N],b[N],s[N],len,sta[N],top,deg[N],sg[N];Vi e[N];bool vis[N];
int main() {
	read(n);read(m);
	rep(i,1,n)read(a[i]);
	while(m--){
		int u,v;read(u);read(v);e[u].pb(v);deg[v]++;
	}
	rep(i,1,n)if(!deg[i])sta[++top]=i;
	while(top){
		int u=sta[top--];s[++len]=u;
		rep(i,0,SZ(e[u])-1)
			if(!--deg[e[u][i]])sta[++top]=e[u][i];
	}
	per(t,n,1){
		int u=s[t];
		rep(i,0,SZ(e[u])-1)vis[sg[e[u][i]]]=1;
		for(sg[u]=0;vis[sg[u]];sg[u]++);
		rep(i,0,SZ(e[u])-1)vis[sg[e[u][i]]]=0;
	}
//	rep(i,1,n)printf("%d:%d\n",i,sg[i]);
	rep(i,1,n)b[sg[i]]^=a[i];bool gg=1;
	rep(i,0,n)gg&=!b[i];
	if(gg){puts("LOSE");return 0;}
	puts("WIN");int mx=0;rep(i,1,n)if(b[i])mx=i;
	rep(u,1,n)if(sg[u]==mx&&a[u]>(a[u]^b[mx])){
		a[u]^=b[mx];b[mx]=0;
		rep(i,0,SZ(e[u])-1)a[e[u][i]]^=b[sg[e[u][i]]],b[sg[e[u][i]]]=0;
		break;
	}
	rep(i,1,n)printf("%d ",a[i]);
	return 0;
}