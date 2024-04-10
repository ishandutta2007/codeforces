#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int in[N],out[N],ans;
vector<int>g[N];
int n,m,f[N];
vector<int>ord;
bool v[N];
void dfs(int x){
	if(v[x])return;
	v[x]=1;
	for(auto y:g[x])dfs(y);
	ord.push_back(x);
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;scanf("%d%d",&u,&v);
		out[u]++,in[v]++,g[u].push_back(v);
	}
	for(int i=1;i<=n;i++)dfs(i);
	reverse(ord.begin(),ord.end());
	for(auto x:ord){
		f[x]=max(f[x],1);
		if(out[x]>1)
			for(auto y:g[x])if(in[y]>1)
				f[y]=max(f[y],f[x]+1);
		ans=max(ans,f[x]);
	}
	printf("%d",ans);
}