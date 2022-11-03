#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long INF = 1e18;

int n;
vector<long long> a[3];

vector<long long> b[3];
long long c[3];

void Solve() {
    for (int i = 0; i < 3; ++i) {
        b[i].assign(n + 1, -INF);
        c[i] = -INF;
    }
    b[0][0] = 0;
    c[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (b[0][i] != -INF) {
            b[0][i + 1] = max(b[0][i + 1], b[0][i] + a[0][i]);
            b[1][i + 1] = max(b[1][i + 1], b[0][i] + a[0][i] + a[1][i]);
            b[2][i + 1] = max(b[2][i + 1], b[0][i] + a[0][i] + a[1][i] + a[2][i]);
        }
        if (b[1][i] != -INF) {
            b[0][i + 1] = max(b[0][i + 1], b[1][i] + a[0][i] + a[1][i]);
            b[1][i + 1] = max(b[1][i + 1], b[1][i] + a[1][i]);
            b[2][i + 1] = max(b[2][i + 1], b[1][i] + a[1][i] + a[2][i]);
        }
        if (b[2][i] != -INF) {
            b[0][i + 1] = max(b[0][i + 1], b[2][i] + a[0][i] + a[1][i] + a[2][i]);
            b[1][i + 1] = max(b[1][i + 1], b[2][i] + a[1][i] + a[2][i]);
            b[2][i + 1] = max(b[2][i + 1], b[2][i] + a[2][i]);
        }
        if (c[0] != -INF) {
            c[0] += a[0][i] + a[1][i] + a[2][i];
            b[2][i + 1] = max(b[2][i + 1], c[0]);
        }
        if (c[2] != -INF) {
            c[2] += a[0][i] + a[1][i] + a[2][i];
            b[0][i + 1] = max(b[0][i + 1], c[2]);
        }
        c[0] = max(c[0], b[0][i + 1]);
        c[2] = max(c[2], b[2][i + 1]);
    }
    cout << b[2][n] << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    for (int i = 0; i < 3; ++i) {
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
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