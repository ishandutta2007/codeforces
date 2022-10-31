#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int p[5001][5001];
int dp[5001][5001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=1;i<=s.size();++i) {
        int l=i;
        int r=i;
        while (l>0 && r<=s.size() && s[l-1]==s[r-1]) {
            p[l][r]=1;
            ++r; --l;
        }
        l=i;
        r=i+1;
        while (l>0 && r<=s.size() && s[l-1]==s[r-1]) {
            p[l][r]=1;
            ++r; --l;
        }
    }
    for (int j=1;j<=s.size();++j) {
        for (int i=j;i>0;--i) {
            dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+p[i][j];
        }
    }
    cin>>n;
    for (int i=1;i<=n;++i) {
        int x,y;
        cin>>x>>y;
        cout<<dp[x][y]<<'\n';
    }
}