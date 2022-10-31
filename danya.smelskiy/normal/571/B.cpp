#include <bits/stdc++.h>
using namespace std;

int n,k;
long long a[300001];
long long dp[5001][5001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=0;i<=k-(n%k);++i)
        for (int j=0;j<=n%k;++j)
            dp[i][j]=1e18;
    dp[0][0]=0;
    int sz=n/k;
    for (int i=0;i<=k-(n%k);++i)
    for (int j=0;j<=n%k;++j) {
        if (i<k-n%k) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+abs(a[i*sz+j*(sz+1)+sz]-a[i*sz+j*(sz+1)+1]));
        if (j<(n%k)) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+abs(a[i*sz+j*(sz+1)+sz+1]-a[i*sz+j*(sz+1)+1]));
    }
    cout<<dp[k-n%k][n%k];
}