#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        vector<int> v;
        bool ok = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            ok |= a[i] == k;
            if (a[i] >= k) {
                v.push_back(i);
            }
        }
        int mn = inf;
        for (int i = 0; i + 1 < v.size(); ++i) {
            mn = min(mn, v[i + 1] - v[i]);
        }
        if (n == 1) {
            mn = 0;
        }
        if (ok && mn <= 2) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}