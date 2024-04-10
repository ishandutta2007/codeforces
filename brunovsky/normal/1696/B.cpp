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
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        if (count(begin(a), end(a), 0) == N) {
            cout << "0\n";
            continue;
        }
        int L = 0, R = N - 1;
        while (L < N && a[L] == 0) {
            L++;
        }
        while (R >= 0 && a[R] == 0) {
            R--;
        }
        assert(L <= R);
        if (count(begin(a) + L, begin(a) + R + 1, 0) == 0) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    return 0;
}