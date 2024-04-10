#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
lli maxcost=4e14;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	lli n,a,b;
    	cin>>n>>a>>b;
    	string rd;
    	cin>>rd;
    	lli dp[n+1][2];
    	dp[0][0]=b;
    	dp[0][1]=maxcost;
    	for(int i=1;i<=n;i++){
    		if(rd[i-1]=='1'){
    			dp[i][1]=dp[i-1][1]+2*b+a;
    			dp[i][0]=maxcost;
    		}
    		else{
    			dp[i][0]=min(dp[i-1][0]+b+a,dp[i-1][1]+b+2*a);
    			dp[i][1]=min(dp[i-1][0]+2*b+2*a,dp[i-1][1]+2*b+a);
    		}
    	}
    	printf("%lli\n",dp[n][0]);
    }
    return 0;
}