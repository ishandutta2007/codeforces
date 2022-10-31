#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000001];
long long dp[1000005];
vector<int> q;
long long ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i) {
        if (i==1 || (a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])) q.push_back(i);
        for (int j=max(0,i-5);j<i;++j)
            dp[i]=max(dp[i],dp[j]+abs(a[i]-a[j+1]));
        for (int j=0;j<=5;++j) {
            if (j>=q.size()) break;
            int x=q.size()-j-1;
            if (q[x]<i) dp[i]=max(dp[i],dp[q[x]]+abs(a[i]-a[q[x]+1]));
            dp[i]=max(dp[i],dp[q[x]-1]+abs(a[i]-a[q[x]]));
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}