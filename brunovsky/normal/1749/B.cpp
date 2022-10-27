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
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        int64_t asum = accumulate(begin(a), end(a), 0LL);
        int64_t bsum = accumulate(begin(b), end(b), 0LL);
        int64_t bmax = *max_element(begin(b), end(b));
        cout << asum + bsum - bmax << '\n';
    }
    return 0;
}