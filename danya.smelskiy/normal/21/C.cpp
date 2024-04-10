#include <bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[100005];
bool dp[100005];
long long sum;
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (long long i=1;i<=n;++i) {
        cin>>a[i];
        sum+=a[i];
    }
    if (sum%3) {
        cout<<"0";
        return 0;
    }
    sum/=3;
    long long nw=0;
    for (long long i=1;i<=n;++i) {
        nw+=a[i];
        if (nw==sum) dp[i]=true;
    }
    nw=0;
    long long z=0;
    for (long long i=n;i>0;--i) {
        nw+=a[i];
        if (dp[i-1]) ans+=z;
        if (nw==sum) ++z;
    }
    cout<<ans;
}