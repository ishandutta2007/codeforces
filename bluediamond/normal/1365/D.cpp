#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = 50 + 7;
int n, m, a[N][N], dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
bool vis[N][N];

bool inside(int r, int c) {
        return (1 <= r && 1 <= c && r <= n && c <= m);
}

void dfs(int r, int c) {
        vis[r][c] = 1;
        for (int k = 0; k < 4; k++) {
                int rn = r + dr[k];
                int cn = c + dc[k];
                if (inside(rn, cn) && a[rn][cn] != 1 && vis[rn][cn] == 0)
                        dfs(rn, cn);
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
                cin >> n >> m;
                for (int i = 1; i <= n; i++) {
                        string s;
                        cin >> s;
                        for (int j = 1; j <= m; j++) {
                                if (s[j - 1] == '.')
                                        a[i][j] = 0;
                                if (s[j - 1] == '#')
                                        a[i][j] = 1;
                                if (s[j - 1] == 'G')
                                        a[i][j] = 2;
                                if (s[j - 1] == 'B')
                                        a[i][j] = 3;
                        }
                }
                for (int i = 1; i <= n; i++)
                        for (int j = 1; j <= m; j++)
                                if (a[i][j] == 3)
                                        for (int k = 0; k < 4; k++) {
                                                int in = i + dr[k];
                                                int jn = j + dc[k];
                                                if (inside(in, jn) && a[in][jn] == 0)
                                                        a[in][jn] = 1;
                                        }
                for (int i = 1; i <= n; i++)
                        for (int j = 1; j <= m; j++)
                                vis[i][j] = 0;
                if (a[n][m] == 0)
                        dfs(n, m);
                bool ok = 1;
                for (int i = 1; i <= n; i++)
                        for (int j = 1; j <= m; j++) {
                                if (a[i][j] == 2 && vis[i][j] == 0)
                                        ok = 0;
                                if (a[i][j] == 3 && vis[i][j] == 1)
                                        ok = 0;
                        }
                if (ok) 
                        cout << "Yes\n";
                else 
                        cout << "No\n";
        }
        return 0;
}