#include<bits/stdc++.h>
using namespace std;
int n,m,a[203],b[203];
bool dp[203][1024];
int main(){
	cin>>n>>m; 
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<1024;k++)
				if(dp[i-1][k])
					dp[i][k|(a[i]&b[j])]=1;
	for(int i=0;i<1024;i++)
		if(dp[n][i]){
			cout<<i;
			return 0;
		}
}