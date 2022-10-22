#include<bits/stdc++.h>
using namespace std;
int T,n,a[100004],b[100004];
vector<int>g[100004];
int vec=0;
bool vis[100004];
void dfs(int x){
	if(vis[x])return;
	vis[x]=1,vec++;
	for(auto y:g[x])dfs(y);
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)g[i].clear(),vis[i]=0;
	for(int i=1;i<=n;i++){
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	int cnt=n;
	for(int i=1;i<=n;i++)if(!vis[i])
		vec=0,dfs(i),cnt-=vec&1;
	long long ans=0;
	for(int l=1,r=n,t=0;t<cnt/2;t++,l++,r--)
		ans+=2*(r-l);
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}