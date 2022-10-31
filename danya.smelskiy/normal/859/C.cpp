#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100];
long long dp[100][2];
long long s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        s+=a[i];
    }
    dp[n][1]=a[n];
    for (int i=n-1;i>0;--i) {
        dp[i][1]=max(a[i]+dp[i+1][0],dp[i+1][1]);
        dp[i][0]=min(dp[i+1][1],a[i]+dp[i+1][0]);
    }
    cout<<s-dp[1][1]<<" "<<dp[1][1];
}