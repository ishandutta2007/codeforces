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
const int N = 266666,mo=1e9+7;
int res,n,dep[N],fa[N][17];ll val[N][17];Vi e[N];
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
void dfs(int u, int Fa, int Dep){
	fa[u][0]=Fa;dep[u]=Dep;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa)
		dfs(e[u][i],u,Dep+1);
}
int main() {
	read(n);rep(i,1,n)read(val[i][0]);
	rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	dfs(1,0,1);
	rep(j,1,16)rep(i,1,n)
		fa[i][j]=fa[fa[i][j-1]][j-1],
		val[i][j]=gcd(val[i][j-1],val[fa[i][j-1]][j-1]);
	rep(s,1,n){
		ll x=val[s][0];int u=s;
		while(u){
		//	cerr<<s<<' '<<u<<' '<<x<<endl;
			int ori=dep[u];
			per(i,16,0)if(dep[u]>=(1<<i)&&(x?val[u][i]%x==0:val[u][i]==0))
				u=fa[u][i];
			res=(res+1LL*x%mo*(ori-dep[u]))%mo;
			x=gcd(x,val[u][0]);
		}
	}
	cout<<res;
	return 0;
}