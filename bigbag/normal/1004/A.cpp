#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, d, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 2;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] - a[i] == 2 * d) {
            ++ans;
        } else if (a[i + 1] - a[i] > 2 * d) {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}