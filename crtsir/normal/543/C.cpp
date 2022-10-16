#include<bits/stdc++.h>
using namespace std;
int n,m,dp[21][1048576],a[21][21];
string s[23];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
		s[i]=' '+s[i];
	}
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=0;i<=20;i++)
		for(int j=0;j<(1<<n);j++)
			dp[i][j]=20000003;
	dp[0][0]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<(1<<n);j++)
			dp[i][j]=dp[i-1][j];
		for(int j=0;j<(1<<n);j++)
			for(int k=0;k<n;k++)
				dp[i][j|(1<<k)]=min(dp[i][j|(1<<k)],dp[i][j]+a[k][i]);
		int cnt[26],maxm[26],x[26];
		memset(x,0,sizeof(x));
		memset(cnt,0,sizeof(cnt));
		memset(maxm,0,sizeof(maxm));
		for(int j=0;j<n;j++){
			cnt[s[j][i]-'a']+=a[j][i];
			maxm[s[j][i]-'a']=max(maxm[s[j][i]-'a'],a[j][i]);
			x[s[j][i]-'a']+=(1<<j);
		}
		for(int j=0;j<(1<<n);j++)
			for(int k=0;k<26;k++){
				dp[i][j|x[k]]=min(dp[i][j|x[k]],dp[i][j]+cnt[k]-maxm[k]);
			}
	}
	cout<<dp[m][(1<<n)-1];
}