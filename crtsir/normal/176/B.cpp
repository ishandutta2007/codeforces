#include<bits/stdc++.h>
using namespace std;
string a,b;
int x,cnt;
long long dp[100003][2];
int main(){
	cin>>a>>b>>x;
	for(int i=0;i<a.size();i++)
		cnt+=(a.substr(i)+a.substr(0,i)==b);
	if(a==b)
		dp[0][0]=1;
	else
		dp[0][1]=1;
	for(int i=1;i<=x;i++)
	{
		dp[i][0]=(dp[i-1][1]*cnt+dp[i-1][0]*(cnt-1))%1000000007;
		dp[i][1]=((dp[i-1][1]*(a.size()-1))%1000000007+dp[i-1][0]*(a.size()-1)-dp[i][0])%1000000007;
	//	cout<<dp[i][0]<<dp[i][1]<<endl;
	}
	cout<<dp[x][0];
}