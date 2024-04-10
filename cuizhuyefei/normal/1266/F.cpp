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
const int N = 1066666;
int n,ans[N],f[N],g[N],Fa[N],val[N],mx,dfn[N],xm[N];Vi e[N],a[N];Vi pos[N];
void dfs1(int u, int fa){
	Fa[u]=fa;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)dfs1(e[u][i],u),umax(f[u],f[e[u][i]]+1);
}
void dfs2(int u, int fa){
	int mx=-1e9,mx1=-1e9;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)
		if(f[e[u][i]]>mx){mx1=mx;mx=f[e[u][i]];}
		else if(f[e[u][i]]>mx1)mx1=f[e[u][i]];
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)g[e[u][i]]=1+max(g[u],1+(mx==f[e[u][i]]?mx1:mx));
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)dfs2(e[u][i],u),a[u].pb(f[e[u][i]]+1);
	if(fa)a[u].pb(g[u]);
}
int main() {
	read(n);rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	dfs1(1,0);dfs2(1,0);
	rep(i,1,n)sort(a[i].begin(),a[i].end());//,reverse(a[i].begin(),a[i].end());
	rep(i,1,n)rep(j,0,SZ(a[i])-1)pos[a[i][j]].pb(i);
	int case1=0;
	per(i,n,1){
		rep(j,0,SZ(pos[i])-1){
			a[pos[i][j]].pop_back(),val[pos[i][j]]++,umax(mx,val[pos[i][j]]);
			int u=pos[i][j];
		//	if(2*i==4&&val[u]+max(xm[u],val[Fa[u]])-2==3)printf("%d %d\n",val[u],max(xm[u],val[Fa[u]]));
			umax(case1,val[u]+max(xm[u],val[Fa[u]])-2);umax(xm[Fa[u]],val[u]);
		}
	//	if(2*i==4){rep(j,1,n)printf("%d:%d\n",j,val[j]);}
		umax(ans[2*i],max(mx,case1));
		Vi cur;
		rep(j,0,SZ(pos[i-1])-1)if(dfn[pos[i-1][j]]!=i)dfn[pos[i-1][j]]=i,cur.pb(pos[i-1][j]);
		rep(j,0,SZ(cur)-1)val[cur[j]]++,umax(mx,val[cur[j]]);
		ans[2*i-1]=mx;
		rep(j,0,SZ(cur)-1)val[cur[j]]--;
	}
	rep(i,1,n)umax(ans[1],SZ(e[i])+1);
	
	rep(i,1,n)printf("%d ",max(ans[i],1));
	return 0;
}