#include <bits/stdc++.h>

using namespace std;

const int max_n = 22, inf = 1000111222;

int n, a[max_n];

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (get_bit(mask, i)) {
                sum += a[i];
            } else {
                sum -= a[i];
            }
        }
        sum %= 360;
        if (sum == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}