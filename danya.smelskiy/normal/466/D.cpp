#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n,m;
int a[2005];
long long dp[2005][2005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (a[1]==m || a[1]+1==m) dp[1][0]=1;
    if (a[1]+1==m) dp[1][1]=1;
    for (int i=2;i<=n;++i) {
        if (a[i]>m) {
            cout<<0;
            return 0;
        }
        int z=m-a[i];
        dp[i][z]=(dp[i-1][z]+(z ? dp[i-1][z-1] : 0))%md;
        if (z) {
            --z;
            dp[i][z]=((dp[i-1][z+1]+dp[i-1][z])*(1+z))%md;
        }
    }
    cout<<dp[n][0];
}