#include <bits/stdc++.h>
using namespace std;

int a,b,c;
long double dp[101][101][101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>c;
    dp[a][b][c]=1;
    for (int i=a;i>=0;--i)
        for (int j=b;j>=0;--j)
    for (int k=c;k>=0;--k) {
        long double all=i*j+i*k+j*k;
        if (all==0) break;
        if (i) {
            dp[i-1][j][k]+=dp[i][j][k]*((long double)(i*k))/all;
        }
        if (j) {
            dp[i][j-1][k]+=dp[i][j][k]*((long double)(i*j))/all;
        }
        if (k) {
            dp[i][j][k-1]+=dp[i][j][k]*((long double)(j*k))/all;
        }
    }
    cout<<fixed<<setprecision(10);
    long double ans=0;
    for (int i=1;i<=a;++i)
        ans+=dp[i][0][0];
    cout<<ans<<" ";
    ans=0;
    for (int i=1;i<=b;++i)
        ans+=dp[0][i][0];
    cout<<ans<<" ";
    ans=0;
    for (int i=1;i<=c;++i)
        ans+=dp[0][0][i];
    cout<<ans;
}