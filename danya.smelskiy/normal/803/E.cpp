#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
bool dp[1005][2005];
int pred[1005][2005];
string ans;
int last;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    dp[0][m]=true;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m+m-1;++j) if (dp[i-1][j]){
            if (s[i-1]=='L') {
                dp[i][j-1]=true;
                pred[i][j-1]=j;
            } else if (s[i-1]=='W') {
                dp[i][j+1]=true;
                pred[i][j+1]=j;
            } else if (s[i-1]=='D') {
                dp[i][j]=true;
                pred[i][j]=j;
            } else {
                dp[i][j-1]=true;
                pred[i][j-1]=j;
                dp[i][j+1]=true;
                pred[i][j+1]=j;
                dp[i][j]=true;
                pred[i][j]=j;
            }
        }
    }
    if (dp[n][0]==false && dp[n][m+m]==false) cout<<"NO";
    else {
        if (dp[n][0]) last=0;
        else last=m+m;
        for (int i=n;i>0;--i){
            if (last-pred[i][last]==-1) ans+="L";
            else if (last-pred[i][last]==1) ans+="W";
            else ans+="D";
            last=pred[i][last];
        }
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }
}