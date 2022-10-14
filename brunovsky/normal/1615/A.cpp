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
        int sum = accumulate(begin(a), end(a), 0);
        if (sum % N == 0) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}