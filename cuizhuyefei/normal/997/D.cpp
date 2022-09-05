#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 8040, mo = 998244353;
int k,f[N][77],g[N][77],F[77],G[77],fac[N],ifac[N];
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
int power(int a, int n){
	int res=1;
	while (n){
		if(n&1)res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
inline int inv(int a){return power(a,mo-2);}
int C(int n, int m){
	return m<0||m>n?0:1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo;
}
struct GG{
	int n,head[N],to[N],nxt[N],edgenum,dp1[N][77],dp2[N][77],fa[N];
	void addedge(int u, int v){
		to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;
	}
	void dfs1(int u, int Fa){
		fa[u]=Fa;
		L(i,u)if(to[i]!=Fa)dfs1(to[i],u);
		dp1[u][0]=1;if(Fa)dp2[u][0]=1;
		rep(i,2,k)rep(j,0,i-2){
			int tmp=0;L(e,u)if(to[e]!=Fa)add(tmp,dp1[to[e]][j]);
			dp1[u][i]=(dp1[u][i]+1LL*tmp*dp1[u][i-j-2])%mo;
		}
	}
	void dfs2(int u, int Fa){
		static int tmp[77];memset(tmp,0,sizeof(tmp));
		L(i,u)if(to[i]!=Fa)rep(j,0,k)add(tmp[j],dp1[to[i]][j]);
		rep(j,0,k)add(tmp[j],dp2[u][j]);
		L(e,u)if(to[e]!=Fa)rep(i,0,k)rep(j,0,i-2)
			dp2[to[e]][i]=(dp2[to[e]][i]+1LL*dp2[to[e]][i-j-2]*(tmp[j]-dp1[to[e]][j]+mo))%mo;
		L(i,u)if(to[i]!=Fa)dfs2(to[i],u);
	}
	inline void init(int f[N][77]){
		dfs1(1,0);dfs2(1,0);
		rep(u,1,n){
			f[u][0]=1;
			rep(i,1,k)rep(j,0,i-2){
				int tmp=dp2[u][j];L(e,u)if(to[e]!=fa[u])add(tmp,dp1[to[e]][j]);
				f[u][i]=(f[u][i]+1LL*tmp*f[u][i-j-2])%mo;
			//	if(u==2&&i==4)cerr<<tmp<<' '<<f[u][i-j-2]<<' '<<f[u][i]<<endl;
			}
		//	rep(i,0,k)cerr<<f[u][i]<<' ';cerr<<endl;
		//	rep(i,0,k)cerr<<dp1[u][i]<<' ';cerr<<endl;
		//	rep(i,0,k)cerr<<dp2[u][i]<<' ';cerr<<endl;
		}
	}
}g1,g2;
int main() { //freopen("1.in","r",stdin);
	read(g1.n);read(g2.n);read(k);int u,v;
	rep(i,1,g1.n-1){read(u);read(v);g1.addedge(u,v);g1.addedge(v,u);}
	rep(i,1,g2.n-1){read(u);read(v);g2.addedge(u,v);g2.addedge(v,u);}
	g1.init(f);g2.init(g);
	rep(i,0,k)rep(j,1,g1.n)(F[i]+=f[j][i])%=mo;
	rep(i,0,k)rep(j,1,g2.n)(G[i]+=g[j][i])%=mo;
	int mx=1000; fac[0]=1;rep(i,1,mx)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[mx]=inv(fac[mx]);per(i,mx-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	ll res=0;
	rep(i,0,k)res+=1LL*C(k,i)*F[i]%mo*G[k-i]%mo;
	cout<<res%mo;
	return 0;
}