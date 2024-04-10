#include <bits/stdc++.h>
using namespace std;


int n;
int a[3005][3];
long long dp[3005][3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<3;++i) {
        for (int j=1;j<=n;++j)
            cin>>a[j][i];
    }
    dp[1][0]=a[1][0];
    dp[1][1]=a[1][1];
    for (int i=2;i<=n;++i) {
        dp[i][0]=max(dp[i-1][1]+a[i][0],dp[i-1][0]+a[i][1]);
        dp[i][1]=max(dp[i-1][0]+a[i][2],dp[i-1][1]+a[i][1]);
    }
    cout<<dp[n][0];
}