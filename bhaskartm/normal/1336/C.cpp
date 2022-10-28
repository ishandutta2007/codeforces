#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int MOD=998244353;
const int N=3005;
int dp[N][N];

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string st1;//big
	string st2;//small
	cin>>st1>>st2;
	int n=st1.size();
	int m=st2.size();
	for(int i=0; i<m; i++){
		if(st2[i]==st1[0]){
			dp[i][i]=2;
		}
	}
	for(int i=m; i<n; i++){
		dp[i][i]=2;
	}
	int ans=0;
	
	for(int i=1; i<st1.size(); i++){
		for(int j=0; j<=n-i; j++){
			if(j-1>=0 && (j-1>=m || st2[j-1]==st1[i])){
				dp[j-1][j+i-1]=(dp[j-1][j+i-1]+dp[j][j+i-1])%MOD;
			}
			if(j+i<n && (j+i>=m || st2[j+i]==st1[i])){
				dp[j][j+i]=(dp[j][j+i]+dp[j][j+i-1])%MOD;
			}
		}
		
	}
	for(int i=m-1; i<n; i++){
		ans=(ans+dp[0][i])%MOD;
	}
	cout<<ans;
	
	return 0;
}