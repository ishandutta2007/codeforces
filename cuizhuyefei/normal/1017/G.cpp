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
const int N = 102000,M=500;
int n,q,fa[N],op[N],X[N],dep[N],dfn[N],c[N];Vi e[N],lk[N];
int col[N],clr[N],need[N],now[N];
void build(int u, int lst, int cnt){
	if(lst&&dfn[u])e[lst].pb(u),need[u]=cnt;
	if(u==1||dfn[u])lst=u,cnt=0;
	rep(i,0,SZ(lk[u])-1)build(lk[u][i],lst,cnt+(!c[u]));
}
void getblack(int u){
	col[u]=1;now[u]++;
	rep(i,0,SZ(e[u])-1)if(now[u]>need[e[u][i]])getblack(e[u][i]);
}
void getwh(int u){
	clr[u]=1;now[u]=0;col[u]=0;
	rep(i,0,SZ(e[u])-1)getwh(e[u][i]),need[e[u][i]]=dep[e[u][i]]-dep[u];
}
void rebuild(int u, int cnt, bool ok){
//	printf("dfs %d %d\n",u,cnt);
	if(dfn[u])cnt=now[u];ok|=clr[u];
	if(!ok&&cnt&&!c[u])c[u]=1,cnt--;
	if(ok){c[u]=0;if(cnt)cnt--,c[u]=1;}
	rep(i,0,SZ(lk[u])-1)rebuild(lk[u][i],cnt,ok);
}
int main() {
	read(n);read(q);
	rep(i,2,n)read(fa[i]),lk[fa[i]].pb(i),dep[i]=dep[fa[i]]+1;
	rep(i,1,q)read(op[i]),read(X[i]);
	for(int l=1;l<=q;l++){
		int r=min(q,l+M);
		rep(i,1,n)now[i]=need[i]=clr[i]=0,col[i]=c[i],e[i].clear();
		rep(i,l,r)dfn[X[i]]=1;
		build(1,0,0);
		rep(i,l,r)//xushu is a good thing!!
			if(op[i]==1)getblack(X[i]);
			else if(op[i]==2)getwh(X[i]);
			else printf("%s\n",col[X[i]]?"black":"white");
			
	//	rep(i,1,n)printf("%d:%d %d\n",i,now[i],clr[i]);puts("");
		rebuild(1,0,0);
	//	rep(i,1,n)printf("%d:%d\n",i,c[i]);puts("");
		rep(i,l,r)dfn[X[i]]=0;l=r;//,c[X[i]]=col[X[i]];
	}
	return 0;
}