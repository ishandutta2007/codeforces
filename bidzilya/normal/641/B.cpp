#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

const int UNDEF_VALUE = 0;

struct TValue {
    int Row;
    int Col;
    int Value;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<TValue>> a(n, vector<TValue>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j].Row = i;
            a[i][j].Col = j;
            a[i][j].Value = UNDEF_VALUE;
        }
    }

    for (; q; --q) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int r;
            cin >> r;
            --r;
            TValue first = a[r][0];
            for (int i = 0; i + 1 < m; ++i) {
                a[r][i] = a[r][i + 1];
            }
            a[r][m - 1] = first;
        } else if (tp == 2) {
            int c;
            cin >> c;
            --c;
            TValue first = a[0][c];
            for (int i = 0; i + 1 < n; ++i) {
                a[i][c] = a[i + 1][c];
            }
            a[n - 1][c] = first;
        } else {
            int r, c, x;
            cin >> r >> c >> x;
            --r;
            --c;
            a[r][c].Value = x;
        }
    }

    vector<vector<int>> initialMatrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            initialMatrix[a[i][j].Row][a[i][j].Col] = a[i][j].Value;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << initialMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}