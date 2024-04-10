#include <bits/stdc++.h>
using namespace std;

long long n;
string s;
long long dp[200];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for (int i=1;i<=s.size();++i)
        dp[i]=1e18;
    for (int i=0;i<s.size();++i) if (dp[i]<(1e18)/n){
        if (s[i]=='0') dp[i+1]=min(dp[i+1],dp[i]*n);
        else {
            long long res=0;
            for (int j=i;j<s.size();++j) {
                res=res*10+(s[j]-'0');
                if (res>=n) break;
                dp[j+1]=min(dp[j+1],dp[i]*n+res);
            }
        }
    }
    cout<<dp[(int)s.size()];
}