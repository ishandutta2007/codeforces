#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S[1010101];
queue<pii> Q;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int n, m;

bool cango(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (S[x][y] == '#') return false;
    return true;
}

bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (S[x][y] != '.') return false;
    int a, b, i, j;
    for (i = 0; i < 4; i++) {
        a = 0, b = 0;
        for (j = 0; j < 4; j++) if (i != j) {
            x += dx[j]; y += dy[j];
            if (cango(x, y)) {
                a++;
                if (S[x][y] == '+' || S[x][y] == 'L') b++;
            }
            x -= dx[j]; y -= dy[j];
        }
        if (a > 0 && a == b) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, i, j, x, y;
    
    for (cin >> t; t--; ) {
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            cin >> S[i];
            for (j = 0; j < m; j++) {
                if (S[i][j] == 'L') {
                    x = i; y = j;
                }
            }
        }
        Q.emplace(x, y);
        for (; !Q.empty(); ) {
            tie(x, y) = Q.front(); Q.pop();
            for (i = 0; i < 4; i++) {
                x += dx[i]; y += dy[i];
                if (check(x, y)) {
                    S[x][y] = '+';
                    Q.emplace(x, y);
                }
                x -= dx[i]; y -= dy[i];
            }
        }
        for (i = 0; i < n; i++) {
            cout << S[i] << "\n";
        }
    }
    
    return 0;
}