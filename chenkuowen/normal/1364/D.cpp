#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
struct Graph{
	struct Edge{ int to,nxt; };
	vector<Edge> edge;
	vector<int> head;
	Graph(int n=0,int m=0){
		edge.clear(); edge.reserve(m);
		head=vector<int>(n+1,-1);
	}
	inline void add(int x,int y){
		edge.push_back((Edge){y,head[x]});
		head[x]=edge.size()-1;
	}
}G;
int dfn[N],dep[N],fa[N],ti=0;
int len=(int)1e9,sx,sy;
bool vis[N];
void dfs(int x,int pre){
	dep[x]=dep[pre]+1; fa[x]=pre;
	vis[x]=1; dfn[x]=++ti;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			if(dfn[y]==0){
				dfs(y,x);
				if(vis[y]) vis[x]=0;
			}else{
				if(dfn[y]<dfn[x]){
					if(dep[x]-dep[y]<len){
						len=dep[x]-dep[y],sx=x,sy=y;
					}
				}
			}
		}
	}
}
int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	G=Graph(n,m);
	for(int i=0;i<m;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
	dfs(1,0);
	if(len==(int)1e9){
		vector<int> ans;
		for(int i=1;i<=n;++i)
			if(vis[i]) ans.push_back(i);
		puts("1");
		for(int i=0;i<(k+1>>1);++i)
			printf("%d ",ans[i]);
		puts("");
		return 0;
	}else{
		vector<int> ring;
		for(int x=sx;x!=fa[sy];x=fa[x])
			ring.push_back(x);
		if(ring.size()<=k){
			puts("2");
			printf("%d\n",int(ring.size()));
			for(auto x:ring) printf("%d ",x); puts("");
		}else{
			vector<int> ans;
			for(int i=0;i+1<ring.size();i+=2)
				ans.push_back(ring[i]);
			puts("1");
			for(int i=0;i<(k+1>>1);++i)
				printf("%d ",ans[i]);
			puts("");
		}
	}
	return 0;
}