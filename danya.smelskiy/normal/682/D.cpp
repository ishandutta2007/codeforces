#include <bits/stdc++.h>
using namespace std;

int n,m,k;
string s,ss;
int dp[1505][1505][12][2];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    ++n; ++m;
    cin>>s>>ss;
    s="#"+s;
    ss="."+ss;
    for (int i=0;i<n;++i)
    for (int j=0;j<m;++j)
    for (int kk=0;kk<=k;++kk)
    for (int z=0;z<2;++z) {
        if (i+1<n && j+1<m && s[i+1]==ss[j+1]) {
            if (z==0) dp[i+1][j+1][kk+1][1]=max(dp[i][j][kk][z]+1,dp[i+1][j+1][kk+1][1]);
            else {
                if (kk && z && dp[i][j][kk][1]) dp[i+1][j+1][kk][1]=max(dp[i][j][kk][z]+1,dp[i+1][j+1][kk][1]);
                else if ((kk && dp[i][j][kk][z]) || (kk==0 && z==0)) dp[i+1][j+1][kk+1][1]=max(dp[i][j][kk][z]+1,dp[i+1][j+1][kk+1][1]);
            }
        }
        dp[i+1][j][kk][0]=max(dp[i+1][j][kk][0],dp[i][j][kk][z]);
        dp[i][j+1][kk][0]=max(dp[i][j+1][kk][0],dp[i][j][kk][z]);
    }
    cout<<max(dp[n-1][m-1][k][0],dp[n-1][m-1][k][1]);
}