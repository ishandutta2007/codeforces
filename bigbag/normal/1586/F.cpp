/**
 *  created: 17/10/2021, 15:21:58
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, k, a[max_n][max_n];
int ans;

void solve(int l, int r, int col) {
    if (l >= r) {
        return;
    }
    ans = max(ans, col);
    int sz = (r - l + 1) / k;
    vector<int> szs;
    for (int i = 0; i < k; ++i) {
        szs.push_back(sz);
    }
    for (int i = 0; i < (r - l + 1) % k; ++i) {
        ++szs[i];
    }
    vector<int> start(k);
    start[0] = l;
    for (int i = 1; i < k; ++i) {
        start[i] = start[i - 1] + szs[i - 1];
    }
    start.push_back(r + 1);
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            for (int x = start[i]; x < start[i + 1]; ++x) {
                for (int y = start[j]; y < start[j + 1]; ++y) {
                    a[x][y] = col;
                }
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        solve(start[i], start[i + 1] - 1, col + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    solve(0, n - 1, 1);
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cout << a[i][j] << " ";
        }
    }
    cout << "\n";
    return 0;
}