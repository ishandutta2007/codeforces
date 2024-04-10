#include<iostream>
#include<vector>
using namespace std;
const int N=300005;
int dp[N];
int a[N];
int n;
vector<int> g[N];
void dfs(int cur){
	if(g[cur].size()==0){
		dp[cur]=1;
		return;
	}
	if(a[cur]==1){
		dp[cur]=0x3f3f3f3f;
		for(int i=0;i<g[cur].size();i++){
			dfs(g[cur][i]);
			dp[cur]=min(dp[cur],dp[g[cur][i]]);
		}
	}
	else{
		for(int i=0;i<g[cur].size();i++){
			dfs(g[cur][i]);
			dp[cur]+=dp[g[cur][i]];
		}
	}
	return ;
}
bool vis[N];
int main(){
	cin>>n;
	int cnt=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++){
		int fa;cin>>fa;
		if(!vis[fa]){
			vis[fa]=1;
			cnt--;
		}
		g[fa].push_back(i);
	}
	dfs(1);
	cout<<cnt+1-dp[1];
	return 0;
}