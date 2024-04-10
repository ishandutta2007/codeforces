#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[1003][1003];
ll d[1003][1003];
int a[1003];
ll dp[1003];
const ll MOD=998244353;
int main(){
	d[0][0]=1;
	for (int i=1;i<=1000;i++)for(int j=0;j<=i;j++){
		d[i][j]=d[i-1][j];
		if(j!=0)d[i][j]=(d[i][j]+d[i-1][j-1])%MOD;
	}
	int n;cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int k=2;k<=n;k++)
		for (int i=1;i+k-1<=n;i++)if(a[i]>0&&a[i]-1<=1000){
			int j=i+k-1;
			num[i][j]=d[k-2][a[i]-1];
		}
	dp[0]=1;
	for (int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for (int j=i;j>=1;j--)
			dp[i]=(dp[i]+dp[j-1]*num[j][i]%MOD)%MOD;
	}
	cout<<dp[n]-1;
}