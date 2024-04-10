#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    vector<vector<int8_t>> grid(N + 2, vector<int8_t>(N + 2, 0));
    deque<array<int, 2>> blacks, whites;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if ((i + j) & 1) {
                whites.push_back({i, j});
            } else {
                blacks.push_back({i, j});
            }
        }
    }

    auto print = [&]() {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cout << char(grid[i][j] ? '0' + grid[i][j] : '.');
            }
            cout << endl;
        }
    };

    for (int turn = 0, ban; turn < N * N; turn++) {
        cin >> ban;
        int b, i, j;
        if (ban == 1) {
            if (blacks.empty()) {
                b = 3, i = whites[0][0], j = whites[0][1], whites.pop_front();
            } else {
                b = 2, i = blacks[0][0], j = blacks[0][1], blacks.pop_front();
            }
        } else if (ban == 2) {
            if (whites.empty()) {
                b = 3, i = blacks[0][0], j = blacks[0][1], blacks.pop_front();
            } else {
                b = 1, i = whites[0][0], j = whites[0][1], whites.pop_front();
            }
        } else /* ban == 3 */ {
            if (blacks.empty()) {
                b = 1, i = whites[0][0], j = whites[0][1], whites.pop_front();
            } else {
                b = 2, i = blacks[0][0], j = blacks[0][1], blacks.pop_front();
            }
        }
        grid[i][j] = b;
        cout << b << ' ' << i << ' ' << j << endl;
        // print();
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    setbuf(stdin, nullptr), setbuf(stdout, nullptr);
    solve();
    return 0;
}