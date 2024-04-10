#include <bits/stdc++.h>
using namespace std;

int n,m;
int x;
int res;
bool ans[101][101][101][2];
int dp[101][101][101][2];
vector<int> a,b,c;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        string s;
        int x;
        cin>>s>>x;
        if (s=="ATK") a.push_back(x);
        else b.push_back(x);
    }
    for (int i=1;i<=m;++i) {
        cin>>x;
        c.push_back(x);
    }
    sort(c.begin(),c.end());
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    dp[0][0][0][0]=0;
    ans[0][0][0][0]=true;
    for (int i=0;i<=a.size();++i)
        for (int j=0;j<=b.size();++j)
    for (int k=0;k<=c.size();++k) for (int z=0;z<2;++z) if (ans[i][j][k][z]) {
        if (z==0) res=max(res,dp[i][j][k][z]);
        if (z==1 && i==a.size() && j==b.size()) res=max(res,dp[i][j][k][z]);
        if (k==c.size()) continue;
        ans[i][j][k+1][z]=true;
        if (i<a.size() && a[i]<=c[k]) ans[i+1][j][k+1][z]=true;
        if (j<b.size() && b[j]<c[k]) ans[i][j+1][k+1][z]=true;
        dp[i][j][k+1][z]=max(dp[i][j][k+1][z],dp[i][j][k][z]);
        if (i==a.size() && j==b.size()) dp[i][j][k+1][z]=max(dp[i][j][k+1][z],dp[i][j][k][z]+c[k]);
        if (i<a.size() && a[i]<=c[k]) dp[i+1][j][k+1][z]=max(dp[i+1][j][k+1][z],dp[i][j][k][z]+c[k]-a[i]);
        if (j<b.size() && b[j]<c[k]) dp[i][j+1][k+1][z]=max(dp[i][j+1][k+1][z],dp[i][j][k][z]);
        ans[i][j][k+1][1]=true;
        dp[i][j][k+1][1]=max(dp[i][j][k+1][1],dp[i][j][k][z]+c[k]);
    }
    cout<<res;
}