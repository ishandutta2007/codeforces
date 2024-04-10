#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 500500;
int n,m,fa[N][20],dep[N],bj[N];Vi e[N];
void GG(){puts("-1");exit(0);}
void dfs1(int u, int Fa, int Dep){
	fa[u][0]=Fa;dep[u]=Dep;
	for(int v:e[u])if(v!=Fa)dfs1(v,u,Dep+1);
}
int kthfa(int u, int del){per(i,19,0)if(del>>i&1)u=fa[u][i];return u;}
int getlca(int u, int v){
	if(dep[u]<dep[v])swap(u,v);int del=dep[u]-dep[v];
	per(i,19,0)if(del>>i&1)u=fa[u][i];
	if(u==v)return u;
	per(i,19,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
vector<Pii>cons[N];int dfn[N],num,col[N];Vi d;vector<Vi>f[N];
void getcol(int u, int c, int tar){
	col[u]=c;d.pb(u);
	for(auto x:cons[u])if(dfn[x.fi]==tar)
		if(col[x.fi]==-1)getcol(x.fi,c^x.se,tar);
		else if(col[x.fi]!=(col[u]^x.se))GG();
}
void dfs2(int u, int Fa){
	for(int v:e[u])if(v!=Fa)dfs2(v,u),bj[u]+=bj[v];
	if(bj[u])cons[u].pb(mp(Fa,0)),cons[Fa].pb(mp(u,0));
	Vi dot;dfn[u]=u,dot.pb(u);
	for(int v:e[u])if(v!=Fa)dfn[v]=u,dot.pb(v);
	for(int x:dot)col[x]=-1;
	for(int x:dot)if(col[x]==-1){
		d.clear();getcol(x,0,u);f[u].pb(d);
	}
}
int mid;bool gg;int dp[N],ans[N];
void upd(Pii &s, Pii a){s=mp(max(s.fi,a.fi),min(s.se,a.se));}
void dfs(int u, int Fa){
	if(gg)return;
	for(int v:e[u])if(v!=Fa)dfs(v,u);
	Pii jiao(0,mid-(Fa>0)),sub(mid/2+1,mid/2);
	for(int x:f[u][0])if(x!=u){
		if(col[x]==0)umax(jiao.fi,dp[x]);else umin(jiao.se,mid-dp[x]-1);
	}
	for(auto a:f[u])if(a[0]!=f[u][0][0]){
		int l=0,r=0;
		for(int x:a)if(col[x]==0)umax(l,dp[x]);else umax(r,dp[x]);
		if(l>r)swap(l,r);
		upd(jiao,mp(l,mid-1-l));
		if(mid-r<=r-1){
			if(sub.fi<=sub.se)umax(sub.se,r-1),umin(sub.fi,mid-r);
			else sub=mp(mid-r,r-1);
		}
	}
	dp[u]=-1;
	if(jiao.fi<=jiao.se){
		if(sub.fi>sub.se||sub.fi>jiao.fi||sub.se<jiao.fi)dp[u]=jiao.fi;
		else if(sub.se+1<=jiao.se)dp[u]=sub.se+1;
	}
	if(dp[u]==-1)gg=1;dp[u]++;
//	if(mid==2)printf("%d-->%d\n",u,dp[u]);
}

int dir[N];
void dfs3(int u, int Fa, bool rev){
//	for(auto a:f[u]){for(int x:a)printf("%d ",x);printf("  :%d\n",u);}
	
	for(int x:f[u][0])if(x!=u){
		dir[x]=col[x];//if(col[x]==0)dir[x]=1;
	}
	for(auto a:f[u])if(a[0]!=f[u][0][0]){
		int l=0,r=0;
		for(int x:a)if(col[x]==0)umax(l,dp[x]);else umax(r,dp[x]);
		bool flag=0;if(dp[u]-1>=l&&dp[u]-1<=mid-1-r)flag=0;else flag=1;
		for(int x:a)dir[x]=col[x]^flag;
	}
	for(int x:e[u])if(x!=Fa)dir[x]^=rev;
//	printf("dp %d %d\n",u,dp[u]);
//	for(int x:e[u])if(x!=Fa)printf("dir %d = %d\n",x,dir[x]);
	for(int x:e[u])if(x!=Fa&&dir[x]==0)dfs3(x,u,0),umax(ans[u],ans[x]);
	ans[u]++;
	for(int x:e[u])if(x!=Fa&&dir[x]==1)umax(ans[x],ans[u]),dfs3(x,u,1);
//	if(1)printf("qaq %d %d %d %d\n",u,ans[u],dp[u],rev);//assert(ans[u]<=dp[u]);
}
int main() {
	read(n);read(m);
	rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	dfs1(1,0,0);
	rep(j,1,19)rep(i,1,n)fa[i][j]=fa[fa[i][j-1]][j-1];
	rep(i,1,m){
		int u,v;read(u);read(v);int l=getlca(u,v),x=0,y=0;
		if(dep[u]>dep[l])bj[u]++,bj[x=kthfa(u,dep[u]-dep[l]-1)]--;
		if(dep[v]>dep[l])bj[v]++,bj[y=kthfa(v,dep[v]-dep[l]-1)]--;
		if(dep[u]>dep[l]&&dep[v]>dep[l]){
			cons[x].pb(mp(y,1));cons[y].pb(mp(x,1));
		}
	}
	dfs2(1,0);
//	rep(i,1,n)printf("%d ",col[i]);puts("");
	int L=1,R=n;
	while(L<R){
		mid=(L+R)>>1;
		gg=0;dfs(1,0);
		if(gg)L=mid+1;else R=mid;
	}
	mid=L;gg=0;dfs(1,0);dfs3(1,0,0);
	printf("%d\n",L);
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}