#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
#define pb push_back
vector<vector<int>>vi;
vector<vector<int>>ve;
int dp[10005];
bool booly[10005];
const int N=1000000007;
main() {
	int n, q;
	cin>>n>>q;
	vi.resize(n+1);
	ve.resize(n+1);
	for(int i=0; i<q; i++){
		int l, r, x;
		cin>>l>>r>>x;
		vi[l].pb(x);
		if(r!=n){
			ve[r+1].pb(x);
		}
	}
	dp[0]=1;
	for(int i=1; i<=n; i++){
		for(auto u:vi[i]){
			
			for(int j=n; j>=0; j--){
				if(j-u>=0){
					dp[j]=dp[j]+dp[j-u];
					if(dp[j]>=N){
						dp[j]=dp[j]-N;
					}
				}
			}
		}
		for(auto u:ve[i]){
			for(int j=0; j<=n; j++){
				if(j-u>=0){
					dp[j]=dp[j]-dp[j-u];
					if(dp[j]<0){
						dp[j]+=N;
					}
				}
			}
		}
		for(int k=1; k<=n; k++){
			if(dp[k]){
				booly[k]=1;
			}
		}
	}
	vector<int>ans;
	for(int i=1; i<=n; i++){
		if(booly[i]){
			ans.pb(i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto u:ans){
		cout<<u<<" ";
	}
	
	return 0;
}