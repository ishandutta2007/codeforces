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
const int N = 606000,mo=998244353;
int n,f[N][2][2];Vi e[N];
void add(int &x, ll y){x=(x+y)%mo;}
void dfs(int u, int fa){
	f[u][1][0]=1;
	rep(t,0,SZ(e[u])-1)if(e[u][t]!=fa){
		int v=e[u][t];dfs(e[u][t],u);
		int a[2][2];rep(i,0,1)rep(j,0,1)a[i][j]=f[u][i][j],f[u][i][j]=0;
		rep(i,0,1)rep(j,0,1){
			add(f[u][i][j],1LL*a[i][j]*(f[v][0][0]+f[v][0][1]));
			add(f[u][i][1],1LL*a[i][j]*(f[v][0][0]+f[v][0][1]));
		}
		rep(i,0,1)add(f[u][0][1],1LL*a[1][i]*(f[v][1][1]+f[v][1][0]));//y
		rep(i,0,1)rep(j,0,1)add(f[u][i][j],1LL*a[i][j]*f[v][1][0]);//n
	}
//	printf("%d:%d %d %d %d\n",u,f[u][0][0],f[u][0][1],f[u][1][0],f[u][1][1]);
}
int main() {
	read(n);rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	dfs(1,0);printf("%lld",(1LL*f[1][1][0]+f[1][0][0]+f[1][0][1])%mo);
	return 0;
}