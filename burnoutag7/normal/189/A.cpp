/******************
*  Writer: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int dp[5005];
int n,a,b,c;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>a>>b>>c;
	for(int i=0;i<=5000;i++){
		dp[i]=-1e9;
	}
	dp[0]=0;
	
	for(int i=1;i<=5000;i++){
		if(i>=a)dp[i]=max(dp[i],dp[i-a]+1);
		if(i>=b)dp[i]=max(dp[i],dp[i-b]+1);
		if(i>=c)dp[i]=max(dp[i],dp[i-c]+1);
	}
	
	cout<<dp[n]<<endl;
	
	return 0;
}