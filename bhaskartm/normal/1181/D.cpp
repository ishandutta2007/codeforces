#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=5e5+5;
ll n,m,q,a[MAXN],cnt[MAXN],loc[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin>>n>>m>>q;
    for (int i=1; i<=n; ++i) {
        cin>>a[i];
        loc[i]=cnt[a[i]]*m+a[i];
        ++cnt[a[i]];
    }
    sort(loc+1,loc+1+n);
    for (int i=1; i<=n; ++i) loc[i]-=i;
    while (q--) {
        ll k; cin>>k; k-=n;
        ll x=lower_bound(loc+1,loc+1+n,k)-loc;
        ll ans=(k+x-1)%m;
        if (ans==0) ans=m;
        cout<<ans<<"\n";
    }
    return 0;
}