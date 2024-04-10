#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll total_coins = 0;
    ll here = 0;
    for(int i = 0; i < k; ++i) {
        ll a, b;
        cin >> a >> b;
        total_coins += b;
        here += (a - 1) * b;
        here %= n;
    }
    ll total = (n - 1) * n / 2;
    total %= n;
    if(n > total_coins) {
        cout << 1 << '\n';

    } else if(n < total_coins) {
        cout << -1 << '\n';
    } else {
        cout << (total == here ? 1 : -1) << '\n';
    }
}