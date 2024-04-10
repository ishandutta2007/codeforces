#include <bits/stdc++.h>
using namespace std;
int n;
int dp[500005];
pair<int,int> a[500005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].second>>a[i].first;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        dp[i]=max(1,dp[i-1]);
        int l=1;
        int r=i-1;
        if (i==1) {
            dp[i]=1;
            continue;
        }
        while (l<r-1) {
            int mid=(l+r)>>1;
            if (a[mid].first<a[i].second)l=mid;
            else r=mid;
        }
        if (a[r].first<a[i].second) l=r;
        if (a[l].first<a[i].second) dp[i]=max(dp[i],dp[l]+1);
    }
    cout<<dp[n];
}