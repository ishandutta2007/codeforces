#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

bool within(int a, int b, int c) { return a <= b && b <= c; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        vector<int> vals = a;
        sort(begin(vals), end(vals));

        // A >= B + k <=> A - B >= k and A + B = n <=> 2A >= n + k <=> A >= (n + k) / 2
        int A = (N + K + 1) / 2;

        int best_gap = INT_MAX, X = 0, Y = 0;
        for (int i = 0; i + A <= N; i++) {
            int x = vals[i], y = vals[i + A - 1];
            if (y - x < best_gap) {
                best_gap = y - x;
                tie(X, Y) = make_pair(x, y);
            }
        }

        cout << X << ' ' << Y << '\n';
        vector<pair<int, int>> ranges;
        for (int l = 0, r = 1, R = 0; r <= N && R < K; l = r++) {
            int inside = within(X, a[l], Y);
            int outside = !within(X, a[l], Y);
            while (r < N && inside <= outside) {
                inside += within(X, a[r], Y);
                outside += !within(X, a[r], Y);
                r++;
            }
            ranges.push_back({l + 1, r}), R++;
        }
        ranges.back().second = N;
        for (auto [l, r] : ranges) {
            cout << l << ' ' << r << '\n';
        }
    }
    return 0;
}