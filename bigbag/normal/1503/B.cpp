/**
 *  created: 03/04/2021, 17:49:35
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n;
vector<pair<int, int>> v[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int f = i % 2;
        for (int j = 0; j < n; ++j) {
            v[f].push_back({i + 1, j + 1});
            f ^= 1;
        }
    }
    for (int it = 0; it < n * n; ++it) {
        int col;
        cin >> col;
        if (v[0].empty()) {
            int ans = 2;
            if (col == 2) {
                ans = 3;
            }
            cout << ans << " " << v[1].back().first << " " << v[1].back().second << endl;
            v[1].pop_back();
            continue;
        }
        if (v[1].empty()) {
            int ans = 1;
            if (col == 1) {
                ans = 3;
            }
            cout << ans << " " << v[0].back().first << " " << v[0].back().second << endl;
            v[0].pop_back();
            continue;
        }
        int num = 0;
        if (col == 1) {
            num = 1;
        }
        cout << num + 1 << " " << v[num].back().first << " " << v[num].back().second << endl;
        v[num].pop_back();
    }
    return 0;
}