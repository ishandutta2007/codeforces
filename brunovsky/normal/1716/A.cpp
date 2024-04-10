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
        if (N <= 3) {
            cout << (N == 1 ? 2 : 1) << '\n';
        } else if (N % 3 == 0) {
            cout << N / 3 << '\n';
        } else {
            cout << N / 3 + 1 << '\n';
        }
    }
    return 0;
}