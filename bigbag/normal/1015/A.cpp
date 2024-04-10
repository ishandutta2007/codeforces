#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, m, l, r, used[max_n];
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while (n--) {
        cin >> l >> r;
        fill(used + l, used + r + 1, 1);
    }
    for (int i = 1; i <= m; ++i) {
        if (!used[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}