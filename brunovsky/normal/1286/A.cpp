#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> p(N);
    vector<bool> in_p(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        in_p[p[i]] = true;
    }
    array<int, 2> cnt = {};
    for (int v = 1; v <= N; v++) {
        if (!in_p[v]) {
            cnt[v & 1]++;
        }
    }
    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    } else if (count(begin(in_p) + 1, end(in_p), true) == 0) {
        cout << 1 << '\n';
        return 0;
    }

    int ans = 0;
    array<vector<int>, 2> gaps, sides;

    int L = 0;
    while (L < N && p[L] == 0) {
        L++;
    }
    if (L > 0) {
        sides[p[L] & 1].push_back(L);
    }
    int R = N - 1;
    while (R >= 0 && p[R] == 0) {
        R--;
    }
    if (R < N - 1) {
        sides[p[R] & 1].push_back(N - 1 - R);
    }
    int l = L;
    while (l < R) {
        int r = l + 1;
        while (r < R && p[r] != 0)
            r++;
        if (r == R)
            break;
        int m = r - 1;
        while (r < R && p[r] == 0)
            r++;
        int gap = r - m - 1;
        assert(l <= m && m < r && p[m] != 0 && p[r] != 0);
        if ((p[m] & 1) != (p[r] & 1)) {
            ans += 1;
        } else {
            gaps[p[m] & 1].push_back(gap);
        }
        l = r;
    }
    for (int i = 0; i + 1 < N; i++) {
        if (p[i] && p[i + 1] && (p[i] & 1) != (p[i + 1] & 1)) {
            ans += 1;
        }
    }
    // fill in greedily
    for (int i : {0, 1}) {
        sort(rbegin(gaps[i]), rend(gaps[i]));
        sort(rbegin(sides[i]), rend(sides[i]));
        while (!gaps[i].empty() && cnt[i] >= gaps[i].back()) {
            cnt[i] -= gaps[i].back();
            gaps[i].pop_back();
        }
        while (!sides[i].empty() && cnt[i] >= sides[i].back()) {
            cnt[i] -= sides[i].back();
            sides[i].pop_back();
        }
        ans += 2 * gaps[i].size();
        ans += sides[i].size();
    }
    cout << ans << '\n';
    return 0;
}