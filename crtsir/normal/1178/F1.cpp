#include<bits/stdc++.h>
using namespace std;
long long dp[503][503],c[503],n,m;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>c[i+1];
	for(int i=1;i<=n+1;i++)dp[i][i-1]=1;
	for(int ik=0;ik<=n;ik++)
		for(int jk=1;jk<=n-ik;jk++){
			int i=jk,j=ik+jk;
			pair<long long,long long>sm=make_pair(2147483647,-1);
			for(long long k=i;k<=j;k++)sm=min(make_pair(c[k],k),sm);
			int pos=sm.second;
			long long cnt1=0,cnt2=0;
			for(int k=i;k<=pos;k++)cnt1=(cnt1+dp[i][k-1]*dp[k][pos-1])%998244353;
			for(int k=pos;k<=j;k++)cnt2=(cnt2+dp[pos+1][k]*dp[k+1][j])%998244353;
			dp[i][j]=(cnt1*cnt2)%998244353;
		}
	cout<<dp[1][n];
}