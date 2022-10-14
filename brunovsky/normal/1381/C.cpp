#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, x, y;
        cin >> N >> x >> y;

        vector<int> b(N);
        vector<int> f(N + 1);
        vector<vector<int>> by_color(N + 1);
        for (int i = 0; i < N; i++) {
            cin >> b[i], b[i]--;
            f[b[i]]++;
            by_color[b[i]].push_back(i);
        }

        debug(N, x, y, b);

        int unused_color = find(begin(f), end(f), 0) - begin(f);
        vector<int> ans(N, unused_color);

        // colors for left (fixed), middle (unused), right (rotated)
        vector<int> rf = f;
        auto cmp = [&](int i, int j) {
            return make_pair(rf[i], i) < make_pair(rf[j], j);
        };
        set<int, decltype(cmp)> colorset(cmp);
        for (int c = 0; c <= N; c++) {
            if (f[c] > 0) {
                colorset.insert(c);
            }
        }

        vector<int> fixed;
        while (int(fixed.size()) < x) {
            int c = *colorset.rbegin();
            colorset.erase(c);
            fixed.push_back(c);
            if (--rf[c] > 0) {
                colorset.insert(c);
            }
        }

        // add fixed colors
        for (int c : fixed) {
            int i = by_color[c].back();
            by_color[c].pop_back();
            ans[i] = b[i];
        }

        vector<int> unused;
        while (int(unused.size()) < N - y) {
            int c = *colorset.rbegin();
            colorset.erase(c);
            unused.push_back(c);
            if (--rf[c] > 0) {
                colorset.insert(c);
            }
        }

        vector<int> rotated;
        while (int(rotated.size()) < y - x) {
            int c = *colorset.rbegin();
            colorset.erase(c);
            rotated.push_back(c);
            if (--rf[c] > 0) {
                colorset.insert(c);
            }
        }

        debug(fixed, unused, rotated);

        vector<int> rotf(N + 1);
        for (int c : rotated) {
            rotf[c]++;
        }
        int most = max_element(begin(rotf), end(rotf)) - begin(rotf);

        vector<int> rot_colors = rotated;
        int R = rot_colors.size();
        for (int j = 0; j < N - y && R < 2 * rotf[most]; j++) {
            if (unused[j] != most) {
                rot_colors.push_back(unused[j]), R++;
            }
        }

        if (R < 2 * rotf[most]) {
            cout << "NO\n";
            continue;
        }

        vector<pair<int, bool>> rotation;
        for (int j = 0, r = rotated.size(); j < R; j++) {
            int i = by_color[rot_colors[j]].back();
            by_color[rot_colors[j]].pop_back();
            rotation.push_back({i, j < r});
        }

        sort(begin(rotation), end(rotation),
             [&](auto u, auto v) { return b[u.first] < b[v.first]; });

        for (int j = 0; j < R; j++) {
            if (rotation[j].second) {
                int i = rotation[(j + (R + 1) / 2) % R].first;
                ans[i] = b[rotation[j].first];
            }
        }

        // verify...
        {
            int ans_x = 0, ans_y = 0;
            vector<int> ans_freq(N + 1);
            for (int i = 0; i < N; i++) {
                ans_x += b[i] == ans[i];
                ans_freq[ans[i]]++;
            }

            for (int c = 0; c <= N; c++) {
                ans_y += min(ans_freq[c], f[c]);
            }

            debug(x, y, ans_x, ans_y);
        }

        cout << "YES\n";
        for (int i = 0; i < N; i++) {
            cout << 1 + ans[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}