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
const int N = 266666;
int n,m,fa[N],dep[N],dl[N],dr[N],num,dp[N];Vi e[N];Pii a[N];int sz;
void dfs1(int u, int Fa, int Dep){
	dep[u]=Dep;fa[u]=Fa;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa)
		if(!dep[e[u][i]])dfs1(e[u][i],u,Dep+1);//,cerr<<u<<' '<<e[u][i]<<endl;
		else if(dep[e[u][i]]<dep[u])a[++sz]=Pii(u,e[u][i]);
}
void dfs2(int u, int Fa){
	dl[u]=++num;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa&&dep[e[u][i]]==dep[u]+1)
		dfs2(e[u][i],u),dp[u]+=dp[e[u][i]];
	dr[u]=num;
}
bool iszx(int u,int v){return dl[u]<=dl[v]&&dr[u]>=dl[v];}
int getlca(int u, int v){
	while(u!=v){
		if(dep[u]<dep[v])swap(u,v);u=fa[u];
	}
	return u;
}
Vi getpath(int u, int v){
	Vi res;bool rev=0;if(dep[u]<dep[v])rev=1,swap(u,v);
	while(1){res.pb(u);if(u==v)break;u=fa[u];}
	if(rev)reverse(res.begin(),res.end());
	return res;
}
void print(Vi res){
	printf("%d ",SZ(res));rep(i,0,SZ(res)-1)printf("%d ",res[i]);puts("");
}
int main() {
	read(n);read(m);
	rep(i,1,m){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	rep(i,1,n)if(!dep[i])dfs1(i,0,1);
	rep(i,1,sz)dp[a[i].fi]++,dp[a[i].se]--;
	rep(i,1,n)if(dep[i]==1)dfs2(i,0);
//	rep(u,1,n)cerr<<u<<' '<<dl[u]<<' '<<dr[u]<<endl;	
	rep(u,1,n)if(dp[u]>=2){
		puts("YES");Pii b[3];int cnt=0;
		rep(i,1,sz)if(iszx(u,a[i].fi)&&iszx(a[i].se,fa[u])&&cnt<2)b[++cnt]=a[i];
	//	cerr<<u<<' '<<cnt<<endl;
		assert(cnt==2);
		Pii x=b[1],y=b[2];if(dep[x.fi]<dep[y.fi])swap(x,y);Vi res,tmp;
		if(dep[y.se]>dep[x.se]){
			u=getlca(x.fi,y.fi);int v=y.se;
			res.clear();res=getpath(u,v);print(res);
			res=getpath(u,y.fi);res.pb(v);print(res);
			res=getpath(u,x.fi);tmp=getpath(x.se,v);rep(i,0,SZ(tmp)-1)res.pb(tmp[i]);print(res);
			/*res.clear();res.pb(y.fi);res.pb(y.se);print(res);
			res.clear();res=getpath(y.fi,y.se);print(res);
			res.clear();res=getpath(x.fi,y.fi);reverse(res.begin(),res.end());
			tmp=getpath(y.se,x.se);reverse(tmp.begin(),tmp.end());
			rep(i,0,SZ(tmp)-1)res.pb(tmp[i]);print(res);*/
		}
		else{
			u=getlca(x.fi,y.fi);int v=x.se;
			res=getpath(u,v);print(res);
			res=getpath(u,y.fi);tmp=getpath(y.se,v);rep(i,0,SZ(tmp)-1)res.pb(tmp[i]);print(res);
			res=getpath(u,x.fi);res.pb(v);print(res);
			/*res=getpath(y.fi,x.se);print(res);
			res.clear();res.pb(y.fi);tmp=getpath(x.se,y.se);per(i,SZ(tmp)-1,0)res.pb(tmp[i]);print(res);
			res.clear();res=getpath(x.fi,y.fi);reverse(res.begin(),res.end());res.pb(x.se);print(res);*/
		}
		return 0;
	}
	puts("NO");
	return 0;
}