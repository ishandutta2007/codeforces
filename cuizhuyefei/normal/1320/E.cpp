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
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 577777;
int n,q,fa[18][N],dep[N],dl[N],dr[N],num,s[N];Vi e[N];
void dfs11(int u, int Fa, int Dep){
	fa[0][u]=Fa;dep[u]=Dep;dl[u]=++num;
	for(int v:e[u])if(v!=Fa)dfs11(v,u,Dep+1);
	dr[u]=num;
}
int getlca(int u, int v){
	if(dep[u]<dep[v])swap(u,v);int del=dep[u]-dep[v];
	rep(i,0,17)if(del>>i&1)u=fa[i][u];
	if(u==v)return u;
	per(i,17,0)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
int getdis(int u, int v){return dep[u]+dep[v]-2*dep[getlca(u,v)];}
bool cmp(int x, int y){return dl[x]<dl[y];}

int top[N],id[N],sd[N],bel[N],jidi[N];//Vi e[N];

Vi solve1(int *s, int len, int *fa){
			static int sta[N];int top=0;Vi ext;
			rep(i,1,len){
				int lca=getlca(sta[top],s[i]);
				if(!top||lca==sta[top])fa[s[i]]=sta[top],sta[++top]=s[i];
				else{
					while(top>1&&dep[sta[top-1]]>=dep[lca])top--;
					if(sta[top]==lca)fa[s[i]]=sta[top],sta[++top]=s[i];
					else{
						fa[sta[top]]=lca;top--;ext.pb(lca);
						fa[lca]=sta[top];sta[++top]=lca;
						fa[s[i]]=sta[top];sta[++top]=s[i];
					}
				}
			}
		return ext;
}
void upd(int u, int x){
	if(!x)return;
	if(!id[u]){id[u]=x;return;}
	int y=id[u];
	if(mp((getdis(u,jidi[x])+sd[x]-1)/sd[x],x)<mp((getdis(u,jidi[y])+sd[y]-1)/sd[y],y))id[u]=x;
}
void dfs1(int u){
	for(int v:e[u])dfs1(v),upd(u,id[v]);
	
}
void dfs2(int u){
	for(int v:e[u])upd(v,id[u]),dfs2(v);
}
int main() {
	read(n);
	rep(i,1,n-1){
		int u,v;read(u);read(v);
		e[u].pb(v);e[v].pb(u);
	}
	dfs11(1,0,0);rep(j,1,17)rep(i,1,n)
		fa[j][i]=fa[j-1][fa[j-1][i]];
	rep(i,1,n)e[i].clear();
	read(q);while(q--){
		int k,m;read(k);read(m);static int Q[N];
		int len=0;
		rep(i,1,k){
			int v,S;read(v);read(S);
			id[v]=i;s[++len]=v;jidi[i]=v;sd[i]=S;
		}
		rep(i,1,m){
			read(Q[i]);s[++len]=Q[i];
		}
		sort(s+1,s+len+1,cmp);len=unique(s+1,s+len+1)-s-1;
		Vi ext=solve1(s,len,top);
		for(auto x:ext)s[++len]=x;
		int Rt=0;rep(i,1,len)if(top[s[i]])e[top[s[i]]].pb(s[i]);else Rt=s[i];
		dfs1(Rt);dfs2(Rt);
		rep(i,1,m)printf("%d ",id[Q[i]]);puts("");
		rep(jj,1,len){
			int i=s[jj];
			top[i]=0,e[i].clear(),id[i]=sd[i]=0;
		}
	}
	return 0;
}