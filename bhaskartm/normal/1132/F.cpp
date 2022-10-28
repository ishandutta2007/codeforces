#include <bits/stdc++.h>
using namespace std;
int dp[505][505];

int main() {
	int n;
	cin>>n;
	string s;
	for(int i=0; i<505; i++){
		for(int j=0; j<505; j++){
			dp[i][j]=10000;
		}
	}
	cin>>s;
	for(int l=0; l<=s.size(); l++){
		for(int i=0; i<=s.size()-l; i++){
			if(l==0){
				dp[l][i]=0;
				continue;
			}
			if(l==1){
				dp[l][i]=1;
				continue;
			}
			dp[l][i]=min(dp[l][i], 1+dp[l-1][i+1]);
			for(int j=i+1; j<i+l; j++){
				if(s[j]==s[i]){
					dp[l][i]=min(dp[l][i], dp[j-i-1][i+1]+dp[i+l-j][j]);
				}
			}
		}
	}
	cout<<dp[s.size()][0]<<endl;
	return 0;
}