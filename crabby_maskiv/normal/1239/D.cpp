#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
int n,m;
bool ins[N];
int dfn[N],low[N],scc[N];
stack<int> s;
int len,cnt;
vector<int> g[N];
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	s.push(u);ins[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(dfn[v]){
			if(ins[v]) low[u]=min(low[u],dfn[v]);
		}
		else{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
	}
	if(low[u]==dfn[u]){
		len++;
		while(!s.empty()){
			int x=s.top();s.pop();
			scc[x]=len;
			ins[x]=0;
			if(x==u) break;
		}
	}
}
int deg[N];
int main(){
	int i,j;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int x,y;
		for(i=1;i<=len;i++) deg[i]=0;
		for(i=1;i<=n;i++){
			g[i].clear();
			dfn[i]=low[i]=scc[i]=0;
		}
		cnt=len=0;
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(x==y) continue;
			g[x].push_back(y);
		}
		for(i=1;i<=n;i++)
			if(!dfn[i]) tarjan(i);
		if(len==1){
			printf("NO\n");
			continue;
		}
		for(i=1;i<=n;i++){
			for(j=0;j<g[i].size();j++){
				int v=g[i][j];
				if(scc[i]!=scc[v]) deg[scc[i]]++;
			}
		}
		for(i=1;i<=len;i++) if(!deg[i]) break;
		int ans=0;
		for(j=1;j<=n;j++) if(scc[j]==i) ans++;
		printf("YES\n");
		printf("%d %d\n",ans,n-ans);
		for(j=1;j<=n;j++) if(scc[j]==i) printf("%d ",j);
		printf("\n");
		for(j=1;j<=n;j++) if(scc[j]!=i) printf("%d ",j);
		printf("\n");
	}
	return 0;
}