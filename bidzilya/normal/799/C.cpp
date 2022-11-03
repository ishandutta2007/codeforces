#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
array<int, 2> m;
vector<pair<int, int>> cost[2];
vector<int> mb[2];

int GetOneAndOne() {
    array<int, 2> s;
    s[0] = 0;
    s[1] = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < (int) cost[i].size(); ++j) {
            if (cost[i][j].first <= m[i]) {
                s[i] = max(s[i], cost[i][j].second);
            }
        }
    }
    if (s[0] == 0 || s[1] == 0) {
        return 0;
    }
    return s[0] + s[1];
}

int GetBoth(const int idx) {
    int result = 0;
    for (int i = 0; i < (int) cost[idx].size(); ++i) {
        if (cost[idx][i].first <= m[idx]) {
            int remain = m[idx] - cost[idx][i].first;

            int bl = 0;
            int br = i - 1;
            int ba = -1;
            while (bl <= br) {
                int bm = (bl + br) >> 1;

                if (cost[idx][bm].first <= remain) {
                    ba = bm;
                    bl = bm + 1;
                } else {
                    br = bm - 1;
                }
            }

            if (ba == -1) {
                continue;
            }

            result = max(result, cost[idx][i].second + mb[idx][ba]);
        }
    }
    return result;
}

void Solve() {
    for (int i = 0; i < 2; ++i) {
        sort(cost[i].begin(), cost[i].end());
        mb[i].resize(cost[i].size());
        for (int j = 0; j < (int) cost[i].size(); ++j) {
            mb[i][j] = cost[i][j].second;
            if (j > 0) {
                mb[i][j] = max(mb[i][j], mb[i][j - 1]);
            }
        }
        
    }
    cout << max(GetOneAndOne(), max(GetBoth(0), GetBoth(1))) << endl;
}

bool Read() {
    if (!(cin >> n >> m[0] >> m[1])) {
        return false;
    }
    cost[0].clear();
    cost[1].clear();
    for (int i = 0; i < n; ++i) {
        int b, cc;
        char t;
        cin >> b >> cc >> t;
        int ti = (t == 'C' ? 0 : 1);
        cost[ti].push_back(make_pair(cc, b));
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}