#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[300004],b[300004],vis[300004];
int g[300004];
void dfs(int x){
	vis[x]=1;
	if(!vis[g[x]])dfs(g[x]);
}
void solve(){
	map<int,int>mp;
	vector<int>v,res;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int tmp=(i-a[i]+n)%n;
		v.push_back(tmp);
		mp[tmp]++;
	}
	sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
	for(auto x:v)if(mp[x]>=n-2*m){
		int cnt=0;
		for(int i=n-x+1;i<=n;i++)b[++cnt]=i;
		for(int i=1;i<=n-x;i++)b[++cnt]=i;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)g[b[i]]=a[i];
		int ans=0;
		for(int i=1;i<=n;i++)if(!vis[i])ans++,dfs(i);
		if(n-ans<=m)res.push_back(x);
	}
	printf("%d ",res.size());for(auto x:res)printf("%d ",x);puts("");
}
int main(){
	for(scanf("%d",&T);T--;)solve();
}