#include <bits/stdc++.h>

using namespace std;

const int max_n = 33, inf = 1000111222;

int n;

bool get_bit(long long x, int pos) {
    return (x >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long x = 0;
            if (j % 2 == 0) {
                x = 1LL << (i + j);
            }
            cout << x << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        long long sum;
        cin >> sum;
        int x = 0, y = 0;
        while (x + y < 2 * n - 2) {
            cout << x + 1 << " " << y + 1 << endl;
            bool f1 = get_bit(sum, x + y + 1);
            bool f2 = ((y % 2) == 0);
            if (f1 == f2) {
                ++x;
            } else {
                ++y;
            }
            assert(x < n && y < n);
        }
        cout << n << " " << n << endl;
    }
    return 0;
}