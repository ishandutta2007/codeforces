#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int res = 0, bestk = 1;
    for (int k = 1; k <= n; ++k) {
        int cur = n - (n + k - 1) / k - k + 1;
        if (res < cur) {
            res = cur;
            bestk = k;
        }
    }
    int k = bestk;
    for (int i = k; i <= n; i += k) {
        a[i] = 2;
    }
    a[n] = 2;
    int cnt = 0;
    while (cnt < res) {
        cout << k;
        for (int i = 1, need = k; i <= n && need; ++i) {
            if (!a[i]) {
                a[i] = 1;
                --need;
                cout << " " << i;
            }
        }
        cout << endl;
        int x;
        cin >> x;
        for (int i = 0; i < k; ++i) {
            int pos = x + i;
            if (pos > n) {
                pos -= n;
            }
            if (a[pos] != 2) {
                a[pos] = 0;
            }
        }
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            cnt += a[i] == 1;
        }
    }
    cout << 0 << endl;
    return 0;
}