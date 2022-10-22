#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 2e5+2, MOD = 998244353;
ll a[MN], b[MN];
ll v[MN];
int main () {
    int n; ll ans = 0;
    scan(n);
    int aa = n, bb = 1;
    for (int i = 1; i <= n; i++)
        scan(a[i]), a[i] *= aa-- * 1LL * bb++;
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) scan(b[i]);
    sort(b+1,b+n+1,greater<int>());
    for (int i = 1; i <= n; i++) ans = (ans + ((a[i]%MOD) * (b[i]%MOD))%MOD)%MOD;
    assert (ans >= 0 && ans <= MOD);
    printf ("%lld\n",ans);
    return 0;
}