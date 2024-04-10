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
const int N = 666666;
int deg[N],n,m,head[N],to[N],nxt[N],edgenum=1;bool gg[N];
Pii sta[N];int top;
void addedge(int u, int v){
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
	swap(u,v);
	to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
}
void dfs(int u){
	while(head[u]){
		if(gg[head[u]>>1])head[u]=nxt[head[u]];
		else{
			int i=head[u];head[u]=nxt[i];gg[i>>1]=1;
			dfs(to[i]);sta[++top]=Pii(u,to[i]);
		}
	}
}
int main() {
	read(n);read(m);
	rep(i,1,m){int u,v;read(u);read(v);addedge(u,v);deg[u]++;deg[v]++;}
	Vi a;rep(i,1,n)if(deg[i]&1)a.pb(i);
	for(int i=0;i<SZ(a);i+=2)addedge(a[i],a[i+1]),m++;
	if(m%2)addedge(1,1),m++;
	dfs(1);printf("%d\n",top);assert(top==m);
	for(int i=1;i<=top;i+=2)swap(sta[i].fi,sta[i].se);
	rep(i,1,top)printf("%d %d\n",sta[i].fi,sta[i].se);
	return 0;
}