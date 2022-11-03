#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

int n, m;
vector<vector<int>> a;

struct TResult {
    vector<int> Rows, Cols;

    int GetSum() const {
        return accumulate(Rows.begin(), Rows.end(), 0) + accumulate(Cols.begin(), Cols.end(), 0);
    }
};

bool operator < (const TResult& lhs, const TResult& rhs) {
    return lhs.GetSum() < rhs.GetSum();
}

void Solve() {
    TResult bestResult;
    bool found = false;
    for (int cntCol = 0; cntCol <= a[0][0]; ++cntCol) {
        TResult result;
        result.Rows.resize(n);
        result.Cols.resize(m);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            result.Rows[i] = a[i][0] - cntCol;
            if (result.Rows[i] < 0) {
                ok = false;
            }
        }
        result.Cols[0] = cntCol;
        for (int i = 1; i < m; ++i) {
            result.Cols[i] = a[0][i] - result.Rows[0];
            if (result.Cols[i] < 0) {
                ok = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (result.Rows[i] + result.Cols[j] != a[i][j]) {
                    ok = false;
                }
            }
        }
        if (ok && (!found || result < bestResult)) {
            found = true;
            bestResult = result;
        }
    }
    if (!found) {
        cout << -1 << endl;
    } else {
        cout << bestResult.GetSum() << endl;
        const auto show = [] (const vector<int>& values, const string prefix) {
            for (int i = 0; i < (int) values.size(); ++i) {
                for (int j = 0; j < values[i]; ++j) {
                    cout << prefix << " " << i + 1 << endl;
                }
            }
        };
        show(bestResult.Rows, "row");
        show(bestResult.Cols, "col");
    }
}

bool Read() {
    if (!(cin >> n >> m)) {
        return false;
    }
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
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