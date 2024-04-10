#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if ((n - 1) / i + i < (n - 1) / k + k) k = i;
    }
    vector<bool> on(n);
    for (;;) {
        int off = 0;
        for (int i = 0; i < n; i++) {
            if (i % k == 0) continue;
            if (not on.at(i)) off++;
        }
        if (off < k) {
            cout << 0 << endl;
            return 0;
        }
        cout << off;
        for (int i = 0; i < n; i++) {
            if (i % k == 0) continue;
            if (not on.at(i)) {
                on.at(i) = true;
                cout << " " << i + 1;
            }
        }
        cout << endl;
        int x;
        cin >> x;
        if (x == -1) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            int m = i + 1;
            if ((x <= m and m < x + off) or m < x - n + off) {
                on.at(i) = false;
            }
        }
    }
}