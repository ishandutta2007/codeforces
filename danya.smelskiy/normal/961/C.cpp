#include <bits/stdc++.h>
using namespace std;


int n;
int dp[5][2];
int ans=1e9;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int k=1;k<=4;++k) {
        int c1=0,c2=0;
        for (int i=1;i<=n;++i) {
            string s;
            cin>>s;
            s="#"+s;
            for (int j=1;j<=n;++j) {
                if ((i+j)&1) {
                    if (s[j]=='0') ++c1;
                    if (s[j]=='1') ++c2;
                } else {
                    if (s[j]=='1') ++c1;
                    if (s[j]=='0') ++c2;
                }
            }
        }
        dp[k][0]=c1;
        dp[k][1]=c2;
    }
    for (int i=1;i<=4;++i) {
        for (int j=1;j<=4;++j)
        if (i!=j) {
            for (int k=1;k<=4;++k)
            if (k!=i && k!=j) {
                for (int z=1;z<=4;++z) if (z!=i && z!=j && z!=k) {
                    ans=min(ans,dp[i][0]+dp[j][1]+dp[k][1]+dp[z][0]);
                    ans=min(ans,dp[i][1]+dp[j][0]+dp[k][0]+dp[z][1]);
                }
            }
        }
    }
    cout<<ans;
}