#include <bits/stdc++.h>
using namespace std;

string s;
long long dp[55][10];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=0;i<=9;++i)
        dp[1][i]=1;
    for (int i=2;i<=s.size();++i) {
        for (int j=0;j<=9;++j) {
            int ss=(s[i-1]-'0'+j);
            dp[i][ss/2]+=dp[i-1][j];
            if (ss&1) dp[i][ss/2+1]+=dp[i-1][j];
        }
    }
    long long ans=0;
    for (int i=0;i<=9;++i)
        ans+=dp[(int)s.size()][i];
    for (int i=2;i<=s.size();++i) {
        int ss=s[i-1]-'0'+s[i-2]-'0';
        if (ss/2==(s[i-1]-'0') || (ss+1)/2==(s[i-1]-'0')) {

        } else break;
        if (i==s.size()) --ans;
    }
    if (s.size()==1) --ans;
    cout<<ans;
}