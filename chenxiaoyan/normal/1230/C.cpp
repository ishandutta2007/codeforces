/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=7;
int n,m;
vector<int> nei[N+1];
int v[N+1];
bool hav[7][7];
int ans;
void dfs(int x=1){
	if(x==n+1){
		memset(hav,0,sizeof(hav));
		for(int i=1;i<=n;i++)for(int j=0;j<nei[i].size();j++){
			int y=nei[i][j];
			if(v[i]<=v[y])hav[v[i]][v[y]]=true;
		}
		int cnt=0;
		for(int i=1;i<=6;i++)for(int j=i;j<=6;j++)cnt+=hav[i][j];
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=6;i++)v[x]=i,dfs(x+1);
}
int main(){
	cin>>n>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		nei[x].pb(y);nei[y].pb(x);
	}
	dfs();
	cout<<ans;
	return 0;
}