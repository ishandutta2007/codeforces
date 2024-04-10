#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;
const int mx = 50;
ll n, L, a[mx], b[mx];

int main()
{
    ll res = 0, ans = 1e18;
    cin >> n >> L;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i] * (1 << (n - i));
    }
    while (L > 0) {
        for (ll i = 0; i < n; ++i) {
            ll cnt = ((L + (1 << i) - 1) / (1 << i));
            ans = min(ans, a[i] * cnt + res);
        }
        ll bestpos = 0;
        for (ll i = 1; i < n; ++i) {
            if ((1 << i) <= L && b[i] < b[bestpos]) {
                bestpos = i;
            }
        }
        ll cnt = L / (1 << bestpos);
        res += (a[bestpos] * cnt);
        L -= (cnt * (1 << bestpos));
    }
    ans = min(ans, res);
    cout << ans << endl;
    return 0;
}