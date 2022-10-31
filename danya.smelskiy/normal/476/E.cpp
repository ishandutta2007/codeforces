#include <bits/stdc++.h>
using namespace std;

string s,ss;
int a[2005];
int dp[2005][2005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    int n=s.size(),m=ss.size();
    for (int i=0;i<n;++i) {
        int j=0;
        int k;
        for (k=i;k<n && j<m;++k)
            if (s[k]==ss[j]) ++j;
        if (j==m) a[i+1]=k;
        else a[i+1]=-1;
    }
    for (int i=1;i<=n;++i)
    for (int j=0;j<i;++j) {
        dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
        if (a[i]!=-1) dp[a[i]+1][j+(a[i]-i+1-m)]=max(dp[a[i]+1][j+a[i]-i+1-m],dp[i][j]+1);
    }
    for (int i=0;i<=n;++i)
        cout<<dp[n+1][i]<<" ";
}