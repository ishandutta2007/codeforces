#include<cstdio>
#include<vector>
#include<algorithm> 
const int N=1e5+3;
std::vector<int>g[N],ans;
int fa[N],n,h[N];
bool Cmp(const int&u,const int&v){return h[u]<h[v];}
void Dfs(int u){
	printf("%d ",u);
	std::sort(g[u].begin(),g[u].end(),Cmp);
	for(int i=0;i<g[u].size();i++)Dfs(g[u][i]);
	if(g[u].size()>=2)for(int i=1;i<g[u].size();i++){
	  for(int j=0;j<h[g[u][i-1]];j++)ans.push_back(g[u][i]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d",fa+i),g[fa[i]].push_back(i);
	for(int i=n-1;i;i--)++h[i],h[fa[i]]=std::max(h[fa[i]],h[i]);
	++h[0];
	Dfs(0),puts("");
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);puts("");
	return 0;
}