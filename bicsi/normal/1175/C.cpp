#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k; ++k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int best = 2e9, choose = -1;
        for (int i = k - 1; i < n; ++i) {
            int diff = a[i] - a[i - k + 1];
            diff = (diff + 1) / 2;
            if (best > diff) {
                best = diff;
                choose = (a[i] + a[i - k + 1]) / 2;
            }
        }
        cout << choose << '\n';
        /*
        int l = 0, r = 1e9 + 1;
        auto eval = [&](int m) {
            vector<int> dist(n);
            for (int i = 0; i < n; ++i)
                dist[i] = abs(a[i] - m);
            nth_element(dist.begin(), dist.begin() + k, dist.end());
            return dist[k];
        };
        while (l <= r) {
            int m = (l + r) / 2;
            int a = eval(m), b = eval(m + 1);
            if (a < b) {
                if (a < best) {
                    best = a;
                    choose = m;
                }
                r = m - 1;
            } else {
                if (b < best) {
                    best = b;
                    choose = m + 1;
                }
                l = m + 1;
            }
        }
        cerr << "[" << best << "]\n";
        cout << choose << '\n';
        */
    }

    return 0;
}