/******************
*  Writer: Oh no  *
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

#define MP make_pair

int n;
int dp[5005];
int h[5005];
int w[5005];
int out[5005];

void dfs(int x){
	if(dp[x]){
		return;
	}
	for(int i=1;i<=n;i++){
		if(h[i]>h[x] && w[i]>w[x]){
			dfs(i);
			if(dp[i]>=dp[x]){
				dp[x]=dp[i]+1;
				out[x]=i;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>w[0]>>h[0];
	for(int i=1;i<=n;i++){
		cin>>w[i]>>h[i];
		out[i]=-1;
	}
	out[0]=-1;
	
	dfs(0);
	
	cout<<dp[0]<<endl;
	
	for(int i=out[0];i>=0;i=out[i]){
		cout<<i<<' ';
	}
	
	return 0;
}//