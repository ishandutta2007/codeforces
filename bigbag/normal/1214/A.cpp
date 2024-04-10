#include <bits/stdc++.h>

using namespace std;

int n, d, e;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> d >> e;
    e *= 5;
    int ans = n;
    for (int i = 0; i * e <= n; ++i) {
        ans = min(ans, (n - i * e) % d);
    }
    cout << ans << endl;
    return 0;
}