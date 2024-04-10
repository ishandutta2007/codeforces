#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;


long long n,m,xx;
int dp[2][350][350];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>xx;
    if (n>m) {
        cout<<"0";
        return 0;
    }
    int x=0,y=1;
    dp[x][0][0]=1;
    for (int i=1;i<=m;++i) {
        swap(x,y);
        for (int j=0;j<=min((int)n,i);++j)
            for (int k=0;k<=j;++k)
                dp[x][j][k]=0;
        for (int j=0;j<=min((int)n,i-1);++j)
        for (int k=0;k<=j;++k) if (dp[y][j][k]){
            for (int n1=(i==xx ? 1 : 0);n1<=1 && j+n1<=n;++n1) {
                for (int n2=0;n2<=1 && k+n2<=j+n1;++n2) {
                    dp[x][n1+j][n2+k]+=dp[y][j][k];
                    if (dp[x][n1+j][n2+k]>=md) dp[x][n1+j][n2+k]-=md;
                }
            }
        }
    }
    long long ans=dp[x][n][n];
    for (long long i=1;i<=n;++i){
        ans*=i;
        ans%=md;
    }
    cout<<ans;
}