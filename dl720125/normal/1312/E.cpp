#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int a[510],dp[510][510],val[510][510];

signed main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=1;l<=n;l++){
		for(int i=1,j=l;j<=n;i++,j++){
			if(l==1){
				dp[i][j]=1;val[i][j]=a[i];continue;
			}
			if(l==2){
				if(a[i]==a[j]){dp[i][j]=1;val[i][j]=a[i]+1;}
				else dp[i][j]=2;
				continue;
			}
			dp[i][j]=l;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
				if(dp[i][k]==1&&dp[k+1][j]==1&&val[i][k]==val[k+1][j]){
					dp[i][j]=1;val[i][j]=val[i][k]+1;
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}