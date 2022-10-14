#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, B, x, y;
        cin >> N >> B >> x >> y;
        int a = 0;
        int64_t sum = 0;
        while (N--) {
            if (a + x > B) {
                a -= y;
            } else {
                a += x;
            }
            sum += a;
        }
        cout << sum << '\n';
    }
    return 0;
}