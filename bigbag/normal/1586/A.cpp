/**
 *  created: 17/10/2021, 14:06:24
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, a[max_n];

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int sum = accumulate(a, a + n, 0);
        if (!is_prime(sum)) {
            cout << n << "\n";
            for (int i = 0; i < n; ++i) {
                cout << i + 1 << " ";
            }
            cout << "\n";
        } else {
            cout << n - 1 << "\n";
            bool first = true;
            for (int i = 0; i < n; ++i) {
                if (a[i] % 2 && first) {
                    first = 0;
                    continue;
                }
                cout << i + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}