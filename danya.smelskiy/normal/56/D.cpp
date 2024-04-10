#include <bits/stdc++.h>
using namespace std;

string s,ss;
int n,m;
int dp[1005][1005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    n=s.size();
    m=ss.size();
    for (int i=1;i<=n;++i)
        dp[i][0]=i;
    for (int j=1;j<=m;++j)
        dp[0][j]=j;
    for (int i=1;i<=n;++i)
    for (int j=1;j<=m;++j) {
        if (s[i-1]==ss[j-1]) {
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j]+1,dp[i][j-1]+1));
        } else {
            dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
        }
    }
    cout<<dp[n][m]<<'\n';
    int nn=n;
    int mm=m;
    while (nn && mm) {
        if (s[nn-1]==ss[mm-1] && dp[nn][mm]==dp[nn-1][mm-1]) {
            --nn; --mm;
            continue;
        }
        if (dp[nn-1][mm-1]==dp[nn][mm]-1) {
            cout<<"REPLACE "<<nn<<" "<<ss[mm-1]<<'\n';
            --nn; --mm;
            continue;
        }
        if (dp[nn-1][mm]==dp[nn][mm]-1) {
            cout<<"DELETE "<<nn<<'\n';
            --nn;
            continue;
        }
        cout<<"INSERT "<<nn+1<<" "<<ss[mm-1]<<'\n';
        --mm;
    }
    for (int i=1;i<=nn;++i)
        cout<<"DELETE "<<1<<'\n';
    for (int i=mm-1;i>=0;--i)
    cout<<"INSERT 1 "<<ss[i]<<'\n';
}