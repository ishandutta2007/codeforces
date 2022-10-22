#include<bits/stdc++.h>
using namespace std;
int n,T,ans;
vector<int>g[200004];
bool t[200004];
void dfs(int x,int fa){
	int cnt=0;
	for(auto y:g[x])if(y!=fa){
		dfs(y,x);
		if(t[y])cnt++;
	}
	if(cnt>0)t[x]=0;
	else t[x]=1;
	if(x!=1&&t[x])ans++;
	else if(!t[x])ans--;
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	ans=0,dfs(1,0);
	printf("%d\n",ans+1);
}
int main(){
	cin>>T;
	while(T--)sol();
}