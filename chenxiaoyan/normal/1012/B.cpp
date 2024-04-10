/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200000,M=200000;
int n,m,s;
vector<int> bel[M+1],nei[N+1];
bool vis[N+1];
void dfs(int x){
	vis[x]=true;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(!vis[y])dfs(y);
	}
}
int main(){
	cin>>n>>m>>s;
	while(s--){
		int x,y;
		scanf("%d%d",&x,&y);
		bel[y].pb(x);
	}
	int ans=-1;
	for(int i=1;i<=m;i++){
		ans+=bel[i].empty();
		for(int j=0;j+1<bel[i].size();j++)nei[bel[i][j]].pb(bel[i][j+1]),nei[bel[i][j+1]].pb(bel[i][j]);
	}
	for(int i=1;i<=n;i++)if(!vis[i])ans++,dfs(i);
	cout<<ans;
	return 0;
}