#include <bits/stdc++.h>
using namespace std;

int ans,n,m;
pair<pair<int,int> ,int> a[300005];
int dp[300005];
int q[300005];

inline bool cmp(pair<pair<int,int> ,int > a,pair<pair<int,int> ,int> b){
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i)
        cin>>a[i].first.first>>a[i].first.second>>a[i].second;
    sort(a+1,a+m+1,cmp);
    int i=1;
    int ans=1;
    while (i<=m) {
        if (i==m || a[i].second!=a[i+1].second) {
            int j=i;
            while (j && a[j].second==a[i].second) {
                int x=a[j].first.first;
                int y=a[j].first.second;
                int xx=dp[x];
                q[y]=max(q[y],xx+1);
                --j;
            }
            j=i;
            while (j && a[j].second==a[i].second) {
                int x=a[j].first.first;
                int y=a[j].first.second;
                dp[y]=max(dp[y],q[y]);
                --j;
            }
            ++i;
        } else ++i;
    }
    for (int i=1;i<=n;++i)
        ans=max(ans,dp[i]);
    cout<<ans;
}