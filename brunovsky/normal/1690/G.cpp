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
        int N, Q;
        cin >> N >> Q;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        // Strict prefix minimums
        int x = INT_MAX;
        set<int> indices;
        for (int i = 0; i < N; i++) {
            if (a[i] < x) {
                indices.insert(i), x = a[i];
            }
        }

        while (Q--) {
            int i, d;
            cin >> i >> d, i--;
            a[i] -= d;
            auto pos = indices.upper_bound(i);
            while (pos != end(indices) && a[i] <= a[*pos]) {
                pos = indices.erase(pos);
            }
            if (--pos, a[*pos] > a[i]) {
                indices.insert(i);
            }
            cout << indices.size() << " \n"[Q == 0];
        }
    }
    return 0;
}