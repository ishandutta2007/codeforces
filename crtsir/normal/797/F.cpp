#include<bits/stdc++.h>
using namespace std;
int n,m,a[5003];
pair<int,int>p[5003];
long long dp[5003][5003],sum[5003];
int q[5003],s,t;
int main(){
//	freopen("jandt.in","r",stdin);
//	freopen("jandt.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++)
		cin>>p[i].first>>p[i].second;
	sort(p+1,p+m+1);
	memset(dp,31,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			sum[j]=sum[j-1]+abs(a[j]-p[i].first);
		s=0,t=-1;
		for(int j=0;j<=n;j++){
			while(s<=t&&j-q[s]>p[i].second)s++;
			while(s<=t&&dp[i-1][q[t]]-sum[q[t]]>=dp[i-1][j]-sum[j])t--;
			q[++t]=j;
			dp[i][j]=dp[i-1][q[s]]+sum[j]-sum[q[s]];
		}
	}
	if(dp[m][n]<1000000000000000)
		cout<<dp[m][n];
	else
		cout<<-1;
}