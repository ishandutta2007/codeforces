#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calc(ll x) {
    ll ans1 = 0, L = 0, R = 1e9;
    while (L <= R) {
        ll mid = (L + R) >> 1;
        if (mid * mid <= x) L = mid + 1, ans1 = mid;
        else R = mid - 1;
    }
    ll ans2 = 0;
    L = 0, R = 1e9;
    while (L <= R) {
        ll mid = (L + R) >> 1;
        if (mid * mid + mid <= x) L = mid + 1, ans2 = mid;
        else R = mid - 1;
    }
    ll ans3 = 0;
    L = 0, R = 1e9;
    while (L <= R) {
        ll mid = (L + R) >> 1;
        if (mid * mid + 2 * mid <= x) L = mid + 1, ans3 = mid;
        else R = mid - 1;
    }
    // cerr << x << ' ' << ans1 + ans2 + ans3 << endl;
    return ans1 + ans2 + ans3;
}
void rmain() {
    ll l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", calc(r) - calc(l - 1));
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}