#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    map<int, int> X, Y;
    ++X[x1];
    ++X[x2];
    ++X[x3];
    ++Y[y1];
    ++Y[y2];
    ++Y[y3];

    int x = 0, y = 0;
    for (auto [i, j] : X) {
        if (j == 2) {
            x = i;
        }
    } 
    for (auto [i, j] : Y) {
        if (j == 2) {
            y = i;
        }
    }

    int tx, ty;
    cin >> tx >> ty;

    vector<string> res{"NO", "YES"};
    if (x == 1 && y == 1) {
        cout << res[tx == 1 || ty == 1] << "\n";
    } else if (x == 1 && y == n) {
        cout << res[tx == 1 || ty == n] << "\n";
    } else if (x == n && y == 1) {
        cout << res[tx == n || ty == 1] << "\n";
    } else if (x == n && y == n) {
        cout << res[tx == n || ty == n] << "\n";
    } else {
        cout << res[tx % 2 == x % 2 || ty % 2 == y % 2] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}