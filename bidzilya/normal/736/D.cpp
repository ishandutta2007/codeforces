#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

const string YES = "YES";
const string NO = "NO";

const int MAX_N = 2e3;

int n, m;
vector<pair<int, int>> qs;

bitset<MAX_N> a[MAX_N];
bitset<MAX_N> b[MAX_N];

void DoPrepare() {
    for (int i = 0; i < n; ++i) {
        a[i].reset();
        b[i].reset();
    }
    for (int i = 0; i < m; ++i) {
        a[qs[i].first][qs[i].second] = 1;
    }
    for (int i = 0; i < n; ++i) {
        b[i][i] = 1;
    }
}

void DoEliminate() {
    for (int i = 0; i < n; ++i) {
        int row = -1;
        for (int j = i; j < n; ++j) {
            if (a[j][i]) {
                row = j;
                break;
            }
        }
        assert(row != -1);
        swap(a[row], a[i]);
        swap(b[row], b[i]);
        for (int j = i + 1; j < n; ++j) {
            if (a[j][i]) {
                a[j] ^= a[i];
                b[j] ^= b[i];
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j]) {
                a[i] ^= a[j];
                b[i] ^= b[j];
            }
        }
    }
}

void Solve() {
    DoPrepare();
    DoEliminate();
    for (int i = 0; i < m; ++i) {
        int r = qs[i].first;
        int c = qs[i].second;
        if (!b[c][r]) {
            printf("%s\n", YES.c_str());
        } else {
            printf("%s\n", NO.c_str());
        }
    }
}

bool Read() {
    if (scanf("%d%d", &n, &m) == EOF) {
        return false;
    }
    qs.resize(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &qs[i].first, &qs[i].second);
        --qs[i].first;
        --qs[i].second;
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