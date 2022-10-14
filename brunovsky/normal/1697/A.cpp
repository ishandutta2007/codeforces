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
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        int a = accumulate(begin(A), end(A), 0);
        cout << max(a - M, 0) << '\n';
    }
    return 0;
}