#include <bits/stdc++.h>

using namespace std;

const int max_n = 7077, inf = 1000111222;

int n, ok[max_n];
long long a[max_n], b[max_n], ans;
map<long long, int> cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]] >= 2) {
            for (int j = 0; j < n; ++j) {
                if ((a[i] & a[j]) == a[j]) {
                    ok[j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ok[i]) {
            ans += b[i];
        }
    }
    cout << ans << "\n";
    return 0;
}