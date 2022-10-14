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
        int zeros = count(begin(a), end(a), 0);
        int ones = count(begin(a), end(a), 1);
        cout << (1LL * ones * (1LL << zeros)) << '\n';
    }
    return 0;
}