#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui32;
const long long INFLL = 1e18;

using namespace std;

const int MAXN = 50;

char f[MAXN + 1][MAXN + 1], was[MAXN + 1][MAXN + 1];
int usedRow[MAXN + 1], usedCol[MAXN + 1];
int n, m, it = 1;
vector<int> cols, rows;

void dfs(int x, int y) {
    rows.push_back(x);
    cols.push_back(y);
    f[x][y] = '.';
    for (int i = 0; i < n; i++) {
        if (f[i][y] == '#') {
            dfs(i, y);
        }
    }
    for (int i = 0; i < m; i++) {
        if (f[x][i] == '#') {
            dfs(x, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
            was[i][j] = f[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == '#') {
                rows.clear();
                cols.clear();
                dfs(i, j);

                for (auto x : rows) {
                    for (auto y : cols) {
                        if (was[x][y] == '.') {
                            cout << "No\n";
                            exit(0);
                        }
                    }
                }
            }
        }
    }

    cout << "Yes\n";
    return 0;
}