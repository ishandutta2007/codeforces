#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5+50;
int n,fa[N],f[N],g[N],ans;
vector<int>v[N];
void dfs(int x){
	if(fa[x])v[x].erase(find(v[x].begin(),v[x].end(),fa[x]));
	f[x]=1;g[x]=0;int ff=!!fa[x];
	for(int i=0,y;i<v[x].size();i++){
		fa[y=v[x][i]]=x;dfs(y);
		ans=max(ans,max(g[x]+ff-1+g[y],max(f[x]+g[y],g[x]+ff-1+f[y])));
		// printf("%d %d %d\n",x,y,ans);
		f[x]=max(f[x],g[y]+1);
		g[x]=max(g[x],max(f[y],g[y])+(int)v[x].size()-1);
	}
	// printf("%d %d %d\n",x,f[x],g[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].pb(y);v[y].pb(x);
	}
	dfs(1);cout<<ans;
	return 0;
}