#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    ++n;
    int x = 0, y = 0;
    while (n--) {
        if (ans.empty()) {
            ans.push_back({x, y});
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if ((i == 1 && j == 1) || (i + j == 0)) {
                    continue;
                }
                ans.push_back({x + i, y + j});
            }
        }
        x += 2;
        y += 2;
    }
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}