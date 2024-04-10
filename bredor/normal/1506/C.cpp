#include<bits/stdc++.h>
using namespace std;
int dp[55][55];
int main(){
	int T;cin>>T;
	while(T--){
		string a,b;cin>>a>>b;
	int n=a.size();int m=b.size();
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i]==b[j]){
				dp[i+1][j+1]=dp[i][j]+1;
			}
			else dp[i+1][j+1]=0;
			ans=max(dp[i+1][j+1],ans); 
		}
	}
	cout<<n+m-2*ans<<endl;
	}
return 0;}