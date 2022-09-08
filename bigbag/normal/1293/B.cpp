#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += 1.0 / i;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}