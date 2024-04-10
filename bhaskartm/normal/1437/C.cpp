#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		vector<int>v;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			v.pb(x);
		}
		sort(v.begin(), v.end());
		int dp[n][2*n+1];
		for(int i=0; i<n; i++){
			for(int j=0; j<=2*n; j++){
				dp[i][j]=1e9;
			}
		}
		for(int i=1; i<=2*n; i++){
			dp[0][i]=abs(i-v[0]);
		}
		for(int i=0; i<n-1; i++){
			for(int j=1; j<=2*n; j++){
				for(int k=j+1; k<=2*n; k++){
					dp[i+1][k]=min(dp[i+1][k], dp[i][j]+abs(v[i+1]-k));
				}
			}
		}
		int ans=1e9;
		for(int i=0; i<=2*n; i++){
			ans=min(ans, dp[n-1][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}