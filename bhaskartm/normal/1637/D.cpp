#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
 
int n;
bool dp[105][10005];

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n+1];
		a[0]=0;
		int sum=0;
		int ss=0;
		for(int i=1; i<=n; i++){
			cin>>a[i];
			sum+=a[i];
			ss+=(a[i]*a[i]);
		}
		int b[n+1];
		b[0]=0;
		for(int i=1; i<=n; i++){
			cin>>b[i];
			sum+=b[i];
			ss+=(b[i]*b[i]);
		}
		
		dp[0][0]=1;
		
		for(int i=0; i<n; i++){
			for(int sums=0; sums<=min(sum, 10004LL); sums++){
				if(dp[i][sums]){
					dp[i+1][sums+a[i+1]]=1;
					dp[i+1][sums+b[i+1]]=1;
				}
			}
		}
		int mini=1e9;
		int val=sum/2;
		for(int i=0; i<=val; i++){
			if(dp[n][i]){
				mini=min(mini, val-i);
			}
		}
		for(int i=0; i<=n; i++){
			for(int j=0; j<=min(sum, 10004LL); j++){
				dp[i][j]=0;
			}
		}
		cout<<((n-2)*ss)+(val-mini)*(val-mini)+(sum-val+mini)*(sum-val+mini)<<endl;
	}
	return 0;
}