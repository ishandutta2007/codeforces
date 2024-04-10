#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mx = 16384;
ll n, k, a[mx], temp, m;
vector<ll> xr;

int main()
{
    ll ans = 0;
    cin >> n >> k;
    for (ll i = 0; i < mx; ++i) {
        ll e = i, ans_e = 0;
        for (ll j = 0; j < 14; ++j) {
            if (e % 2 == 1) {
                ans_e++;
            }
            e = (e / 2);
        }
        if (ans_e == k)
            xr.push_back(i);
    }
    for (ll i = 0; i < mx; ++i) {
        a[i] = 0;
    }
    for (ll i = 0; i < n; ++i) {
        cin >> temp;
        a[temp]++;
    }
    for (ll i = 0; i < mx; ++i) {
        for (ll j = 0; j < xr.size(); ++j) {
            m = (i ^ xr[j]);
            if (m > i)
                ans += (a[i] * a[m]);
            if (m == i) {
                ans += ((a[i] * (a[i] - 1)) / 2);
            }
        }
    }
    cout << ans;
    return 0;
}