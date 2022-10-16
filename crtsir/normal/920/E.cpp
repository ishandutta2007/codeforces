#include<bits/stdc++.h>
using namespace std;
int n,m,fa[200003],N,cnt[2003][2003],sz[2003];
vector<int>v[200003],g[2003],ans;
bool vis[2003];
int dfs(int x){
	vis[x]=1;int ret=sz[x];
	for(int i=0;i<g[x].size();i++)
		if(!vis[g[x][i]])
			ret+=dfs(g[x][i]);
	return ret;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}int pt=0;
	for(int i=1;i<n;i++)
		if(v[i].size()<v[pt].size())
			pt=i;sz[0]=n;
	for(int i=0;i<v[pt].size();i++)
		fa[v[pt][i]]=++N,sz[N]++,sz[0]--;
	for(int i=0;i<n;i++)
		for(int j=0;j<v[i].size();j++)
			cnt[fa[i]][fa[v[i][j]]]++;
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			if(cnt[i][j]!=1ll*sz[i]*sz[j])
				g[i].push_back(j);
	for(int i=0;i<=N;i++)
		if(!vis[i])
			ans.push_back(dfs(i));
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<' ';
}