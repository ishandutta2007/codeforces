#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const ll mod=998244353ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll dp[N][2*N][4];
int main(){
	ios::sync_with_stdio(0);
    int i,j,k;
    cin>>n>>m;
    dp[1][2][1]=dp[1][2][2]=dp[1][1][0]=dp[1][1][3]=1;
    for(i=2;i<=n;i++){
    	for(j=1;j<=2*i;j++){
    		dp[i][j][0]+=dp[i-1][j][1];
    		dp[i][j][0]+=dp[i-1][j][2];
    		dp[i][j][0]+=dp[i-1][j-1][3];
    		dp[i][j][0]+=dp[i-1][j][0];
    		
    		dp[i][j][1]+=dp[i-1][j-1][0];
    		dp[i][j][1]+=dp[i-1][j][1];
    		if(j>1) dp[i][j][1]+=dp[i-1][j-2][2];
    		dp[i][j][1]+=dp[i-1][j-1][3];
    		
    		dp[i][j][2]+=dp[i-1][j-1][0];
    		if(j>1) dp[i][j][2]+=dp[i-1][j-2][1];
    		dp[i][j][2]+=dp[i-1][j][2];
    		dp[i][j][2]+=dp[i-1][j-1][3];
    		
    		dp[i][j][3]+=dp[i-1][j][1];
    		dp[i][j][3]+=dp[i-1][j][2];
    		dp[i][j][3]+=dp[i-1][j][3];
    		dp[i][j][3]+=dp[i-1][j-1][0];
    		
    		dp[i][j][1]%=mod;
    		dp[i][j][2]%=mod;
    		dp[i][j][3]%=mod;
    		dp[i][j][0]%=mod;
		}
	}
	cout<<(dp[n][m][1]+dp[n][m][2]+dp[n][m][3]+dp[n][m][0])%mod;
    return 0;
}