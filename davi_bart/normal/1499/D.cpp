#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int gcd_extend(int a, int b, int& x, int& y) {
    // Base Case
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    // Recursively find the gcd
    else {
        int g = gcd_extend(b, a % b, x, y);
        int x1 = x, y1 = y;
        x = y1;
        y = x1 - (a / b) * y1;
        return g;
    }
}
vector<int> q(20000010, 0);
int solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int g = gcd(a, b);
    if (c % g != 0) return 0;
    a /= g;
    b /= g;
    c /= g;
    vector<int> d;
    for (int i = 1; i * i <= c; i++) {
        if (c % i == 0) {
            d.pb(i);
            if (i * i != c) d.pb(c / i);
        }
    }
    int ans = 0;
    for (int x : d) {
        int o = c / x + b;
        if (o % a != 0) continue;
        int k = o / a;
        // cout << "k::" << k;
        ans += 1 << q[k];

        // int oo = 0;
        // for (int j = 1; j * j <= k; j++) {
        //     if (k % j == 0) {
        //         if (gcd(j, k / j) == 1) {
        //             oo++;
        //             if (j * j != k) oo++;
        //         }
        //     }
        // }
        // cout << " " << oo << " " << q[k] << endl;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < 20000010; i++) {
        if (q[i]) continue;
        for (int j = i; j < 20000010; j += i) q[j]++;
    }
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}