#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;

int n,m,a[510],dp[510][510],minv[510][510],pos[510][510];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){minv[i][i]=a[i];pos[i][i]=i;}
	for(int l=2;l<=n;l++){
		for(int i=1,j=l;j<=n;i++,j++){
			if(minv[i][j-1]<a[j]){
				minv[i][j]=minv[i][j-1];
				pos[i][j]=pos[i][j-1];
			}
			else{
				minv[i][j]=a[j];
				pos[i][j]=j;
			}
		}
	}
	for(int i=1;i<=n;i++) dp[i][i]=1;
	for(int l=2;l<=n;l++){
		for(int i=1,j=l;j<=n;i++,j++){
			int loc=pos[i][j];
			int ans1=0,ans2=0;
			ans1=dp[i][loc-1]*2;
			ans2=dp[loc+1][j]*2;
			for(int k=i;k<loc-1;k++){
				ans1+=(dp[i][k]*dp[k+1][loc-1])%MOD;
				ans1%=MOD;
			}
			for(int k=loc+1;k<j;k++){
				ans2+=(dp[loc+1][k]*dp[k+1][j])%MOD;
				ans2%=MOD;
			}
			if(i==loc){
				dp[i][j]=ans2;
			}
			else if(j==loc){
				dp[i][j]=ans1;
			}
			else{
				dp[i][j]=(ans1*ans2)%MOD;
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}