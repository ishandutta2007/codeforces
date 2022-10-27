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
        int N, M;
        cin >> N >> M;
        int x, y;
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
        }
        cout << (N > M ? "YES\n" : "NO\n");
    }
    return 0;
}