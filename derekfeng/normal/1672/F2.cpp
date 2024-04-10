#include<bits/stdc++.h>
using namespace std;
int t,n,num[200004];
int a[200004],b[200004];
vector<int>g[400004];
vector<int>ord;
bool vis[400004];
int topo[400004],cnt;
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	for(auto y:g[x])dfs(y);
	topo[x]=++cnt;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(num,0,(n+2)<<2);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),num[a[i]]++;
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		int val=0;
		for(int i=1;i<=n;i++)if(num[val]<num[i])val=i;
		val+=n;
		for(int i=1;i<=n+n;i++)g[i].clear(),vis[i]=0;
		for(int i=1;i<=n;i++){
			g[i].push_back(b[i]+n);
			g[a[i]+n].push_back(i);
		}
		ord.clear(),vis[val]=1,cnt=0;
		for(int i=1;i<=n+n;i++)if(!vis[i])dfs(i);
		bool ok=1;
		for(int i=1;i<=n+n;i++)if(i!=val)
			for(auto j:g[i])if(j!=val)
				ok&=topo[i]>topo[j];
		puts(ok?"AC":"WA");
	}
}