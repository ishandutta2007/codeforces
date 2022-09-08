/**
 *  created: 14/06/2022, 17:49:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];

bool ok(vector<int> cnt) {
    for (int x = 0; x < 10; ++x) {
        if (cnt[x]) {
            --cnt[x];
            for (int y = 0; y < 10; ++y) {
                if (cnt[y]) {
                    --cnt[y];
                    for (int z = 0; z < 10; ++z) {
                        if (cnt[z] && (x + y + z) % 10 == 3) {
                            return true;
                        }
                    }
                    ++cnt[y];
                }
            }
            ++cnt[x];
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> cnt(10);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++cnt[a[i] % 10];
        }
        if (ok(cnt)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}