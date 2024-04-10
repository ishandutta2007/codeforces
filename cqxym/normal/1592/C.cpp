#include<iostream>
#include<vector>
using namespace std;
#define R register int
#define I inline void
#define N 200001
int f[N];
vector<int>G[N];
bool dp[N][2];
I PreDP(int x,int F){
	for(auto T:G[x]){
		if(T!=F){
			PreDP(T,x);
			f[x]^=f[T];
		}
	}
}
I ReDP(int x,int F){
	dp[x][0]=dp[x][1]=false;
	int t=0;
	for(auto T:G[x]){
		if(T!=F){
			ReDP(T,x);
			t+=dp[T][0];
			dp[x][0]=dp[x][0]||dp[T][0];
			dp[x][1]=dp[x][1]||dp[T][1];
		}
	}
	dp[x][1]=dp[x][1]||dp[x][0]&&f[x]==0||t>1;
	dp[x][0]=dp[x][0]||f[x]==f[1];
}
I Solve(){
	int n,k,x,y;
	cin>>n>>k;
	for(R i=1;i<=n;i++){
		cin>>f[i];
		G[i].clear();
	}
	for(R i=1;i!=n;i++){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	PreDP(1,0);
	if(f[1]==0){
		cout<<"YES"<<endl;
		return;
	}
	if(k==2){
		cout<<"NO"<<endl;
		return;
	}
	ReDP(1,0);
	if(dp[1][1]==true){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}