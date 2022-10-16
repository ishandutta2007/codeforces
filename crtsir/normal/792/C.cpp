#include<bits/stdc++.h>
using namespace std;
int dp[2][3][100003];
pair<int,int>path[2][3][100003];
bool bl[2][3][100003],can0=1;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		dp[0][0][0]=-1e9-7;
		dp[1][0][0]=-1e9-7;
		dp[0][1][0]=-1e9-7;
		dp[1][1][0]=-1e9-7;
		dp[0][2][0]=-1e9-7;
		dp[1][2][0]=-1e9-7;
		if(s[i]=='0')can0=0;
	}
	dp[0][0][0]=0;
	bl[0][0][0]=0;
	path[0][0][0]=make_pair(-1,-1);
	if(s[0]!='0')dp[1][(s[0]-'0')%3][0]=1,path[1][(s[0]-'0')%3][0]=make_pair(-1,-1),bl[1][(s[0]-'0')%3][0]=1;
	for(int i=1;i<s.size();i++){
		dp[0][0][i]=dp[0][0][i-1];
		path[0][0][i]=make_pair(0,0);
		bl[0][0][i]=0;
		dp[1][0][i]=dp[1][0][i-1];
		path[1][0][i]=make_pair(1,0);
		bl[1][0][i]=0;
		dp[0][1][i]=dp[0][1][i-1];
		path[0][1][i]=make_pair(0,1);
		bl[0][1][i]=0;
		dp[1][1][i]=dp[1][1][i-1];
		path[1][1][i]=make_pair(1,1);
		bl[1][1][i]=0;
		dp[0][2][i]=dp[0][2][i-1];
		path[0][2][i]=make_pair(0,2);
		bl[0][2][i]=0;
		dp[1][2][i]=dp[1][2][i-1];
		path[1][2][i]=make_pair(1,2);
		bl[1][2][i]=0;
		for(int j=0;j<3;j++)
		{ 
			if(s[i]!='0')
				if(dp[1][(j+s[i]-'0')%3][i]<=dp[0][j][i-1])
					dp[1][(j+s[i]-'0')%3][i]=dp[0][j][i-1]+1,
					path[1][(j+s[i]-'0')%3][i]=make_pair(0,j),
					bl[1][(j+s[i]-'0')%3][i]=1;
			if(dp[1][(j+s[i]-'0')%3][i]<=dp[1][j][i-1])
				dp[1][(j+s[i]-'0')%3][i]=dp[1][j][i-1]+1,
				path[1][(j+s[i]-'0')%3][i]=make_pair(1,j),
				bl[1][(j+s[i]-'0')%3][i]=1;
		}
	}
	if(dp[1][0][s.size()-1]<0){
		cout<<-can0;
		return 0;
	}
	string ans;
	pair<int,int>now=make_pair(1,0);
	for(int i=s.size()-1;i>=0;i--)
	{
		if(bl[now.first][now.second][i])ans=s[i]+ans;
		now=path[now.first][now.second][i];
	}
	cout<<ans;
}