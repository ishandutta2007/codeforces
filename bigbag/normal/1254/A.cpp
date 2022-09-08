#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, m, k;
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<char> allc;
    for (int i = '0'; i <= '9'; ++i) {
        allc.push_back(i);
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        allc.push_back(i);
    }
    for (int i = 'A'; i <= 'Z'; ++i) {
        allc.push_back(i);
    }
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            for (int j = 0; j < m; ++j) {
                cnt += s[i][j] == 'R';
            }
        }
        vector<int> v;
        for (int i = 0; i < k; ++i) {
            v.push_back(cnt / k);
        }
        for (int i = 0; i < cnt % k; ++i) {
            ++v[i];
        }
        vector<pair<int, int>> all;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < m; ++j) {
                    all.push_back({i, j});
                }
            } else {
                for (int j = m - 1; j >= 0; --j) {
                    all.push_back({i, j});
                }
            }
        }
        int pos = 0;
        for (int i = 0; i < k; ++i) {
            int cnt = 0;
            while (pos < all.size() && cnt + (s[all[pos].first][all[pos].second] == 'R') <= v[i]) {
                cnt += (s[all[pos].first][all[pos].second] == 'R');
                s[all[pos].first][all[pos].second] = allc[i];
                ++pos;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << s[i] << "\n";
        }
    }
    return 0;
}