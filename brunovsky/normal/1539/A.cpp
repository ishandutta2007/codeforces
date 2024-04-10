#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        long N, x, t;
        cin >> N >> x >> t;
        long r = t / x;
        if (x * N > t) {
            long ans = (N - 1) * r - r * (r - 1) / 2;
            cout << ans << '\n';
        } else {
            long ans = N * (N - 1) / 2;
            cout << ans << '\n';
        }
    }

    return 0;
}