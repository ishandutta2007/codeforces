#include<bits/stdc++.h>
using namespace std;
const int MAX_N=3005;
typedef long long ll;
struct Graph{
	struct Edge{ int to,nxt; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y){
		edge[++top]=(Edge){y,head[x]};
		head[x]=top;
	}
}G;
int n,sz[3005][3005],fa[3005][3005];
ll f[3005][3005];
int dis[3005][3005];
vector<pair<int,int> > g[3005];
void dfs(int x,int pre,int o,int dist){
	g[dist].push_back(make_pair(x,o));
	dis[o][x]=dist;
	fa[o][x]=pre;
	sz[o][x]=1;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			dfs(y,x,o,dist+1);
			sz[o][x]+=sz[o][y];
		}
	}
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
	for(int x=1;x<=n;++x)
		dfs(x,0,x,0);
	ll ans=0;
	for(int i=1;i<=n;++i)
		for(auto e:g[i]){
			int x=e.first,y=e.second;
			f[x][y]=max(f[x][fa[x][y]],f[y][fa[y][x]])
				+1ll*sz[x][y]*sz[y][x];
			ans=max(ans,f[x][y]);
		}
	printf("%lld\n",ans);
	return 0;
}