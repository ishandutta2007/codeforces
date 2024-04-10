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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int sx, sy;
    cin >> sx >> sy;
    --sx;
    --sy;

    string s;
    cin >> s;

    cout << 1 << " ";

    vector<vector<bool>> used(n, vector<bool>(m, false));
    used[sx][sy] = true;
    int count = 0;
    for (int i = 0; i < (int) s.length(); ++i) {
        if (s[i] == 'U') {
            sx = max(0, sx - 1);
        } else if (s[i] == 'D') {
            sx = min(sx + 1, n - 1);
        } else if (s[i] == 'L') {
            sy = max(0, sy - 1);
        } else if (s[i] == 'R') {
            sy = min(sy + 1, m - 1);
        }

        if (!used[sx][sy]) {
            used[sx][sy] = true;
            ++count;
        }

        if (i + 1 != s.length()) {
            cout << count << " ";
            count = 0;
        }
    }

    int remains = count;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j]) {
                ++remains;
            }
        }
    }

    cout << remains << endl;

    return 0;
}