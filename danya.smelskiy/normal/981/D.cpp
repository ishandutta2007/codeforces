#include <bits/stdc++.h>
using namespace std;


int n,m;
long long ans;
long long a[505];
bool dp[505][505];

inline bool solve(long long res) {
    memset(dp,false,sizeof(dp));
    dp[0][0]=true;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            long long s=0;
            for (int k=i;k>0;--k) {
                s+=a[k];
                if ((s&res)==res) dp[i][j]|=dp[k-1][j-1];
            }
        }
    }
    return dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (long long i=60;i>=0;--i) {
        long long cur=ans;
        cur|=(1ll<<i);
        if (solve(cur)) ans=cur;
    }
    cout<<ans;
}