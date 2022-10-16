#include<bits/stdc++.h>
using namespace std;
int n,k;string s;
pair<bool,int>dp[1003][2003];
char c(int x){
	if(x==1)return 'L';
	if(x==0)return 'D';
	if(x==-1)return 'W';
}
int main(){
	cin>>n>>k>>s;
	dp[0][1001].first=1;
	for(int i=1;i<=n;i++){
		int p=i-1;
		for(int j=1002-k;j<1001+k;j++)
			if(dp[p][j].first)
			{
				if(s[p]=='D'||s[p]=='?')
					dp[i][j].first=1,
					dp[i][j].second=0;
				if(s[p]=='L'||s[p]=='?')
					dp[i][j+1].first=1,
					dp[i][j+1].second=1;
				if(s[p]=='W'||s[p]=='?')
					dp[i][j-1].first=1,
					dp[i][j-1].second=-1;
			}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1001-k;j<1002+k;j++)
			cout<<dp[i][j].first<<' ';
		cout<<endl;
	}*/
	if(dp[n][1001-k].first){
		string ans;
		int p=1001-k;
		for(int i=n;i>0;i--)ans=c(dp[i][p].second)+ans,p-=dp[i][p].second;
		cout<<ans;
	}else if(dp[n][1001+k].first){
		string ans;
		int p=1001+k;
		for(int i=n;i>0;i--)ans=c(dp[i][p].second)+ans,p-=dp[i][p].second;
		cout<<ans;
	}else
		cout<<"NO";
}