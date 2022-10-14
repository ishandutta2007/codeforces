#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N;
    cin >> N;
    vector<array<int, 2>> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i][0];
    }
    for (int i = 0; i < N; i++) {
        cin >> p[i][1];
    }
    sort(begin(p), end(p));
    int x = 1, y = 1;
    long cost = 0;
    for (int i = 0; i < N; i++) {
        auto [nx, ny] = p[i];
        if (x - y == nx - ny) {
            if (x % 2 == y % 2) {
                cost += nx - x;
            }
        } else {
            int dx = (nx - ny) - (x - y);
            int first_is_active = x % 2 == y % 2;
            cost += (dx + 1 - first_is_active) / 2;
        }
        x = nx, y = ny;
    }
    return cost;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}