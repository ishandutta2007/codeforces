#include <bits/stdc++.h>
using namespace std;
int dp[100004][2];
int d[100004][2];
int MOD=1e9+7;
int main(){
	int n,m;cin>>n>>m;
	if (n>m) swap(n,m);
	d[1][0]=2;
	for (int i=2;i<=m;i++){
		d[i][1]=d[i-1][0];
		d[i][0]=(d[i-1][0]+d[i-1][1])%MOD;
	}
	int num=(d[m][0]+d[m][1])%MOD;
	cout<<((d[n][0]+d[n][1])%MOD+num%MOD-2)%MOD;
}