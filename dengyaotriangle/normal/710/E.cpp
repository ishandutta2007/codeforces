#include<iostream>
#include<cstring>

using namespace std;

const int maxn=10000005;

long long n,x,y;
long long dp[maxn+maxn];

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>x>>y;
	dp[0]=0;
	for(long long i=1;i<=n+n;i++){
		if(dp[i-1]!=-1) dp[i]=dp[i-1]+x;
		if(i%2==0){
			if(dp[i/2]!=-1){
				if(dp[i]==-1){
					dp[i]=dp[i/2]+y;
				}else{
					if(dp[i/2]+y<dp[i])dp[i]=dp[i/2]+y;
				}
			}
		}else{
			if(dp[(i+1)/2]!=-1){
				if(dp[i]==-1){
					dp[i]=dp[i/2]+y+x;
				}else{
					if(dp[(i+1)/2]+y+x<dp[i])dp[i]=dp[(i+1)/2]+y+x;
				}
			}
		}
	}
	cout<<dp[n];
	return 0;
}