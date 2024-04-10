#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
long long dp[100005][35];
int a[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) for(int j=0;j<=30;j++) dp[i][j]=LLONG_MIN/10;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=30;j++) {
                int now = a[i];
                for(int l=1;l<=j;l++) now/=2;
                dp[i][min(30,j + 1)] = max(dp[i][min(30,j+1)],dp[i - 1][j]+now/2);
                dp[i][j]=max(dp[i][j],dp[i-1][j]+now-k);
            }
        long long ans=0;
        for(int i=0;i<=30;i++) ans=max(ans,dp[n][i]);
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map
//cf