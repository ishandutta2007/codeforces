#include <bits/stdc++.h>
using namespace std;
const long long md=998244353;

int n,k;
long long dp[505][505];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    dp[0][0]=1;
    int len;
    for (int i=1;i<=n;++i) {
        for (int j=i;j>0;--j) {
            len=i-j+1;
            for (int k=0;k<=len;++k) {
                dp[i][len]+=dp[j-1][k];
                if (dp[i][len]>=md) dp[i][len]-=md;
            }
            for (int k=len+1;k<=n;++k) {
                dp[i][k]+=dp[j-1][k];
                if (dp[i][k]>=md) dp[i][k]-=md;
            }
        }
    }
    long long res=0;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) if (i*j<k) {
            res+=dp[n][i]*dp[n][j];
            res%=md;
        }
    }
    res+=res;
    res%=md;
    cout<<res;

}