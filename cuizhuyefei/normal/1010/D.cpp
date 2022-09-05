#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 2030300;
int n;char t[N][5];bool ok[N],vis[N];
int fa[N],f[N],lc[N],rc[N];
int calc(int u){
	if(t[u][0]=='N')return !f[lc[u]];
	if(t[u][0]=='A')return f[lc[u]]&f[rc[u]];
	if(t[u][0]=='O')return f[lc[u]]|f[rc[u]];
	return f[lc[u]]^f[rc[u]];
}
void dfs(int u){
	if(lc[u])dfs(lc[u]);if(rc[u])dfs(rc[u]);
	if(t[u][0]!='I')f[u]=calc(u);
}
void DFS(int u){
	if(!ok[u])return;
	vis[u]=1;if(lc[u])DFS(lc[u]);if(rc[u])DFS(rc[u]);
}
int main() {
	read(n);
	rep(i,1,n){
		scanf("%s",t[i]);
		if(t[i][0]=='I')read(f[i]);
		else if(t[i][0]=='N')read(lc[i]);
		else read(lc[i]),read(rc[i]);
		fa[lc[i]]=fa[rc[i]]=i;
	}
	dfs(1);rep(i,1,n){
		f[i]^=1;ok[i]=calc(fa[i])!=f[fa[i]];f[i]^=1;
	//	printf("%d\n",ok[i]);
	}
	ok[1]=1;DFS(1);
	rep(i,1,n)if(t[i][0]=='I')printf("%d",f[1]^vis[i]);
	return 0;
}