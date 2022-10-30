#include <bits/stdc++.h>
using namespace std;
string s,ss;
int dp[200005][3];
long long ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    for (int i=s.size();i>0;--i) {
        dp[i][0]=dp[i+1][0];
        dp[i][1]=dp[i+1][1];
        if (s[i-1]=='0') ++dp[i][0];
        else ++dp[i][1];
    }
    for (int i=1;i<=ss.size();++i)
    if (ss[i-1]=='0') {
        int l=max(1,(int)s.size()-(int)ss.size()+i);
        int r=min(i,(int)s.size())+1;
        ans+=dp[l][1]-dp[r][1];
    } else {
        int l=max(1,(int)s.size()-(int)ss.size()+i);
        int r=min(i,(int)s.size())+1;
        ans+=dp[l][0]-dp[r][0];
    }
    cout<<ans;
}