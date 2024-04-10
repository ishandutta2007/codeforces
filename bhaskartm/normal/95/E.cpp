#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
vector<vector<int>>adj;
bool vis[100005];
int num;
int cnt[100005];
const int N=1e9;
void dfs(int v){
	vis[v]=1;
	num++;
	for(auto u:adj[v]){
		if(vis[u]==0){
			dfs(u);
		}
	}
}

bool is(int num){
	bool che=1;
	while(num!=0){
		int val=(num%10);
		if(val!=4 && val!=7){
			che=0;
			break;
		}
		num=num/10;
	}
	return che;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	adj.resize(n+1);
	
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	for(int i=1; i<=n; i++){
		if(vis[i]){
			continue;
		}
		num=0;
		dfs(i);
		cnt[num]++;
	}
	int dp[100005];
	for(int i=0; i<100005; i++){
		dp[i]=N;
	}
	
	dp[0]=0;

	for(int i=1; i<=100000; i++){
		if(cnt[i]==0){
			continue;
		}
		
		for(int x=0; (1<<x)<=cnt[i]; x++){
			for(int j=100000; j>=((1<<x)*i); j--){
				dp[j]=min(dp[j], dp[j-((1<<x)*i)]+(1<<x));
			}
			cnt[i]-=(1<<x);
		}
		
		for(int j=100000; j>=(cnt[i]*i); j--){
			dp[j]=min(dp[j], dp[j-(cnt[i]*i)]+cnt[i]);
		}
		
	}
	
	int mini=N;
	for(int i=1; i<=n; i++){
		if(is(i)){
			mini=min(mini, dp[i]);
		}
	}
	if(mini==N){
		cout<<-1;
	}
	else{
		cout<<mini-1;
	}
	return 0;
}