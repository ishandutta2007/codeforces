#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
const int MAX_N=5+3e5;
int dfn[MAX_N],low[MAX_N],fa[MAX_N];
class Adj{
	private:
		struct Edge{
			int to; int nxt; int key;
		}edge[MAX_N*4];
		int top_edge;
	public:
		int head[MAX_N*2];
		Adj(){
			top_edge=-1;
			memset(head,-1,sizeof(head));
		}
		Edge& operator[](int x){
			return edge[x];
		}
		void add_edge(int x,int y,int key){
			++top_edge;
			edge[top_edge].to=y;
			edge[top_edge].nxt=head[x];
			edge[top_edge].key=key;
			head[x]=top_edge;
		}
};
Adj edge1,edge2;
stack<int> stk;
int ti=0,top_node=0,cnt[MAX_N*2];
void tarjan(int x,int pre){
	dfn[x]=low[x]=++ti,stk.push(x);
	for(int j=edge1.head[x];j!=-1;j=edge1[j].nxt){
		int y=edge1[j].to;
		if(y!=pre){
			if(dfn[y]>0) low[x]=min(low[x],dfn[y]);
			else{
				tarjan(y,x),low[x]=min(low[x],low[y]);
				if(low[y]==dfn[x]){
					++top_node;
					while(stk.top()!=x){
						edge2.add_edge(stk.top(),top_node,0);
						edge2.add_edge(top_node,stk.top(),0);
						stk.pop();
					}
					edge2.add_edge(x,top_node,0);
					edge2.add_edge(top_node,x,0);
				}else if(low[y]>dfn[x]){
					edge2.add_edge(x,y,1);
					edge2.add_edge(y,x,1);
				} 
			}
		}
	}
	if(dfn[x]==low[x]) stk.pop();
}
int dis[MAX_N*2];
int dfs(int x){
	for(int i=1;i<=top_node;++i) dis[i]=-1;
	dis[x]=0,stk.push(x);
	while(!stk.empty()){
		int x=stk.top(); stk.pop();
		for(int j=edge2.head[x];j!=-1;j=edge2[j].nxt){
			int y=edge2[j].to;
			if(dis[y]==-1){
				dis[y]=dis[x]+edge2[j].key;
				stk.push(y);
			}
		}
	}
	int p=1;
	for(int i=1;i<=top_node;++i) 
		if(dis[i]>dis[p]) p=i;
	return p;
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int u,v; scanf("%d%d",&u,&v);
		edge1.add_edge(u,v,0),edge1.add_edge(v,u,0);
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i) dfn[i]=0;
	top_node=n,tarjan(1,0);
	for(int i=1;i<=n;++i){
		if(edge2[edge2.head[i]].nxt==-1){
			fa[i]=edge2[edge2.head[i]].to;
		}else fa[i]=0;
	}
	printf("%d",dis[dfs(dfs(1))]);
	return 0;
}