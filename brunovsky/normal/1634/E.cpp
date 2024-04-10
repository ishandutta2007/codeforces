#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int M;
    cin >> M;
    vector<vector<int>> nums(M);
    vector<string> ans(M);
    map<int, set<pair<int, int>>> freq;
    map<pair<int, int>, vector<int>> where;
    vector<set<int>> active(M);
    for (int i = 0; i < M; i++) {
        int N;
        cin >> N;
        ans[i].resize(N, '?');
        nums[i].resize(N);

        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            nums[i][j] = x;
            freq[x].insert({i, j});
            where[{i, x}].push_back(j);
            active[i].insert(j);
        }
    }

    for (const auto& [x, occ] : freq) {
        if (occ.size() % 2 != 0) {
            cout << "NO\n";
            return 0;
        }
    }

    auto remove = [&](int i, int x, char side) {
        int j = where.at({i, x}).back();
        where.at({i, x}).pop_back();
        if (where.at({i, x}).empty()) {
            where.erase({i, x});
        }
        freq.at(x).erase({i, j});
        if (freq.at(x).empty()) {
            freq.erase(x);
        }
        active.at(i).erase(j);
        ans[i][j] = side;
    };

    while (!freq.empty()) {
        int x = freq.begin()->first;
        int a = freq.at(x).begin()->first;
        remove(a, x, 'L');
        while (!where.count({a, x})) {
            int b = freq.at(x).begin()->first;
            remove(b, x, 'R');
            int y = nums[b][*active.at(b).begin()];
            remove(b, y, 'L');
            x = y;
        }
        remove(a, x, 'R');
    }

    cout << "YES\n";
    for (int i = 0; i < M; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}