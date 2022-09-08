#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t;
long long a, b, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b >> k;
        long long ans = (k + 1) / 2 * a - (k / 2) * b;
        cout << ans << endl;
    }
    return 0;
}