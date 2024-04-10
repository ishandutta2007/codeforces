#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

string s,ss;
int p[300005];
long long dp[300005];
long long dp2[300005];
long long ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    string sk=ss+"#"+s;
    for (int i=1;i<sk.size();++i) {
        int j=p[i-1];
        while (j && sk[j]!=sk[i]) j=p[j-1];
        if (sk[j]==sk[i]) ++j;
        p[i]=j;
    }
    int last=-1;
    dp[(int)ss.size()]=1;
    dp2[(int)ss.size()]=1;
    for (int i=ss.size()+1;i<sk.size();++i) {
        dp[i]=dp[i-1];
        if (p[i]==ss.size()) last=i-ss.size();
        if (last!=-1) {
            dp[i]=(dp[i]+dp2[last])%md;
            ans=(ans+dp2[last])%md;
        }
        dp2[i]=(dp2[i-1]+dp[i])%md;
    }
    cout<<ans;
}