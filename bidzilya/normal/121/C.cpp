#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

ll n, k;
ll ans = 0;
ll c[111], a[111];

void build() {
    c[0] = 0;
    c[1] = 1;
    for (int i = 2; i <= 100; ++i)
        if (i * c[i - 1] > k) {
            c[i] = k + 1;
        } else {
            c[i] = c[i - 1] * i;
        }
    ll us[111];
    for (int i = 0; i <= 100; ++i)
        us[i] = 0;
    for (ll i = max(n - 100, 1LL); i < n; ++i) {
        bool found = 0;
        for (ll j = max(n - 100, 1LL); j <= n; ++j)
            if (!us[n - j] && k > c[n - i]) {
                k -= c[n - i];
            } else if (!us[n - j] && k <= c[n - i]) {
                us[n - j] = 1;
                a[n - i] = j;
                found = 1;
                break;
            }
        if (!found) {
            cout << -1 << endl;
            exit(0);
        }
    }
    if (k != 1) {
        cout << -1 << endl;
        exit(0);
    }
    for (ll j = max(n - 100, 1LL); j <= n; ++j)
            if (!us[n - j]) {
                us[n - j] = 1;
                a[0] = j;
                break;
            }
}

int happy(ll x) {
    if (!x) return 0;
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) return 0;
        x /= 10;
    }
    return 1;
}

void go(ll x) {
    if (x > n) return;
    if (x >= n - 100) {
        if (happy(a[n - x]))
            ++ans;
    } else {
        if (x) ++ans;
    }
    go(x * 10 + 4);
    go(x * 10 + 7);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> n >> k;
    build();
    go(0);
    cout << ans << endl;
    return 0;
}