/**
 *  created: 12/02/2022, 16:46:54
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, a[max_n];

long long solve() {
    if (n == 3 && a[1] % 2) {
        return -1;
    }
    if (*max_element(a + 1, a + n - 1) == 1) {
        return -1;
    }
    long long ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        ans += (a[i] + 1) / 2;
    }
    return ans;
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
        cout << solve() << "\n";
    }
    return 0;
}