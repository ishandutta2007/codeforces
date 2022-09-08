#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = n - 1; i > 0; --i) {
            a[i] -= a[i - 1];
        }
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            cnt += a[i] > 0;
        }
        --k;
        if (k == 0) {
            if (cnt) {
                puts("-1");
            } else {
                puts("1");
            }
        } else {
            printf("%d\n", max(1, (cnt + k - 1) / k));
        }
    }
    return 0;
}