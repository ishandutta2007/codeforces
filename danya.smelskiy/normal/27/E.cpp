#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[1005][15];
long long a[15];
int kol;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=2;;++i) {
            bool t=false;
        for (int j=2;j*j<=i;++j)
            if (i%j==0) {
                t=true;
                break;
            }
            if (!t) {
                a[++kol]=i;
                if (kol==10) break;
            }
    }
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=10;++j)
            dp[i][j]=1e18;
    }
    dp[1][0]=1;
    for (int i=2;i<=n;++i) {
        for (int j=1;j<=10;++j){
            long long last=1;
            for (int k=1;k<=60;++k) {
                if (last*a[j]>1e18) break;
                last*=a[j];
                if (i%(k+1)) continue;
                long long z=dp[i/(k+1)][j-1];
                if (z<=(long long)(1e18)/last) dp[i][j]=min(dp[i][j],z*last);
            }
        }
    }
    long long ans=1e18;
    for (int i=0;i<=10;++i)
        ans=min(ans,dp[n][i]);
    cout<<ans;
}