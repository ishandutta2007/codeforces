/**
 *  created: 12/06/2022, 17:37:07
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, q;
long long a[max_n];

long long get_sum(int l, int r) {
    return a[r] - a[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << get_sum(n - x + 1, n - x + y) << "\n";
    }
    return 0;
}