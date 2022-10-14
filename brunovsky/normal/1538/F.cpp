#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        long l, r;
        cin >> l >> r;
        long ans = 0;
        while (l != r) {
            ans += r - l;
            l /= 10;
            r /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}