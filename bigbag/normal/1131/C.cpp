#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, a[max_n], dp[max_n][max_n], p[max_n][max_n];
int px[max_n][max_n];

void upd(int i, int j, int x, int tp, int pr) {
    if (dp[i][j] > x) {
        dp[i][j] = x;
        p[i][j] = tp;
        px[i][j] = pr;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int last = 0; last + 1 < n; ++last) {
        for (int i = 0; i <= last; ++i) {
            int x = last, y = i;
            for (int it = 0; it < 2; ++it) {
                int mx = 0;
                if (last + 2 == n) {
                    mx = max(a[last + 1] - a[x], a[last + 1] - a[y]);
                }
                upd(last + 1, y, max({dp[x][y], a[last + 1] - a[x], mx}), 0, x);
                upd(x, last + 1, max({dp[x][y], a[last + 1] - a[y], mx}), 1, y);
                swap(x, y);
            }
        }
    }
    int ans = inf, x, y;
    for (int i = 0; i < n; ++i) {
        if (ans > dp[n - 1][i]) {
            ans = dp[n - 1][i];
            x = n - 1;
            y = i;
        } else if (ans > dp[i][n - 1]) {
            ans = dp[i][n - 1];
            x = i;
            y = n - 1;
        }
    }
    vector<int> v1, v2;
    while (x || y) {
        if (p[x][y] == 0) {
            v1.push_back(a[x]);
            x = px[x][y];
        } else {
            v2.push_back(a[y]);
            y = px[x][y];
        }
    }
    v1.push_back(a[0]);
    reverse(v1.begin(), v1.end());
    for (int x : v1) {
        cout << x << " ";
    }
    for (int x : v2) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}