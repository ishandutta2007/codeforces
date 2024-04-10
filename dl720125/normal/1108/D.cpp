#include <bits/stdc++.h>
//#define int long long
using namespace std;

int n,dp[200010][3];
char c[200010][3];
string s;

void print(int pos,int dex){
	if(pos==0) return;
	char v=c[pos][dex];
	if(v=='R') print(pos-1,0);
	else if(v=='B') print(pos-1,1);
	else print(pos-1,2);
	cout<<v;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>s;
	if(s[0]=='R'){
		dp[0][0]=1;
	}
	else if(s[0]=='B') dp[0][1]=1;
	else dp[0][2]=1;
	
	for(int i=1;i<s.size();i++){
		if(s[i]=='R') dp[i][0]++;
		else if(s[i]=='B') dp[i][1]++;
		else dp[i][2]++;
		
		if(dp[i-1][1]<dp[i-1][2]){
			c[i][0]='G';
		}
		else c[i][0]='B';
		
		if(dp[i-1][0]<dp[i-1][2]){
			c[i][1]='G';
		}
		else c[i][1]='R';
		
		if(dp[i-1][0]<dp[i-1][1]){
			c[i][2]='B';
		}
		else c[i][2]='R';
		
		dp[i][0]+=max(dp[i-1][1],dp[i-1][2]);
		dp[i][1]+=max(dp[i-1][0],dp[i-1][2]);
		dp[i][2]+=max(dp[i-1][1],dp[i-1][0]);
	}
	if(dp[n-1][0]>dp[n-1][1]&&dp[n-1][0]>dp[n-1][2]){
		cout<<n-dp[n-1][0]<<endl;
		print(n-1,0);
		cout<<'R'<<endl;
	}
	else if(dp[n-1][1]>dp[n-1][0]&&dp[n-1][1]>dp[n-1][2]){
		cout<<n-dp[n-1][1]<<endl;
		print(n-1,1);
		cout<<'B'<<endl;
	}
	else{
		cout<<n-dp[n-1][2]<<endl;
		print(n-1,2);
		cout<<'G'<<endl;
	}
	return 0;
}