#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, p;

bool get_bit(int x, int pos) {
    return (x >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> p;
    for (int k = 1; k < 11111; ++k) {
        int x = n - k * p;
        if (x >= 1) {
            int mn = 0, mx = 0;
            for (int i = 0; i < 31; ++i) {
                if (get_bit(x, i)) {
                    ++mn;
                    mx += 1 << i;
                }
            }
            if (mn <= k && k <= mx) {
                cout << k << "\n";
                return 0;
            }
        }
    }
    cout << "-1\n";
    return 0;
}