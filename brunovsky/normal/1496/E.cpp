#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N, M;
    cin >> N >> M;
    vector<string> garden(N + 2);
    garden[0] = garden[N + 1] = string(M + 2, '+');
    for (int i = 1; i <= N; i++) {
        cin >> ws >> garden[i];
        assert(int(garden[i].size()) == M);
        garden[i] = '+' + garden[i] + '+';
    }
    if (N % 3 == 0) {
        for (int i = 2; i <= N; i += 3) {
            garden[i] = string(M + 2, 'X');
        }
        for (int i = 3; i + 1 <= N; i += 3) {
            for (int j = 1; j <= M; j++) {
                if (j == M || garden[i][j] == 'X' || garden[i + 1][j] == 'X') {
                    garden[i][j] = garden[i + 1][j] = 'X';
                    break;
                }
            }
        }
    } else {
        for (int i = 1; i <= N; i += 3) {
            garden[i] = string(M + 2, 'X');
        }
        for (int i = 2; i + 1 <= N; i += 3) {
            for (int j = 1; j <= M; j++) {
                if (j == M || garden[i][j] == 'X' || garden[i + 1][j] == 'X') {
                    garden[i][j] = garden[i + 1][j] = 'X';
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << garden[i].substr(1, M) << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}