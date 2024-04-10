#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		if(n==1){
			cout<<arr[0]<<endl;
			continue;
		}
		if(n==2){
			cout<<max(arr[0], arr[1])<<endl;
			continue;
		}
		int maxi=0;
		for(int i=0; i<n; i=i+2){
			if(i%2==0){
				maxi+=arr[i];
			}
		}
		
		vector<int>b;
		for(int i=1; i<n; i=i+2){
			b.pb(arr[i]-arr[i-1]);
		}
		
		int ans=0;
		int dp[b.size()];
		dp[0]=b[0];
		ans=max(ans, dp[0]);
		for(int i=1; i<b.size(); i++){
			dp[i]=max(b[i], b[i]+dp[i-1]);
			ans=max(ans, dp[i]);
		}
		
		vector<int>c;
		for(int i=2; i<n; i=i+2){
			c.pb(arr[i-1]-arr[i]);
		}
		
		int dp2[c.size()];
		int ans2=0;
		dp2[0]=c[0];
		ans2=max(ans2, dp2[0]);
		
		for(int i=1; i<c.size(); i++){
			dp2[i]=max(c[i], c[i]+dp2[i-1]);
			ans2=max(ans2, dp2[i]);
		}
		int ans3=max(ans, ans2);
		cout<<maxi+ans3<<endl;
	}
	return 0;
}