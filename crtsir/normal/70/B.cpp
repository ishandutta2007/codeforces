#include<bits/stdc++.h>
using namespace std;
int dp[10003],c[10003],cnt,x=1;//Cf
string s;
int main(){
	int n;
	cin>>n;
	getline(cin,s);
	getline(cin,s);
	memset(dp,40000,sizeof(dp));
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='.'||s[i]=='!'||s[i]=='?')
		{
			c[++cnt]=x;
			if(x>n){
				cout<<"Impossible";
				return 0;
			}
			x=0;
		}
		else
			x++;
	}
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=cnt;i++)
	{
		x=c[i];
		for(int j=i-1;j>-1&&x<=n;j--)
		{
			dp[i]=min(dp[i],dp[j]+1);
			x=x+c[j]+1;
		}
	}
	cout<<dp[cnt];
}