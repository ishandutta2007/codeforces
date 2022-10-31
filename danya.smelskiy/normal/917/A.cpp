#include <bits/stdc++.h>
using namespace std;

string s;
int n,ans;
bool dp[5005][5005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    for (int i=1;i<=n;++i) {
        int cnt=0;
        for (int j=i;j<=n;++j) {
            if (s[j-1]==')') --cnt;
            else ++cnt;
            if (cnt<0) break;
            dp[i][j]=true;
        }
    }
    for (int i=n;i>0;--i) {
        int cnt=0;
        for (int j=i;j>0;--j) {
            if (s[j-1]=='(') --cnt;
            else ++cnt;
            if (cnt<0) break;
            if (((i-j+1)&1)==0 && dp[j][i]) ++ans;
        }
    }
    cout<<ans;
}