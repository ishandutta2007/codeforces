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
        int N, K;
        cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        if (K >= N) {
            cout << 0 << '\n';
            continue;
        }
        // Iterate over the MEX? We can under MEX and exact DIFF
        map<int, int> cnt;
        for (int x : a) {
            cnt[x]++;
        }
        map<int, int> orig = cnt;
        vector<set<int>> ff(N + 1);
        for (auto [x, c] : cnt) {
            ff[c].insert(x);
        }
        set<int> active;
        for (int f = 1; f <= N; f++) {
            if (ff[f].size()) {
                active.insert(f);
            }
        }
        auto rem = [&](int f, int x) {
            ff[f].erase(x);
            if (f) {
                cnt.erase(x);
            }
            if (f && ff[f].empty()) {
                active.erase(f);
            }
        };
        auto ins = [&](int f, int x) {
            if (f) {
                cnt.emplace(x, f);
            }
            if (f && ff[f].empty()) {
                active.insert(f);
            }
            ff[f].insert(x);
        };
        auto optimize = [&]() {
            int ans = cnt.size(), M = K;
            for (int f : active) {
                int r = min<int>(ff[f].size(), M / f);
                M -= f * r, ans -= r;
            }
            return ans;
        };
        int ans = optimize();
        for (int m = 1; m <= N; m++) {
            // Assume we enforce MEX(a)>=m, what is the answer?
            int gap = orig[m - 1] - cnt[m - 1];
            rem(cnt[m - 1], m - 1);
            while (gap && active.size()) {
                int f = *active.begin();
                int x = *ff[f].begin();
                int t = max(0, f - gap);
                gap -= f - t;
                rem(f, x), ins(t, x);
            }
            if (orig[m - 1] == 0) {
                if (K > 0 && active.size()) {
                    int f = *active.begin();
                    int x = *ff[f].begin();
                    int t = f - 1;
                    K--;
                    rem(f, x), ins(t, x);
                } else if (K > 0) {
                    K--;
                } else {
                    break;
                }
            }
            cnt.erase(m - 1);
            ans = min(ans, optimize());
        }
        cout << ans << '\n';
    }
    return 0;
}