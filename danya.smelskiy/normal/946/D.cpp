#include <bits/stdc++.h>
using namespace std;


int n,m,k;
string s[505];
int dp[505];
int dp2[505];
int dp3[505];
int cnt[505];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="#"+s[i];
    }
    for (int i=1;i<=n;++i) {
        memset(dp2,0,sizeof(dp2));
        memset(cnt,0,sizeof(cnt));
        for (int j=1;j<=m;++j) {
            cnt[j]=cnt[j-1];
            if (s[i][j]=='1') ++cnt[j];
        }
        cnt[m+1]=cnt[m];
        dp2[cnt[m]]=m;
        int last1=0;
        for (int j=1;j<=m;++j) {
            if (s[i][j]=='1') {
                for (int z=j;z<=m;++z) if (s[i][z]=='1') {
                    dp2[last1+cnt[m]-cnt[z]]=max(dp2[last1+cnt[m]-cnt[z]],j-1+m-z);
                }
                ++last1;
            }
        }
        memset(dp3,0,sizeof(dp3));
        for (int j=0;j<=k;++j)
        for (int z=0;j+z<=k;++z) {
            dp3[j+z]=max(dp3[j+z],dp[j]+dp2[z]);
        }
        for (int j=0;j<=k;++j)
            dp[j]=dp3[j];
    }
    int ans=0;
    for (int i=0;i<=k;++i)
        ans=max(ans,dp[i]);
    int ans2=n*m;
    ans=ans2-ans;
    cout<<ans;
}