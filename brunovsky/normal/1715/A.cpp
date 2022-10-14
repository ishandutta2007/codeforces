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
        if (N > M) {
            swap(N, M);
        }
        if (M == 1) {
            cout << 0 << '\n';
        } else {
            cout << N + M - 2 + 1 + N - 1 << '\n';
        }
    }
    return 0;
}