#include <bits/stdc++.h>

using namespace std;

int n, m, sx, sy;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> sx >> sy;
    vector<int> xs{sx};
    for (int x = 1; x <= n; ++x) {
        if (x != sx) {
            xs.push_back(x);
        }
    }
    for (int x : xs) {
        int lasty;
        for (int y = sy; y <= m; ++y) {
            cout << x << " " << y << "\n";
            lasty = y;
        }
        for (int y = 1; y < sy; ++y) {
            cout << x << " " << y << "\n";
            lasty = y;
        }
        sy = lasty;
    }
    return 0;
}