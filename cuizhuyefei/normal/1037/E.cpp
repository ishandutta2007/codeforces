#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
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
const int N = 666666;
int n,m,k,U[N],V[N],deg[N],ans[N],q[N],now,f,r;
Vi e[N];
void bfs(){
	while(f!=r){
		now--;int u=q[f++];
		per(i,SZ(e[u])-1,0)if(deg[e[u][i]]>=k){
			deg[e[u][i]]--;if(deg[e[u][i]]<k)q[r++]=e[u][i];
		}
	}
}
int main() {
	read(n);read(m);read(k);now=n;
	rep(i,1,m){
		int u,v;read(u);read(v);U[i]=u;V[i]=v;
		e[u].pb(v);e[v].pb(u);deg[u]++;deg[v]++;
	}
	f=1,r=1;rep(i,1,n)if(deg[i]<k)q[r++]=i;
	bfs();per(i,m,1){
		ans[i]=now;if(deg[U[i]]>=k&&deg[V[i]]>=k){
			deg[U[i]]--;deg[V[i]]--;
			if(deg[U[i]]==k-1)q[r++]=U[i];
			if(deg[V[i]]==k-1)q[r++]=V[i];
		}
		e[U[i]].pop_back();e[V[i]].pop_back();
		bfs();
	}
	rep(i,1,m)printf("%d\n",ans[i]);
	return 0;
}