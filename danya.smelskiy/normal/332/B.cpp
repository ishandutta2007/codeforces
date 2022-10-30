#include <bits/stdc++.h>
using namespace std;

int n,m;
pair<int,int> dp[300001];
long long a[300001];
long long b[300001];
int r[300001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        a[i]+=a[i-1];
        if (i>=m) b[i]=a[i]-a[i-m];
        if (i>=m) {
            if (b[i]>b[r[i-1]]) r[i]=i;
            else r[i]=r[i-1];
        }
    }
    dp[m]=make_pair(0,m);
    for (int i=m+1;i<=n;++i){
        int x=r[i-m];
        long long y=b[x];
        long long z=b[i];
        if (y<=z) dp[i]=make_pair(x,i);
        else dp[i]=make_pair(i,x);
        if (b[dp[i-1].first]+b[dp[i-1].second]>=y+z) dp[i]=dp[i-1];
    }
    if (dp[n].first>dp[n].second) swap(dp[n].first,dp[n].second);
    cout<<dp[n].first-m+1<<" "<<dp[n].second-m+1;
}