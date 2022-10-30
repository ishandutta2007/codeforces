#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int ans = k * n + 1;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && n / i < k) {
            ans = min(ans, i * k + n / i);
        }
    }
    cout << ans << endl;
    return 0;
}