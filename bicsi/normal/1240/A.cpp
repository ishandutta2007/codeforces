#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

long long Solve(const vector<int>& price, int n, int a, int x, int b, int y) {
    int at = 0;
    long long ans = 0;
    long long lc = a;
    while (lc % b) lc += a;
    // cerr << lc << endl;
    for (long long i = lc; i <= n; i += lc)
        ans += 1LL * (x + y) * price[at++];
    // cerr << ans / 100 << endl;
    for (long long i = a; i <= n; i += a) if (i % b)
        ans += 1LL * x * price[at++];
    // cerr << ans / 100 << endl;
    for (long long i = b; i <= n; i += b) if (i % a)
        ans += 1LL * y * price[at++];
    // cerr << ans / 100 << endl;
    return ans / 100;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> price(n);
        for (int i = 0; i < n; ++i) {
            cin >> price[i];
        }
        sort(price.rbegin(), price.rend());
        int x, a, y, b; cin >> x >> a >> y >> b;
        long long k; cin >> k;
        if (x < y) { swap(x, y); swap(a, b); }
            
        /*
        for (int i = 1; i <= n; ++i) {
            cerr << Solve(price, i, a, x, b, y) << endl;
        }*/
        // cerr << Solve(price, 6, a, x, b, y) << endl;
        int ans = 0, adv = 1;
        for (int step = 1; step; adv ? step *= 2 : step /= 2) {
            if (ans + step <= n && Solve(price, ans + step, a, x, b, y) < k) {
                ans += step;
            } else adv = 0;
        }
        if (ans == n) ans = -1;
        else ++ans;

        cout << ans << '\n';
    }

    return 0;
}