#include<bits/stdc++.h>
using namespace std;
int T,n,fa[200100],deg[200100],ged[200100],res;
vector<int>v[200100];
void dfs(int x){for(auto y:v[x])if(y!=fa[x])fa[y]=x,deg[x]++,dfs(y);}
queue<int>q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
		dfs(1);
		for(int x=2;x<=n;x++)if(!deg[x])ged[fa[x]]++,res++;
		for(int x=2;x<=n;x++)if(deg[x]&&deg[x]==ged[x])q.push(x);
		while(!q.empty()){
			int x=q.front();q.pop();
			deg[fa[x]]--,res--;
			if(fa[x]==1)continue;
			if(!deg[fa[x]]){
				ged[fa[fa[x]]]++,res++;
				if(fa[fa[x]]!=1&&deg[fa[fa[x]]]==ged[fa[fa[x]]])q.push(fa[fa[x]]);
			}else if(deg[fa[x]]==ged[fa[x]])q.push(fa[x]);
		}
		if(!deg[1])res++;
		printf("%d\n",res);
		res=0;for(int i=1;i<=n;i++)deg[i]=ged[i]=fa[i]=0,v[i].clear();
	}
	return 0;
}