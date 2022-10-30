#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int t;
int dp[52][1005][1005];
int dp2[52][1005];
int c[1501][60];
long long f[100];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    dp[0][0][1]=1;
    f[0]=1;
    for (long long i=1;i<=50;++i)
        f[i]=(f[i-1]*i)%md;
    for (int i=0;i<=50;++i) {
        for (int j=0;j<=1001;++j) {
            long long sum=0;
            for (int k=0;k<=1001;++k) {
                sum=sum+dp[i][j][k];
                if (sum>md) sum-=md;
                if (j+k<=1000) {
                    dp[i+1][j+k][k+1]=dp[i+1][j+k][k+1]+sum;
                    if (dp[i+1][j+k][k+1]>md) dp[i+1][j+k][k+1]-=md;
                }
            }
            for (int k=1;k<=1001;++k) {
                dp2[i][j]=(dp2[i][j]+dp[i][j][k]);
                if (dp2[i][j]>md) dp2[i][j]-=md;
            }
            dp2[i][j]=(dp2[i][j]*f[i])%md;
        }
    }
    c[0][0]=1;
    for (int i=1;i<=1500;++i)
    for (int j=0;j<=min(55,i);++j) {
        c[i][j]=c[i-1][j];
        if (j) c[i][j]+=c[i-1][j-1];
        if (c[i][j]>=md) c[i][j]-=md;
    }

    for (int i=1;i<=t;++i) {
        int x,y;
        cin>>x>>y;
        long long res=0;
        if (y>50) {
            cout<<"0"<<'\n';
            continue;
        }
        for (int i=0;i<=x;++i)
            res=(res+(long long)((long long)dp2[y][i]*(long long)c[x-i+y][y])%md)%md;
        cout<<res<<'\n';
    }
}