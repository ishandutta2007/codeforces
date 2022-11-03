#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll mask = 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13;

ll a, b;
ll k;
bool us[mask];
ll ans = 0;

ll step(ll p, ll c) {
    ll m = p - 1;
    for (int i = 2; i <= k; ++i) 
        if (p - (p % i) >= c) {
            m = min(m, p - (p % i));
        }
    return m;
}

void go(ll v) {
    us[v] = 1;
    ll s = step(v, -INF);
    if (s < 0)
        s += mask;
    if (us[s]) {
        v = a;
        while (true) {
            if (v == b) {
                return;
            }
            if ((v % mask) == s) {
                break;
            }
            v = step(v, b);
            ++ans;
        }
        ll len = 0;
        ll v2 = s % mask;
        while (true) {
            v2 = step(v2, -INF);
            if (v2 < 0) 
                v2 += mask;
            ++len;
            if (v2 == s) break;
        }
        ans += (v - b) / mask * len;
        v -= ((v - b) / mask) * mask;
        while (true) {
            if (v == b) {
                return;
            }
            v = step(v, b);
            ++ans;
        }
    } else {
        go(s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> k;
    go(a % mask);
    cout << ans << endl;
    return 0;
}