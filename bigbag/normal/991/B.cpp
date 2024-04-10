#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, sum, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    for (int i = 0; i <= n; ++i) {
        if (sum >= 4 * n + (n + 1) / 2) {
            cout << i << endl;
            return 0;
        }
        sum -= a[i];
        sum += 5;
    }
    return 0;
}