#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    // Looks like some fracturing search stuff
    // Just enumerate going left to right and top to bottom
    int N;
    cin >> N;
    vector<vector<int>> items(N);
    vector<int> len(N);
    int best_unrestricted = 0;
    for (int i = 0; i < N; i++) {
        cin >> len[i];
        items[i].resize(len[i]);
        for (int j = len[i] - 1; j >= 0; j--) {
            cin >> items[i][j];
        }
        best_unrestricted += items[i][0];
    }
    using build = array<int, 10>;
    set<build> banned;
    int B;
    cin >> B;
    for (int i = 0; i < B; i++) {
        build ban = {};
        for (int j = 0; j < N; j++) {
            cin >> ban[j];
            ban[j] = len[j] - ban[j];
        }
        banned.insert(ban);
    }

    set<build> visited;
    priority_queue<pair<int, build>> pq;
    pq.push(make_pair(best_unrestricted, build{}));
    visited.insert(build{});

    while (true) {
        auto [score, build] = pq.top();
        pq.pop();
        visited.erase(build);
        if (!banned.count(build)) {
            for (int i = 0; i < N; i++) {
                cout << len[i] - build[i] << " \n"[i + 1 == N];
            }
            debug("winner score: ", score);
            break;
        }
        for (int i = 0; i < N; i++) {
            if (build[i] + 1 < len[i]) {
                int delta = items[i][build[i]] - items[i][build[i] + 1];
                build[i]++;
                if (!visited.count(build)) {
                    pq.push(make_pair(score - delta, build));
                    visited.insert(build);
                }
                build[i]--;
            }
        }
    }
    return 0;
}