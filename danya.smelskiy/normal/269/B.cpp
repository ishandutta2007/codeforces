#include <bits/stdc++.h>
using namespace std;


int n,m;
pair<long double,int> a[5005];
int dp[5005];
int ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i].second>>a[i].first;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        int z=a[i].second;
        dp[z]++;
        for (int j=1;j<z;++j)
            dp[z]=max(dp[z],dp[j]+1);
    }
    for (int i=1;i<=n;++i)
        ans =  (dp[i]>ans ? dp[i] : ans);
    cout<<n-ans;
}