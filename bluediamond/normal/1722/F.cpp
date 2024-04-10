#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr bool multiple_test_cases = true;
int main() {
    auto main = [](){
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (auto& si : s) cin >> si;
        vector v(n, vector<int>(m));
        auto check = [&](int x, int y) {
            return x >= 0 and x < n and y >= 0 and y < m;
        };
        auto check_star = [&](int x, int y) {
            return check(x, y) and s[x][y] == '*';
        };
        int c = 0, ok = 1;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1)
                if (s[i][j] == '*' and not v[i][j]) {
                    int count = 0, direction = 0;
                    for (int k = 0; k < 4; k += 1) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (check_star(ni, nj)) {
                            count += 1;
                            direction |= 1 << (k >> 1);
                        }
                    }
                    if (count == 2 and direction == 3) {
                        v[i][j] = c += 1;
                        for (int k = 0; k < 4; k += 1) {
                            int ni = i + dx[k], nj = j + dy[k];
                            if (check_star(ni, nj)) {
                                v[ni][nj] = c;
                            }
                        }
                    }
                }
        }
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < m; j += 1)
                if (s[i][j] == '*') {
                    if (not v[i][j]) ok = 0;
                    for (int di = -1; di <= 1; di += 1)
                        for (int dj = -1; dj <= 1; dj += 1) {
                            int ni = i + di, nj = j + dj;
                            if (check_star(ni, nj) and v[ni][nj] != v[i][j])
                                ok = 0;
                        }
            }
        cout << (ok ? "YES\n" : "NO\n");
    };
/*================================================*/
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    if (multiple_test_cases) {
        cin >> t;
    }
    for (int ti = 1; ti <= t; ti += 1) {
        main();
    }
}