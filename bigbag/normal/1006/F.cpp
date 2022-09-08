#include <bits/stdc++.h>

using namespace std;

const int max_n = 22, inf = 1000111222;

int n, m;
long long k, a[max_n][max_n], ans;
vector<long long> all[2][max_n][max_n];

void calc_down(int x, int y, int need, long long cur) {
    cur ^= a[x][y];
    if (need == 0) {
        all[0][x][y].push_back(cur);
        //cout << "@" << x << " " << y << " " << cur << endl;
        return;
    }
    if (x + 1 < n) {
        calc_down(x + 1, y, need - 1, cur);
    }
    if (y + 1 < m) {
        calc_down(x, y + 1, need - 1, cur);
    }
}

void calc_up(int x, int y, int need, long long cur) {
    cur ^= a[x][y];
    //cout << "!!!" << x << " " <<y << " " << need << " " << cur << endl;
    if (need == 0) {
        all[1][x][y].push_back(cur);
        //cout << "#" << x << " " << y << " " << cur << endl;
        return;
    }
    if (x > 0) {
        calc_up(x - 1, y, need - 1, cur);
    }
    if (y > 0) {
        calc_up(x, y - 1, need - 1, cur);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int len = n + m - 2;
    int down = len / 2;
    int up = len - down;
    calc_down(0, 0, down, 0);
    calc_up(n - 1, m - 1, up, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sort(all[1][i][j].begin(), all[1][i][j].end());
            for (long long x : all[0][i][j]) {
                long long y = x ^ k ^ a[i][j];
                ans += upper_bound(all[1][i][j].begin(), all[1][i][j].end(), y) - lower_bound(all[1][i][j].begin(), all[1][i][j].end(), y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}