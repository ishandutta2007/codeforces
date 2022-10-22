#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5;
struct Graph{
	struct Edge{ int to,nxt; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1; }
	inline void add(int x,int y){
		edge[++top]=(Edge){y,head[x]};
		head[x]=top;
	}
}G;
int id[MAX_N],fa[MAX_N],p[MAX_N],hs[MAX_N],dep[MAX_N],ti=0;
vector<int> ans;
void opera(int x){ fa[x]=fa[fa[x]]; ans.push_back(x); }
void dfs(int x,int pre){
	dep[x]=1; hs[x]=-1;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			dfs(y,x);
			dep[x]=max(dep[x],dep[y]+1);
			if(hs[x]==-1||dep[hs[x]]<dep[y]) hs[x]=y;
		}
	}
}
void dfs2(int x,int pre){
	fa[x]=id[ti]; id[++ti]=x;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre&&y!=hs[x])
			dfs2(y,x);
	}
	if(hs[x]!=-1) dfs2(hs[x],x);
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d",&p[i]);
		G.add(p[i],i);
		G.add(i,p[i]);
	}
	dfs(0,-1);
	dfs2(0,-1);
	for(int i=1;i<=n;++i)
		while(fa[id[i]]!=p[id[i]]) opera(id[i]);
	for(int i=1;i<=n;++i) printf("%d ",id[i]); puts("");
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();++i) printf("%d ",ans[i]); puts("");
//	printf("|%d|",n-dep[0]);
//	if(ans.size()==93) printf("[%d]",ans[i]);
	return 0;
}