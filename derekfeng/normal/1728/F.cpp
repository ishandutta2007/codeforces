#include<bits/stdc++.h>
using namespace std;
vector<int>all;
vector<int>gr[1000004];
int n,a[1004],m;long long ans;
bool vis[1000004];int mch[1004];
bool dfs(int x){
	for(auto y:gr[x])if(!vis[y]){
		vis[y]=1;if(mch[y]<0||dfs(mch[y])){
			mch[y]=x;return 1;
		}
	}return 0;
}
int main(){
	scanf("%d",&n);for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j<=n;j++)all.push_back(a[i]*j);
	}sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	m=all.size();for(int i=0;i<n;i++)for(int j=1;j<=n;j++)
		gr[lower_bound(all.begin(),all.end(),a[i]*j)-all.begin()].push_back(i);
	memset(mch,-1,sizeof(mch));
	for(int i=0;i<m;i++)if(dfs(i))ans+=all[i],memset(vis,0,sizeof(vis));
	printf("%lld\n",ans);
}