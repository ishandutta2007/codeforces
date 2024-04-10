#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const int mod=998244353;
int n,m;
ll dp[N][3];
vector<int> g[N];
inline ll po(ll x,int k){
	ll ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}
inline ll inv(ll x){return po(x,mod-2);}
void dfs(int u){
	if(!g[u].size()){
		dp[u][2]=1;
		return;
	}
	dp[u][2]=dp[u][0]=1;
	for(auto v:g[u]){
		dfs(v);
		dp[u][2]=dp[u][2]*(dp[v][0]+dp[v][2]+dp[v][1]+dp[v][2])%mod;
		dp[u][0]=dp[u][0]*(dp[v][0]+dp[v][2])%mod;
	}
	for(auto v:g[u])
		dp[u][1]=(dp[u][1]+dp[u][0]*inv(dp[v][0]+dp[v][2])%mod*(dp[v][1]+dp[v][2]))%mod;
	dp[u][2]=(dp[u][2]-dp[u][1]-dp[u][0]+mod+mod)%mod;
}
int main(){
	int i,j;
	cin>>n;
	for(i=2;i<=n;i++){
		int fa;cin>>fa;
		g[fa].push_back(i);
	}
	dfs(1);
	cout<<(dp[1][2]+dp[1][0])%mod;
	return 0;
}