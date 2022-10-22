#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 3e3+3, MOD = 1e9+7;
ll lcm (int a, int b) {
    return a*1LL*b/__gcd(a,b);
}
void solve () {
    int n;
    scanf ("%d",&n);
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) scanf ("%d",&p[i]);
    int x,a,y,b;
    scanf ("%d %d %d %d",&x,&a,&y,&b);
    if (x < y) swap(x,y), swap(a,b);
    ll all = lcm(a,b);
    sort(all(p)); reverse(all(p));
    ll k; scanf ("%lld",&k);
    auto check = [&] (int mid) {
        ll ret = 0;
        ll both = mid/all;
        for (int i = 0; i < both; i++) ret += p[i] * 1LL * (x+y) / 100;
        ll gox = mid/a - both;
        for (int i = both; i < both+gox; i++) ret += p[i] * 1LL * (x) / 100;
        ll goy = mid/b-both;
        for (int i = both+gox; i < both+gox+goy; i++) ret += p[i] * 1LL * y / 100;
        return ret >= k;
    };
    int low = 1, high = n, ans = -1, mid;
    while (low <= high) {
        mid = (low+high)/2;
        if (check(mid)) high = (ans = mid) - 1;
        else low = mid + 1;
    }
    printf ("%d\n",ans);
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}