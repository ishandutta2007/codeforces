#include <bits/stdc++.h>

using namespace std;

int t, n, x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        int ans = 1e9, A, B;
        for (int a = 1; a <= x; ++a) {
            for (int b = a + 1; b <= y; ++b) {
                int d = b - a;
                int last = a + d * (n - 1);
                if ((x - a) % d == 0 && (y - a) % d == 0 && last >= y) {
                    if (ans > last) {
                        ans = last;
                        A = a;
                        B = b;
                    }
                }
            }
        }
        const int D = B - A;
        for (int i = 0; i < n; ++i) {
            cout << A + D * i << " ";
        }
        cout << "\n";
    }
    return 0;
}