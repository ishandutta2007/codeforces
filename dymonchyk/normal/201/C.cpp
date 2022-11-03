#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int arr[100005];
long long dp[2][100005];
long long dp2[2][100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;++i)
        scanf("%d",&arr[i]);
    dp[0][n-1]=dp[1][n-1]=0;
    for(int i=n-2;i>=0;--i) {
        int cnt=arr[i];
        if (cnt>1) dp[0][i]=(cnt-(cnt&1))+dp[0][i+1];
        if (cnt) dp[1][i]=(cnt-(cnt%2==0 ? 1 : 0))+max(dp[0][i+1],dp[1][i+1]);
        dp[1][i]=max(dp[1][i],dp[0][i]);
    }
    dp2[0][0]=dp2[1][0]=0;
    for(int i=1;i<n;++i) {
        int cnt=arr[i-1];
        if (cnt>1) dp2[0][i]=(cnt-(cnt&1))+dp2[0][i-1];
        if (cnt) dp2[1][i]=(cnt-(cnt%2==0 ? 1 : 0))+max(dp2[0][i-1],dp2[1][i-1]);
        dp2[1][i]=max(dp2[1][i],dp2[0][i]);
    }
    long long ans2=0;
    for(int i=0;i<n;++i) {
        ans2=max(ans2,dp[1][i]+dp2[1][i]);
    }
    cout << ans2 << endl;
    return 0;
}