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
	int n, m;
	cin>>n>>m;
	string s1, s2;
	cin>>s1>>s2;
	int sz1=s1.size();
	int sz2=s2.size();
	int dp[sz1+1][sz2+1];
	for(int i=0; i<=sz1; i++){
		for(int j=0; j<=sz2; j++){
			if(min(i, j)==0){
				dp[i][j]=0;
			}
			else{
				dp[i][j]=0;
			}
		}
	}
	for(int i=1; i<=sz1; i++){
		for(int j=1; j<=sz2; j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=max(dp[i][j], 2+dp[i-1][j-1]);
			}
			else{
				dp[i][j]=max(dp[i][j], dp[i-1][j-1]-2);
			}
			dp[i][j]=max(dp[i-1][j]-1, dp[i][j]);
			dp[i][j]=max(dp[i][j], dp[i][j-1]-1);
		}
	}
	int maxi=0;
	for(int i=1; i<=sz1; i++){
		for(int j=1; j<=sz2; j++){
			maxi=max(maxi, dp[i][j]);
		}
	}
	cout<<maxi;
	return 0;
}