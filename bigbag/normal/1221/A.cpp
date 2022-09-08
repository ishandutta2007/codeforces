#include <bits/stdc++.h>

using namespace std;

const int max_n = 3333, inf = 1000111222;

int t, n, a[max_n], cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] < max_n) {
                ++cnt[a[i]];
            }
        }
        for (int i = 2; i <= 2048; ++i) {
            cnt[i] += cnt[i / 2] / 2;
        }
        if (cnt[2048]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}