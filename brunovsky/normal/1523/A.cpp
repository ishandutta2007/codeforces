#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N, M;
    string s;
    cin >> N >> M >> s;
    vector<array<int, 2>> runs;
    {
        int i = 0;
        while (i < N && s[i] == '1')
            i++;
        while (i < N) {
            int j = i + 1;
            while (j < N && s[j] == '0')
                j++;

            runs.push_back({i, j});
            i = j;
            while (i < N && s[i] == '1')
                i++;
        }
    }

    vector<array<int, 2>> ans_runs;

    for (auto& [x, y] : runs) {
        int cells = y - x;
        if (x > 0 && y < N && cells > 2 * M) {
            x += M;
            y -= M;
            ans_runs.push_back({x, y});
        } else if (x == 0 || y == N) {
            x += x == 0 ? 0 : M;
            y -= y == N ? 0 : M;
            if (x < y) {
                ans_runs.push_back({x, y});
            }
        } else if (cells & 1) {
            x += cells / 2;
            y -= cells / 2;
            assert(x + 1 == y);
            ans_runs.push_back({x, y});
        }
    }

    string ans(N, '1');

    for (auto [x, y] : ans_runs) {
        for (int i = x; i < y; i++) {
            ans[i] = '0';
        }
    }

    return ans;
}

// *****

int main() {
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}