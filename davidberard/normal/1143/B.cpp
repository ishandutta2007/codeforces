#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll compute(ll n) {
    ll ans = 1;
    for (; n; n/=10) {
        ans *= n%10;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ans = compute(n);
    for (ll i = 0, d=1; i<10; ++i, d*=10) {
        ll cv = ((n/d)%10)*d;
        cv += d;
        n -= cv;
        if (n < 1) break;
        ans = max(ans, compute(n));
    }
    cout << ans << endl;
    return 0;
}