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
const int N = 266666;
int n,m,sta[N],dfn[N],deg[N],col[N],low[N],top,num,cnt;bool insta[N];
Vi dot[N],e[N],ne[N];
void tarjan(int u){
	dfn[u]=low[u]=++num;
	sta[++top]=u;insta[u]=1;
	for(int v:e[u])if(!dfn[v]){
		tarjan(v);umin(low[u],low[v]);
	}
	else if(insta[v])umin(low[u],dfn[v]);
	if(dfn[u]==low[u]){
		cnt++;
		while(top){
			int x=sta[top--];insta[x]=0;
			dot[cnt].pb(x);col[x]=cnt;if(x==u)break;
		}
	}
}
int ask(int u, int v){
	printf("? %d %d\n",u,v);fflush(stdout);
	int x;read(x);return x;
}
void era(int u){
	for(int v:ne[u])if(!--deg[v])sta[++top]=v;
}
int main() {
	read(n);read(m);
	while(m--){
		int u,v;read(u);read(v);e[u].pb(v);
	}
	rep(i,1,n)if(!dfn[i])tarjan(i);
	rep(u,1,n)for(int v:e[u])if(col[u]!=col[v])ne[col[u]].pb(col[v]),deg[col[v]]++;
	top=0;
	rep(i,1,cnt)if(!deg[i])sta[++top]=i;
	while(top>1){
		int x=sta[top--];int y=sta[top--];
		while(SZ(dot[x])&&SZ(dot[y])){
			if(ask(dot[x].back(),dot[y].back()))dot[y].pop_back();
			else dot[x].pop_back();
		}
		if(SZ(dot[x]))sta[++top]=x,era(y);
		else sta[++top]=y,era(x);
	}
	printf("! %d\n",dot[sta[top]].back());
	return 0;
}