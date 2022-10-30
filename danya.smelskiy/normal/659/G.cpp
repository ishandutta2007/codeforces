#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n;
long long ans;
long long a[1000005];
long long dp[1000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        ans=(ans+a[i]-1)%md;
    }
    a[n+1]=1e9;
    a[0]=1e9;
    for (int i=1;i<=n;++i) {
        ans=(ans+dp[i]*min(a[i-1]-1,a[i]-1))%md;
        dp[i+1]=(dp[i]*min(a[i]-1,min(a[i-1]-1,a[i+1]-1)))%md;
        dp[i+1]=(dp[i+1]+min(a[i]-1,a[i+1]-1))%md;
    }
    cout<<ans;
}