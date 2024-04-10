#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int dp[1505][1505][27];
int dp2[1505][27];
int x;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    cin>>m;
    for (int i=1;i<=n;++i) {
        int x=s[i-1]-'a';
        for (int j=0;j<=i;++j) {
            for (int k=0;k<26;++k) {
                if (k==x) {
                    dp[i][j][k]=dp[i-1][j][k]+1;
                } else if (j) {
                    dp[i][j][k]=dp[i-1][j-1][k]+1;
                }
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=0;j<=n;++j)
            for (int k=0;k<26;++k)
                dp2[j][k]=max(dp2[j][k],dp[i][j][k]);
    }
    for (int i=1;i<=n;++i)
        for (int j=0;j<26;++j)
        dp2[i][j]=max(dp2[i][j],dp2[i-1][j]);
    for (int i=1;i<=m;++i) {
        cin>>x;
        char c;
        cin>>c;
        cout<<dp2[x][c-'a']<<'\n';
    }
}