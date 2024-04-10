#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,deg[N],K,ans[N],num;
vector<int>g[N],id[N];
void dfs(int x,int fa,int c){
	int C=1;
	if(C==c&&C<num)C++;
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=fa){
		int to=g[x][i],I=id[x][i];
		ans[I]=C;
		dfs(to,x,C);
		if(C<num)C++;
		if(C==c&&C<num)C++;
	}
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
		id[u].push_back(i),id[v].push_back(i);
		deg[u]++,deg[v]++;
	}
	sort(deg+1,deg+n+1);
	printf("%d\n",(num=!deg[n-K]?1:deg[n-K]));
	dfs(1,0,0);
	for(int i=1;i<n;i++)printf("%d ",ans[i]);
}