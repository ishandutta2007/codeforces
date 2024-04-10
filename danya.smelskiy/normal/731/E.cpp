#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005];
long long p[200005];
long long dp[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    long long mx=p[n];
    for (int i=n-1;i>0;--i) {
        dp[i]=mx;
        mx=max(mx,p[i]-dp[i]);
    }
    cout<<dp[1];
}