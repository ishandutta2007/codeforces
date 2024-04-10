#include <bits/stdc++.h>
using namespace std;

string s,ss;
int n;
long long a,b,md=1e9+7;
long long dp[100005][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss>>n;
    for (int i=1;i<=s.size();++i) {
        string sk="";
        for (int j=i;j<=s.size();++j)
            sk+=s[j-1];
        for (int j=1;j<i;++j)
            sk+=s[j-1];
        if (sk==ss) ++a;
        else ++b;
    }
    if (s==ss) dp[0][0]=1;
    else dp[0][1]=1;
    for (int i=1;i<=n;++i) {
        if (a) dp[i][0]=(dp[i-1][0]*(a-1)+dp[i-1][1]*a)%md;
        if (b) dp[i][1]=(dp[i-1][1]*(b-1)+dp[i-1][0]*b)%md;
    }
    cout<<dp[n][0];
}