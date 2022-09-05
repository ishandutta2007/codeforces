#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define ALL(x) x.begin(),x.end()
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
const int N = 150005,M = 500,mo=998244353;
int n,q,fa[N],dl[N],dr[N],idfn[N],v[N],dep[N],invn,num,lzy[N],sz[N],xs[N];Vi e[N],dp[N];
int bel[2*N/M+3][N];
void dfs1(int u, int Fa, int Dep){
	fa[u]=Fa;dl[u]=++num;sz[u]=1;idfn[num]=u;dep[u]=Dep;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa){
		dfs1(e[u][i],u,Dep+1);sz[u]+=sz[e[u][i]];
	}
	dr[u]=num;
}
inline void Add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
//inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
inline void mdy(int p, int x){while(p<=n)Add(v[p],x),p+=p&-p;}
inline int qry(int p){int r=0;while(p)Add(r,v[p]),p-=p&-p;return r;}
inline void modify(int l, int r, int x){
	if(l<=r)mdy(l,x),mdy(r+1,mo-x);
}
bool cmp1(int x, int y){return dep[x]<dep[y];}
int main() {
	read(n);read(q);
	rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	dfs1(1,0,0);invn=power(n,mo-2);
	rep(u,1,n)sort(ALL(e[u]),cmp1);
	rep(u,1,n)rep(i,0,SZ(e[u])-1)
		dp[u].pb(1ll*(n-(e[u][i]==fa[u]?n-sz[u]:sz[e[u][i]]))*invn%mo);
	static int s[N];int sz=0;
	rep(u,1,n)if(SZ(e[u])>M){
		s[++sz]=u;if(fa[u])assert(e[u][0]==fa[u]);
		rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa[u])rep(j,dl[e[u][i]],dr[e[u][i]])
			bel[sz][idfn[j]]=i;
	}
	while(q--){
		int op,v,d;read(op);read(v);
		if(op==2){
			int res=(qry(dl[v])+lzy[v])%mo;
			rep(i,1,sz)
				if(s[i]==v)Add(res,xs[s[i]]);
				else res=(res+1ll*xs[s[i]]*dp[s[i]][bel[i][v]])%mo;-
			printf("%d\n",res%mo);
		}
		else{
			read(d);
			if(SZ(e[v])>M)Add(xs[v],d);
			else{
				Add(lzy[v],d);
				rep(i,0,SZ(e[v])-1)if(e[v][i]!=fa[v])modify(dl[e[v][i]],dr[e[v][i]],1ll*d*dp[v][i]%mo);
				else modify(1,dl[v]-1,1ll*d*dp[v][i]%mo),modify(dr[v]+1,n,1ll*d*dp[v][i]%mo);
			}
		}
	}
	return 0;
}