#include <bits/stdc++.h>
using namespace std;
long long n,dp[100001][4],a[100000];
int main(){
    cin>>n;
    cin>>a[1];
    if (a[1]==1 || a[1]==3) dp[1][2]=1;
    if (a[1]==2 || a[1]==3) dp[1][1]=1;
    for (int i=2;i<=n;++i){
        cin>>a[i];
        if (a[i]==2||a[i]==3) dp[i][1]=max(dp[i-1][2],dp[i-1][0])+1;
        if (a[i]==1||a[i]==3) dp[i][2]=max(dp[i-1][1],dp[i-1][0])+1;
        dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
    }
    cout<<n-max(dp[n][0],max(dp[n][1],dp[n][2]));
}