#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    n /= 2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = inf;
    for (int x = 0; x < 2; ++x) {
        int cur = 1 + x, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += abs(a[i] - cur);
            cur += 2;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}