#include <bits/stdc++.h>
using namespace std;

int n;
pair<long long,long long> a[3005];
long long dp[3005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1);
    dp[0]=0;
    for (int i=1;i<=n;++i){
        dp[i]=1e18;
        a[i].first+=a[i-1].first;
    }
    for (int i=1;i<=n;++i) {
        dp[i]=dp[i-1]+a[i].second;
        for (int j=i-1;j>0;--j){
            dp[i]=min(dp[i],dp[j-1]+a[j].second+a[i].first-a[j].first-(a[j].first-a[j-1].first)*(i-j));
        }
//        cout<<dp[i]<<" ";
    }
    cout<<dp[n];
}