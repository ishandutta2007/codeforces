#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int dp[10005];

int main() {
    cin>>n;
    cin>>s;
    for (int i=2;i<=n;++i) {
        dp[i]=dp[i-1];
        if (s[i-1]!=s[i-2]) {
            dp[i]=max(dp[i],1);
            dp[i]=max(dp[i],dp[i-2]+1);
        }
    }
    cout<<n-dp[n];
}