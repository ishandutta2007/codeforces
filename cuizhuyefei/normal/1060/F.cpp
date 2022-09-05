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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 123;const double eps=1e-14;
int n,head[N],to[N],nxt[N],edgenum;
void add(int u, int v){to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;}
double C[N][N],f[N][N];int sz[N];
void dfs(int u, int fa){
	f[u][0]=1;sz[u]=1;L(i,u)if(to[i]!=fa){
		dfs(to[i],u);static double a[N];rep(j,0,sz[u]+sz[to[i]])a[j]=0;
		rep(j,0,sz[u])rep(k,0,sz[to[i]])a[j+k]+=f[u][j]*f[to[i]][k];
		sz[u]+=sz[to[i]];rep(j,0,sz[u])f[u][j]=a[j];
	}
	if(fa){
		static double a[N];rep(j,0,sz[u])a[j]=0;
		rep(j,0,sz[u]-1)a[j+1]+=f[u][j];//w
		rep(j,0,sz[u]-1)rep(k,0,j)a[k]+=f[u][j]*0.5*C[j][k]/(sz[u]-j)/C[sz[u]-k][j-k];//b
		rep(j,0,sz[u])f[u][j]=a[j];
	}
//	printf("%d:%.2lf %.2lf %.2lf\n",u,f[u][0],f[u][1],f[u][2]);
}
double solve(int rt){
	memset(f,0,sizeof(f));dfs(rt,0);return f[rt][0];
}
int main() {
	read(n);rep(i,1,n-1){int u,v;read(u);read(v);add(u,v);add(v,u);}
	C[0][0]=1;rep(i,1,n){
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	rep(i,1,n)printf("%.9lf\n",solve(i));
	return 0;
}