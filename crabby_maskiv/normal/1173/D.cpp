#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
vector<int> g[N];
ll fac[N];
ll dp[N];
void dfs(int cur,int last){
	dp[cur]=1;
	int ch=0;
	for(auto v:g[cur]){
		if(v==last) continue;
		dfs(v,cur);
		ch++;
		dp[cur]=(dp[cur]*dp[v])%mod;
	}
	dp[cur]*=fac[ch+(cur>1)];
	dp[cur]%=mod;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	fac[0]=1;
	for(i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%mod;
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	cout<<(n*dp[1])%mod;
	return 0;
}