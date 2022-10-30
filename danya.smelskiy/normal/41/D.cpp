#include <bits/stdc++.h>
using namespace std;

int n,m,k;
string s[105];
int dp[105][105][15];
pair<int,int> pred[105][105][15];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    ++k;
    for (int i=1;i<=n;++i)
        cin>>s[i];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            for (int z=0;z<k;++z)
                dp[i][j][z]=-1e9;
    for (int i=1;i<=m;++i) {
        int x=s[n][i-1]-'0';
        dp[n][i][(x%k)]=x;
    }

    for (int i=n-1;i>0;--i) {
        for (int j=1;j<=m;++j) {
            int x=s[i][j-1]-'0';
            for (int z=0;z<k;++z) {
                int nxt=(z+x)%k;
                if (j+1<=m && dp[i+1][j+1][z]+x>=dp[i][j][nxt]) {
                    dp[i][j][nxt]=dp[i+1][j+1][z]+x;
                    pred[i][j][nxt]=make_pair(j+1,z);
                }
                if (j>1 && dp[i+1][j-1][z]+x>=dp[i][j][nxt]) {
                    dp[i][j][nxt]=dp[i+1][j-1][z]+x;
                    pred[i][j][nxt]=make_pair(j-1,z);
                }
            }
        }
    }
    int mx=-1,pos1,pos2,pos3;
    for (int i=1;i<=m;++i) {
        if (dp[1][i][0]>mx) {
            mx=dp[1][i][0];
            pos1=1;
            pos2=i;
            pos3=0;
        }
    }
    if (mx==-1) {
        cout<<"-1"<<'\n';
        return 0;
    }
    cout<<mx<<'\n';
    string ans="";
    vector<pair<int,int> > v;
    for (int i=1;i<n;++i){
        int to1=pred[i][pos2][pos3].first;
        int to2=pred[i][pos2][pos3].second;
        if (to1>pos2) ans+="L";
        else ans+="R";
        pos2=to1;
        pos3=to2;
    }
    cout<<pos2<<'\n';
    reverse(ans.begin(),ans.end());
    cout<<ans;
}