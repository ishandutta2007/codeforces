#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int dp[27][27];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s;
        int x=s[0]-'a';
        int y=s[(int)s.size()-1]-'a';
        for (int j=0;j<26;++j)
            if (dp[j][x]) dp[j][y]=max(dp[j][y],dp[j][x]+(int)s.size());
        dp[x][y]=max(dp[x][y],(int)s.size());
    }
    int ans=0;
    for (int i=0;i<26;++i)
        ans=max(ans,dp[i][i]);
    cout<<ans;
}