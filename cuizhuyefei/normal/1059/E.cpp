#include<bits/stdc++.h>
#define L(i,u) for(int i=head[u];i;i=nxt[i])
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long ll;
const int N = 233333;
int n,k,w[N],head[N],to[N],nxt[N],edgenum,dep[N],fa[N][17],dy[N],res;ll s,val[N][17];
int d[N],pos[N];
void add(int u, int v){to[++edgenum]=v;nxt[edgenum]=head[u];head[u]=edgenum;}
void DFS(int u, int Dep){
	dep[u]=Dep;L(i,u)DFS(to[i],Dep+1);
}
void init(){
	rep(j,1,16)rep(i,1,n)if(dep[i]>=(1<<j))
		fa[i][j]=fa[fa[i][j-1]][j-1],val[i][j]=val[i][j-1]+val[fa[i][j-1]][j-1];
	rep(i,1,n){
		int u=i;ll v=s;
		per(j,16,0)if(dep[u]>=(1<<j)&&dep[i]-(dep[u]-(1<<j))<=k&&v>=val[u][j])
			v-=val[u][j],u=fa[u][j];
		pos[i]=dep[u]?dep[u]+1:(dep[i]+1<=k&&v>=w[u]?0:1);//printf("%d:%d\n",i,pos[i]);
	}
}
void dfs(int u){
	d[u]=n+1;L(i,u)dfs(to[i]),d[u]=min(d[u],d[to[i]]);
	if(d[u]>dep[u])res++,d[u]=pos[u];
}
int main(){
	read(n);read(k);scanf("%lld",&s);
	rep(i,1,n)read(w[i]),val[i][0]=w[i];rep(i,2,n)read(fa[i][0]),add(fa[i][0],i);
	rep(i,1,n)if(w[i]>s){puts("-1");return 0;}
	DFS(1,0);init();dfs(1);
	printf("%d",res);return 0;
}