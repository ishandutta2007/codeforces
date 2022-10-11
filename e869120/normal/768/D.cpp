#include<bits/stdc++.h>
using namespace std;
long double dp[12000][1000];
int main(){
	int n,q;cin>>n>>q;
	dp[0][0]=1.0l;
	for(int i=0;i<10000;i++){
		for(int j=0;j<=n;j++){
			dp[i+1][j]+=dp[i][j]*(1.0l*j/n);
			dp[i+1][j+1]+=dp[i][j]*(1.0l*(n-j)/n);
		}
	}
	for(int i=0;i<q;i++){
		long double p;cin>>p;
		for(int j=0;j<10000;j++){
			if((p/2000)<=dp[j][n]){cout<<j<<endl;break;}
		}
	}
	return 0;
}