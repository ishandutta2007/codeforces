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
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        constexpr int MAX = 100;
        vector<int> found(2 * MAX + 1);
        for (int i = 0; i < N; i++) {
            found[A[i] + MAX]++;
        }

        int count = found[MAX] > 0;
        for (int v = 1; v <= MAX; v++) {
            count += min(found[MAX + v] + found[MAX - v], 2);
        }
        cout << count << '\n';
    }
    return 0;
}