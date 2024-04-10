#include <bits/stdc++.h>
using namespace std;






int n,m;
int x;
int cnt[100005];
int cnt2[100005];
int dp[5005][5005];
int cost[100005];
inline long long solve(int x,int y) {
    for (int i=1;i<=x;++i) {
        for (int j=1;j<=y;++j) {
            for (int k=1;k<=i && k<=m;++k) {
                dp[i][j]=max(dp[i][j],dp[i-k][j-1]+cost[k]);
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n*m;++i) {
        cin>>x;
        ++cnt[x];
    }
    for (int i=1;i<=n;++i) {
        cin>>x;
        ++cnt2[x];
    }
    for (int i=1;i<=m;++i)
        cin>>cost[i];
    long long ans=0;
    solve(n*m,n);
    for (int i=1;i<=1e5;++i) if (cnt[i]) {
        if (cnt[i]>=cnt2[i]*m) {
            ans+=cost[m]*cnt2[i];
            continue;
        }
        ans+=dp[cnt[i]][cnt2[i]];
    }
    cout<<ans;
}