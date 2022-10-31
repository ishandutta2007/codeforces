#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int c, d, n, m, k;
    cin >> c >> d >> n >> m >> k;

    int tgt = max(0, m * n - k);
    int ans = 1e9;
    for (int q = 0; q <= tgt; ++q)
        ans = min(ans, q*c + max(0, (tgt - q * n)) * d);

    cout << ans << "\n";

    return 0;
}