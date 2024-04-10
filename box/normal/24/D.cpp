#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, (a))
#define rep1(i, a) iter(i, 1, (a)+1)
double dp[1005][1005];
int main() {
    ios_base::sync_with_stdio(false); 
	cin.tie(0);
	int n,m,x,y;cin>>n>>m>>x>>y;
    if(m==1)for(int i=n-1;i>=1;i--)rep(it,100)dp[i][0]=(dp[i+1][0]+dp[i][0])/2+1;
    else for(int i=n-1;i>=1;i--)rep(it,100){
        dp[i][0]=(dp[i+1][0]+dp[i][0]+dp[i][1])/3+1;
        rep1(j,m-2)dp[i][j]=(dp[i+1][j]+dp[i][j-1]+dp[i][j]+dp[i][j+1])/4+1;
        dp[i][m-1]=(dp[i+1][m-1]+dp[i][m-2]+dp[i][m-1])/3+1;
    }
    cout<<fixed<<setprecision(10)<<dp[x][y-1]<<endl;
    return 0;
}