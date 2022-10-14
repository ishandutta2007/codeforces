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
            cin >> a[i], a[i]--;
        }
        vector<int> occ(N);
        for (int i = 0; i < N; i++) {
            occ[a[i]]++;
        }
        int M = *max_element(begin(occ), end(occ));
        if (M > (N + 1) / 2) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> cnt(N);
        int R = 0;
        for (int l = 0, r = 1; l < N; l = r++) {
            while (r < N && a[r - 1] != a[r])
                r++;
            cnt[a[l]]++;
            cnt[a[r - 1]]++;
            R++;
        }
        // (1 1) is ok 0 jumps
        // (1 1) (1 2) is ok 1 jump
        // (1 1) (1 1) (2 3) is ok 2 jumps
        // (1 1) (1 1) (1 2) is not ok 3 jumps
        // (1 1) (1 1) (1 1) (1 2) is not ok 5 jumps
        M = *max_element(begin(cnt), end(cnt));
        if (M > R + 1) {
            R += M - (R + 1);
        }
        cout << R - 1 << '\n';
    }
    return 0;
}

// You stupid fuck, you don't need to reconstruct it