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
const int N = 233333;
int rt,n,val[N],fa[N];Vi e[N];map<int,int>Map[N];
struct node{int x,y,z;}ans[N];int len;
void dfs(int u, int Fa){
	fa[u]=Fa;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa)dfs(e[u][i],u);
	val[u]=Map[u][Fa];
}
void find(int u,int fa, int &x){
	if(SZ(e[u])==1){x=u;}
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)find(e[u][i],u,x);
}
void dfs1(int u){
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa[u])dfs1(e[u][i]);
	if(SZ(e[u])==1){
		if(val[u]){
			ans[++len]=(node){u,rt,-val[u]};int x=-val[u];
			for(int d=u;d!=rt;d=fa[d])val[d]+=x;
		}
	}
	else{
		int le[4];int l=0,x=u;
		rep(i,0,SZ(e[x])-1)if(e[x][i]!=fa[x]&&l<2){l++;find(e[x][i],x,le[l]);}
		ans[++len]=(node){rt,le[1],-val[x]/2};
		ans[++len]=(node){rt,le[2],-val[x]/2};
		ans[++len]=(node){le[1],le[2],val[x]/2};
		int del=-val[x];
		for(int d=u;d!=rt;d=fa[d])val[d]+=del;
	}
}
int main() {
	read(n);rep(i,1,n-1){
		int u,v,w;read(u);read(v);read(w);e[u].pb(v);e[v].pb(u);Map[u][v]=Map[v][u]=w;
	}
	rep(i,1,n)if(SZ(e[i])==2){puts("NO");return 0;}
	puts("YES");
	rt=1;rep(i,1,n)if(SZ(e[i])==1)rt=i;
	dfs(rt,0);dfs1(rt);
	/*if(n==2)ans[++len]=(node){1,2,-Map[1][2]};
	else{
		int le[4];int l=0,x=e[rt][0];
		rep(i,0,SZ(e[x])-1)if(e[x][i]!=rt&&l<2){l++;find(e[x][i],x,le[l]);}
		ans[++len]=(node){1,le[1],-val[x]/2};
		ans[++len]=(node){1,le[2],-val[x]/2};
		ans[++len]=(node){le[1],le[2],val[x]/2};
	}*/
	rep(i,1,n)assert(!val[i]);
	printf("%d\n",len);
	rep(i,1,len)printf("%d %d %d\n",ans[i].x,ans[i].y,-ans[i].z);
	return 0;
}