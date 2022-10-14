#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<string> desktop(N);
    int C = 0;
    for (int i = 0; i < N; i++) {
        cin >> desktop[i];
        C += count(begin(desktop[i]), end(desktop[i]), '*');
    }
    int good = 0;
    for (int j = 0, c = C; j < M && c > 0; j++) {
        for (int i = 0; i < N && c > 0; i++, c--) {
            good += desktop[i][j] == '*';
        }
    }
    while (Q--) {
        int x, y;
        cin >> x >> y, x--, y--;
        int rank = y * N + x;
        if (desktop[x][y] == '*') {
            C--;
            int u = C / N, v = C % N;
            good -= rank < C;
            good -= desktop[v][u] == '*';
            desktop[x][y] = '.';
        } else {
            int u = C / N, v = C % N;
            C++;
            good += rank < C;
            good += desktop[v][u] == '*';
            desktop[x][y] = '*';
        }
        cout << (C - good) << '\n';
    }
    return 0;
}