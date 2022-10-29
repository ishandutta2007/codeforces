#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 105
#define maxm 200005
#define ll long long 
using namespace std;

int n,m,i,j,k,du[maxn],S,T;
int em,e[maxm],nx[maxm],ls[maxn],ec[maxm],cost[maxm];
ll ans;

void insert(int x,int y,int z,int c){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em; ec[em]=z; cost[em]=c;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em; ec[em]=0; cost[em]=-c;
}

int dis[maxn],d[maxn],vis[maxn];
int bfs(){
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	int t=0,w=1; d[1]=S,dis[S]=0,vis[S]=1;
	while (t<w){
		int x=d[++t]; vis[x]=0;
		for(int i=ls[x];i;i=nx[i]) if (ec[i]&&dis[x]+cost[i]<dis[e[i]]){
			dis[e[i]]=dis[x]+cost[i];
			if (!vis[e[i]])
				vis[e[i]]=1,d[++w]=e[i];
		}
	}
	return dis[T]<1e9;
}

int dfs(int x,int p){
	if (x==T) return p;
	int res=p; vis[x]=1;
	for(int i=ls[x];i;i=nx[i]) if (ec[i]&&dis[x]+cost[i]==dis[e[i]]&&!vis[e[i]]){
		int tmp=dfs(e[i],min(ec[i],res));
		res-=tmp,ec[i]-=tmp,ec[i^1]+=tmp;
		if (!res) break;
	}
	return p-res;
}

void maxflow(){
	while (bfs()){
		memset(vis,0,sizeof(vis));
		ans+=1ll*dis[T]*dfs(S,1e9);
	}
	printf("%lld\n",ans);
}

int main(){
	scanf("%d%d",&n,&m),em=1;
	for(i=1;i<=m;i++){
		int x,y,z,w; scanf("%d%d%d%d",&x,&y,&z,&w);
		if (x==n) x=1; if (y==n) y=1;
		ans+=max(w-z,0);
		if (x==y) continue;
		du[x]+=w,du[y]-=w;
		if (w>z) {
			insert(y,x,w-z,0);
			insert(x,y,2e9,2);
			insert(y,x,z,1);
		} else{
			insert(x,y,z-w,1);
			insert(y,x,w,1);
			insert(x,y,2e9,2);
		}
	}
	S=n,T=n+1;
	for(i=1;i<n;i++) if (du[i]>0) insert(i,T,du[i],0);
	else if (du[i]<0) insert(S,i,-du[i],0);
	maxflow();
}