#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[3003][3003];
string s,t;
int main(){cin>>s>>t;int n=s.size(),m=t.size();
	for(int i=0;i<n;i++){
		if(i>=m||s[0]==t[i])
			dp[i][i]=2;
	}
	for(int i=1;i<n;i++)
		for(int j=0;i+j<n;j++){
			int l=j,r=i+j;
			if(l>=m||s[i]==t[l])dp[l][r]=(dp[l][r]+dp[l+1][r])%mod;
			if(r>=m||s[i]==t[r])dp[l][r]=(dp[l][r]+dp[l][r-1])%mod;
		}
	int ans=0;
	for(int i=m-1;i<n;i++)
		ans=(dp[0][i]+ans)%mod;
	cout<<ans;
}