#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n * m), id(n * m);
    for (int i = 0; i < n * m; ++i) {
        std::cin >> a[i];
        id[i] = i;
    }
    std::sort(id.begin(), id.end(), [&](int x, int y) {
        return a[x] < a[y] || (a[x] == a[y] && x < y);
    });
    std::vector<int> s(n * m);
    std::vector<std::vector<int>> p(n, std::vector<int>(m));
    for (int i = 0, j = 0; i < n * m; i = j) {
        j = i;
        while (j < n * m && a[id[i]] == a[id[j]]) {
            ++j;
        }
        for (int k = i; k < j; ++k) {
            s[k] = k;
        }
        std::sort(s.begin() + i, s.begin() + j, [&](int x, int y) {
            return x / m < y / m || (x / m == y / m && x % m > y % m);
        });
        for (int k = i; k < j; ++k) {
            p[s[k] / m][s[k] % m] = id[k];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                ans += p[i][j] < p[i][k];
            }
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}