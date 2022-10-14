#include <bits/stdc++.h>

using namespace std;

// *****

string to_string(int x, int y, int z, int w) {
    return to_string(x) + ' ' + to_string(y) + ' ' + to_string(z) + ' ' + to_string(w);
}

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int supv = *max_element(begin(A), end(A)) + 1;

    vector<vector<int>> pos(supv);
    array<int, 2> twice = {};

    for (int i = 1; i <= N; i++) {
        int a = A[i];
        pos[a].push_back(i);

        if (pos[a].size() == 4u) {
            int x = pos[a][0], y = pos[a][1], z = pos[a][2], w = pos[a][3];
            cout << "YES\n" << to_string(x, y, z, w) << endl;
            return;
        }
        if (pos[a].size() == 2u) {
            if (twice[0] != 0) {
                int x = pos[a][0], z = pos[a][1];
                int y = twice[0], w = twice[1];
                cout << "YES\n" << to_string(x, y, z, w) << endl;
                return;
            } else {
                twice = {pos[a][0], pos[a][1]};
            }
        }
    }

    vector<vector<pair<int, int>>> vis(supv);

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int x = i, y = j;
            if (A[x] < A[y]) {
                swap(x, y);
            }
            int diff = abs(A[x] - A[y]);
            for (auto [z, w] : vis[diff]) {
                if (x != z && x != w && y != z && y != w) {
                    cout << "YES\n" << to_string(x, w, z, y) << endl;
                    return;
                }
            }
            vis[diff].push_back({x, y});
        }
    }

    cout << "NO" << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}