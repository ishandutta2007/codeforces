#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

const bool kFileInput = false;
const bool kDebugOutput = false;

int main()
{
    if (kFileInput) {
        freopen("input.txt", "r", stdin);
    }

    int n, m;
    cin >> n >> m;

    if (n > m) {
        cout << "YES" << endl;
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<bool> > b(n, vector<bool>(m, false));
    b[0][a[0] % m] = true;
    for (int i = 1; i < n; ++i) {
        b[i].assign(b[i - 1].begin(), b[i - 1].end());
        int x = a[i] % m;
        b[i][x] = true;
        for (int j = 0; j < m; ++j) {
            if (!b[i - 1][j]) {
                continue;
            }
            int y = x + j;
            if (y >= m) {
                y -= m;
            }
            b[i][y] = true;
        }
    }

    if (b[n - 1][0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}