#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,ans,l[200004],r[200004];
ll f[200004];
vector<int>g[200004];
void dfs(int x){
	f[x]=0;
	for(auto y:g[x])dfs(y),f[x]+=f[y];
	if(f[x]>r[x])f[x]=min(f[x],(ll)r[x]);
	else if(f[x]<l[x])f[x]=r[x],ans++;
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=2;i<=n;i++){
		int p;scanf("%d",&p);
		g[p].push_back(i);
	}
	for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	ans=0,dfs(1);
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}