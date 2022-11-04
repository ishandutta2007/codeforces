#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1010;
const int INF = 2e9;
const int DX[4] = {1, 0, 0, -1};
const int DY[4] = {0, -1, 1, 0};
const string S = "DLRU";

int n, m, k;
string f[MAX_N];
int dist[MAX_N][MAX_N];
int posx, posy;

bool check(int a, int b) {
    return a >= 0 && a < n && b >= 0 && b < m && f[a][b] != '*';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    if ((k % 2) == 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    queue<pair<int, int>> bfs;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 'X') {
                posx = i;
                posy = j;
                dist[i][j] = 0;
                bfs.push({posx, posy});
            } else {
                dist[i][j] = INF;
            }
        }
    }
    int cnt = 0;
    while (bfs.size()) {
        pair<int, int> p = bfs.front();
        bfs.pop();
        for (int d = 0; d < 4; d++) {
            int x = p.first + DX[d];
            int y = p.second + DY[d];
            if (check(x, y)) {
                if (dist[x][y] == INF) {
                    dist[x][y] = dist[p.first][p.second] + 1;
                    cnt++;
                    bfs.push({x, y});
                }
            }
        }
    }
    if (!cnt) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 0; i < k; i++) {
        if (dist[posx][posy] == k - i) {
            for (int d = 0; d < 4; d++) {
                if (check(posx + DX[d], posy + DY[d]) && dist[posx + DX[d]][posy + DY[d]] < dist[posx][posy]) {
                    cout << S[d];
                    posx += DX[d];
                    posy += DY[d];
                    break;
                }
            }
            continue;
        }
        for (int d = 0; d < 4; d++) {
            if (check(posx + DX[d], posy + DY[d])) {
                cout << S[d];
                posx += DX[d];
                posy += DY[d];
                break;
            }
        }
    }
}