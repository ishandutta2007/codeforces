#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
vector<int> son[N];
void dfs(int x,int pre){
	if(pre!=0) son[x].erase(find(son[x].begin(),son[x].end(),pre));
	for(auto y:son[x])
		dfs(y,x);
}
bool vis[N];
void dfs1(int x){
	vis[x]=0;
	for(auto y:son[x]){
		dfs1(y);
		if(!vis[y]) vis[x]=1;
	}
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) son[i].clear();
		for(int i=1;i<n;++i){
			int x,y; scanf("%d%d",&x,&y);
			son[x].push_back(y);
			son[y].push_back(x);
		}
		dfs(1,0);
		dfs1(1);
		int cnt0=0,cnt1=0;
		for(int x=1;x<=n;++x){
			if(!vis[x]) ++cnt0;
			else ++cnt1;
		}
		if(vis[1]) printf("%d\n",cnt0-cnt1+1);
		else printf("%d\n",cnt0-cnt1);
	}
	return 0;
}