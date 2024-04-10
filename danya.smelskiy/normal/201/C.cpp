#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[100005];
long long ans;
long long l[100005];
long long r[100005];
long long o[100005];
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (long long i=2;i<=n;++i)
        cin>>a[i];
    for (long long i=2;i<=n;++i) {
        if (a[i]>1) l[i]=l[i-1]+(a[i] - ((a[i]&1) ? 1 : 0));
    }
    for (long long i=n-1;i>0;--i) {
        if (a[i+1]>1) r[i]=r[i+1]+(a[i+1]-((a[i+1]&1) ? 1 : 0));
    }
    for (long long i=2;i<=n;++i) {
        o[i]=o[i-1]+(a[i] - ((a[i]&1)==0 ? 1 : 0));
    }
    long long mx=0;
    for (long long i=2;i<=n;++i) {
        mx=max(mx,l[i]-o[i]);
        ans=max(ans,mx+r[i]+o[i]);
    }
    cout<<ans;
}