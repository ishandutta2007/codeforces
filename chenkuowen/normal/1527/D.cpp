#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+2e5;
bool vis[N];
struct Graph{
	struct Edge{ int to,nxt; };
	vector<int> head;
	vector<Edge> edge;
	Graph(int n=0,int m=0){
		head=vector<int>(n+1,-1);
		edge.clear(); edge.reserve(m);
	}
	inline void add(int x,int y){
		edge.push_back((Edge){y,head[x]});
		head[x]=edge.size()-1;
	}
}G;
int fa[N],sz[N];
void dfs(int x,int pre){
	fa[x]=pre; vis[x]=0; sz[x]=1;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y==pre) continue;
		dfs(y,x); sz[x]+=sz[y];
	}
}
deque<int> path;
ll calc(){
	if(path.size()==1){
		int s=1; ll ret=0;
		for(int j=G.head[1];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			ret+=1ll*s*sz[y];
			s+=sz[y];
		}
		return ret;
	}
//	for(auto x:path) printf("[%d]",x); puts("");
//	exit(0);
	int lsz=path[0]==1?sz[1]-sz[path[1]]:sz[path[0]];
	int rsz=path[path.size()-1]==1?sz[1]-sz[path[path.size()-2]]:sz[path[path.size()-1]];
	return 1ll*lsz*rsz;
}
bool choose(int x){
	vector<int> g;
	for(;!vis[x]&&x!=0;x=fa[x])
		vis[x]=1,g.push_back(x);
	if(g.empty()) return true;
//	for(auto x:g) printf("<%d>",x); puts("");
	if(path.empty()||path.back()==x){
		for(int i=(int)g.size()-1;i>=0;--i) path.push_back(g[i]);
		return true;
	}else if(path.front()==x){
		for(int i=(int)g.size()-1;i>=0;--i) path.push_front(g[i]);
		return true;
	}else return false;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		path.clear();
		G=Graph(n,n+n);
		for(int i=1;i<n;++i){
			int x,y; scanf("%d%d",&x,&y); ++x,++y;
			G.add(x,y); G.add(y,x);
		}
		dfs(1,0);
		vector<ll> ans(n+2);
		ans[0]=1ll*n*(n-1)/2;
		for(int i=1;i<=n;++i){
			if(!choose(i)) break;
			ans[i]=calc();
		}
		for(int i=0;i<=n;++i) printf("%lld ",ans[i]-ans[i+1]);
	}
	return 0;
}