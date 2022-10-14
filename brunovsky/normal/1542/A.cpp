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
        int N;
        cin >> N;
        int odds = 0;
        for (int i = 0; i < 2 * N; i++) {
            int n;
            cin >> n;
            odds += n & 1;
        }
        if (odds == N) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}