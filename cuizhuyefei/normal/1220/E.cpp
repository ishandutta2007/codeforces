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
const int N = 666666;
ll ext,res,n,m,w[N];Vi e[N],newe[N];
int top[N],s,dep[N],fa[N],cnt[N],dp[N];
void Mrk(int x){
	dp[x]=1;
}
void dfs1(int u, int fa){
	rep(i,0,SZ(newe[u])-1)if(newe[u][i]!=fa)
		dfs1(newe[u][i],u),dp[u]|=dp[newe[u][i]];
	if(dp[u])ext+=w[u];
}
void getans(int u, int fa, ll cur){
	umax(res,cur);
	rep(i,0,SZ(newe[u])-1)if(newe[u][i]!=fa)
		getans(newe[u][i],u,cur+(!dp[newe[u][i]]?w[newe[u][i]]:0));
}
int find(int x){return top[x]==x?x:top[x]=find(top[x]);}
void merge(int u, int v){
	u=find(u);v=find(v);
	if(u!=v)top[u]=v,w[v]+=w[u],cnt[v]+=cnt[u];
}
void Mergeline(int u, int v){
	while(1){
		u=find(u);
		if(dep[v]<dep[u])merge(u,find(fa[u])),u=fa[u];
		else break;
	}
}
void dfs(int u, int Fa, int Dep){
	fa[u]=Fa;dep[u]=Dep;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa)
		if(!dep[e[u][i]]){dfs(e[u][i],u,Dep+1);}
		else if(dep[e[u][i]]<dep[u]){
			Mergeline(u,e[u][i]);
		}
}
int main() {
	read(n);read(m);
	rep(i,1,n)read(w[i]),top[i]=i,cnt[i]=1;
	rep(i,1,m){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	read(s);dfs(1,0,1);
	rep(u,1,n)rep(i,0,SZ(e[u])-1)if(find(u)!=find(e[u][i]))
		newe[find(u)].pb(find(e[u][i]));
//	rep(i,1,n)if(find(i)==i)cerr<<i<<' '<<w[i]<<endl;
	Mrk(s);rep(i,1,n)if(find(i)==i&&cnt[i]>1)Mrk(i);
	dfs1(find(s),0);getans(find(s),0,ext);cout<<res;
	return 0;
}