#include <bits/stdc++.h>
using namespace std;
string s;
int kol[100];
pair<int,int> xx,yy;
int ans;
int dp[2606][2606];
pair<int,int> pred[2606][2606];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    if (s.size()>=2600) {
        for (int i=0;i<s.size();++i)
            ++kol[s[i]-'a'];
        for (int i=0;i<26;++i)
        if (kol[i]>=100) {
            for (int j=0;j<100;++j)
                cout<<char(i+'a');
            return 0;
        }
    }
    int n=s.size();
    xx=yy=make_pair(-1,-1);
    for (int i=2;i<=n;++i) {
        for (int j=1;j<=n-i+1;++j) {
            pred[j][j+i-1]=make_pair(j,j+i-2);
            dp[j][j+i-1]=dp[j][j+i-2];
            if (dp[j+1][j+i-1]>dp[j][j+i-1]) {
                dp[j][j+i-1]=dp[j+1][j+i-1];
                pred[j][j+i-1]=make_pair(j+1,j+i-1);
            }
            if (s[j-1]==s[j+i-2] && dp[j+1][j+i-2]+1>dp[j][j+i-1]) {
                dp[j][j+i-1]=dp[j+1][j+i-2]+1;
                pred[j][j+i-1]=make_pair(j+1,j+i-2);
            }
            if (dp[j][j+i-1]==1 && s[j-1]==s[j+i-2]) pred[j][j+i-1]=make_pair(-1,-1);
            if (dp[j][j+i-1]>ans) {
                ans=dp[j][j+i-1];
                xx=make_pair(j,j+i-1);
            }
            if (dp[j][j+i-1]==50) {
                yy=make_pair(j,j+i-1);
            }
        }
    }
    if (xx==make_pair(-1,-1)) {
        cout<<s[0];
        return 0;
    }
    if (yy!=make_pair(-1,-1)) {
    xx=yy;
    string res="";
    while (xx!=make_pair(-1,-1)) {
        if (xx.first==xx.second) break;
        if (pred[xx.first][xx.second]==make_pair(-1,-1) || dp[xx.first][xx.second]==dp[pred[xx.first][xx.second].first][pred[xx.first][xx.second].second]+1)
        res+=s[xx.first-1];
        xx=pred[xx.first][xx.second];
    }
    string res2=res;
    reverse(res2.begin(),res2.end());
    if (xx!=make_pair(-1,-1) && xx.first==xx.second) res+=s[xx.first-1];
    res+=res2;
    cout<<res;
    return 0;
    }
    xx=yy=make_pair(-1,-1);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n-i+1;++j) {
            pred[j][j+i-1]=make_pair(j,j+i-2);
            dp[j][j+i-1]=dp[j][j+i-2];
            if (dp[j+1][j+i-1]>dp[j][j+i-1]) {
                dp[j][j+i-1]=dp[j+1][j+i-1];
                pred[j][j+i-1]=make_pair(j+1,j+i-1);
            }
            if (s[j-1]==s[j+i-2] && dp[j+1][j+i-2]+(i==1 ? 1 : 2)>dp[j][j+i-1]) {
                dp[j][j+i-1]=dp[j+1][j+i-2]+(i==1 ? 1 : 2);
                pred[j][j+i-1]=make_pair(j+1,j+i-2);
            }
            if (dp[j][j+i-1]==1 && s[j-1]==s[j+i-2]) pred[j][j+i-1]=make_pair(-1,-1);
            if (dp[j][j+i-1]>ans) {
                ans=dp[j][j+i-1];
                xx=make_pair(j,j+i-1);
            }
        }
    }
    string res="";
    bool t=false;
    if (dp[xx.first][xx.second]&1) t=true;
    while (xx!=make_pair(-1,-1)) {
        if (xx.first==xx.second) break;
        if (pred[xx.first][xx.second]==make_pair(-1,-1) || dp[xx.first][xx.second]==dp[pred[xx.first][xx.second].first][pred[xx.first][xx.second].second]+2)
        res+=s[xx.first-1];
        xx=pred[xx.first][xx.second];
    }
    string res2=res;
    reverse(res2.begin(),res2.end());
    if (t) res+=s[xx.first-1];
    res+=res2;
    cout<<res;

}