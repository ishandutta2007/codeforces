#include <bits/stdc++.h>
using namespace std;


long long n,W,B,X;
long long a[1005];
long long b[1005];
pair<bool,long long > dp[1005][10005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>W>>B>>X;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    dp[0][0]=make_pair(true,W);
    for (int i=0;i<n;++i) {
        for (int j=0;j<=10000;++j)
        if (dp[i][j].first) {
            long long mana=dp[i][j].second+X;
            if (mana>W+1ll*j*B) mana=W+1ll*j*B;
            if (dp[i+1][j].first==false || dp[i+1][j].second<mana) dp[i+1][j]=make_pair(true,mana);
            for (int k=1;k<=a[i+1] && mana>=b[i+1];++k) {
                mana-=b[i+1];
                if (dp[i+1][j+k].first==false || dp[i+1][j+k].second<mana) {
                    dp[i+1][j+k]=make_pair(true,mana);
                }
            }
        }
    }
    int ans=0;
    for (int i=0;i<=1e4;++i)
    if (dp[n][i].first) {
        ans=i;
    }
    cout<<ans;
}