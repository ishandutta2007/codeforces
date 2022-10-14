#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

vector<int> permutation;

int QUERY(int t, int x, int i, int j) {
#ifdef LOCAL
    if (t == 1) {
        return max(min(x, permutation[i - 1]), min(x + 1, permutation[j - 1]));
    } else {
        return min(max(x, permutation[i - 1]), max(x + 1, permutation[j - 1]));
    }
#else
    cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl;
    int v;
    cin >> v;
    return v;
#endif
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

#ifdef LOCAL
        permutation.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> permutation[i];
        }
#endif

        vector<int> candidates;
        for (int i = 1; i + 1 <= N; i += 2) {
            int v = QUERY(2, 1, i, i + 1);
            if (v == 1 || v == 2) {
                candidates.push_back(i);
                candidates.push_back(i + 1);
            }
        }
        if (N & 1) {
            int v = QUERY(2, 1, 1, N);
            if (v == 1 || v == 2) {
                candidates.push_back(N);
            }
        }
        sort(begin(candidates), end(candidates));
        int C = candidates.size();
        assert(1 <= C && C <= 5);

        debug(candidates);

        if (C > 1) {
            for (int c = 0; c < C; c++) {
                int i = candidates[c];
                int j = candidates[(c + 1) % C];
                if (QUERY(2, 1, i, j) == 1) {
                    candidates[0] = i;
                    break;
                }
            }
        }
        int one = candidates[0];

        vector<int> ans(N + 1);
        ans[one] = 1;

        for (int i = 1; i <= N; i++) {
            if (i != one) {
                ans[i] = QUERY(1, N - 1, one, i);
            }
        }

        cout << "!";
        for (int i = 1; i <= N; i++) {
            cout << " " << ans[i];
        }
        cout << endl;
    }
    return 0;
}