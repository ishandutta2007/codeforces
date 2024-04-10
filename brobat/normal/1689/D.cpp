#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
const int N = 1005;
char grid[N][N];
const int INF = (int)1E18;

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

pair<int, int> closest(pair<int, int> x) {
    pair<int, int> ans = {INF, INF};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'B') {
                if(dist(x, {i, j}) < dist(x, ans)) {
                    ans = {i, j};
                }
            }
        }
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<pair<int, int>> b;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'B') {
                    b.push_back({i, j});
                }
            }
        }
        vector<pair<int, int>> corners = {{0, 0}, {0, m - 1}, {n - 1, 0}, {n - 1, m - 1}};
        vector<pair<int, int>> source(4);
        for(int i = 0; i < 4; i++) {
            source[i] = closest(corners[i]);
        }
        vector<vector<vector<int>>> dist(4, vector<vector<int>>(n, vector<int>(m, -1)));
        for(int s = 0; s < 4; s++) {
            queue<pair<int, int>> q;
            q.push(source[s]);
            dist[s][source[s].first][source[s].second] = 0;
            while(!q.empty()) {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int x = a + d[k][0];
                    int y = b + d[k][1];
                    if(x < 0 || y < 0 || x >= n || y >= m) continue;
                    if(dist[s][x][y] == -1) {
                        q.push({x, y});
                        dist[s][x][y] = dist[s][a][b] + 1;
                    }
                }
            }
        }

        // for(int k = 0; k < 4; k++) {
        //     cerr << corners[k].first << " " << corners[k].second << " " << source[k].first << " " << source[k].second << '\n';
        //     for(int i = 0; i < n; i++) {
        //         for(int j = 0; j < m; j++) {
        //             cerr << dist[k][i][j] << " ";
        //         }
        //         cerr << '\n';
        //     }
        //     cerr << '\n';
        // }
        

        vector<vector<int>> mx(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < 4; k++) {
                    mx[i][j] = max(mx[i][j], dist[k][i][j]);
                }
            }
        }

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cerr << mx[i][j] << " ";
        //     }
        //     cerr << '\n';
        // }

        int ans_val = INF;
        pair<int, int> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mx[i][j] < ans_val) {
                    ans_val = mx[i][j];
                    ans = {i, j};
                }
            }
        }

        // cout << ans << '\n';
        cout << ans.first + 1 << " " << ans.second + 1 << '\n';
    }
    
    return 0;
}