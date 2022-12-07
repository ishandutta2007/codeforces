#include <bits/stdc++.h>
using namespace std;
#define int long long

set<pair<int, int>> bench;

void insert(int a, int b) {
    if(a > b) swap(a, b);
    bench.insert({a, b});
}

bool doesnt(int a, int b) {
    if(a > b) swap(a, b);
    return (bench.find({a, b}) == bench.end());
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    int p, q;
    cin >> p >> q;
    int INF = (int)1E18;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, INF));
    // set ---> pair<int, int>, int = m*i + j. THese pairs mark a sunbench
    // set<pair<int, int>> bench;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == '.') {
                dist[i][j] = 0;
            }
        }
    }
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shift[4][2] = {{2, 0}, {0, 2}, {-2, 0}, {0, -2}}; 
    int rot[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(grid[i][j] == '#' || x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#') continue;
                if(k == 0) {
                    if(grid[i][j] == 'U' && grid[x][y] == 'D') {
                        // bench.insert({i*m+j, x*m+y});
                        // bench.insert({x*m+y, i*m+j});
                        insert(i*m + j, x*m + y);
                    }
                } else if(k == 2) {
                    if(grid[i][j] == 'L' && grid[x][y] == 'R') {
                        // bench.insert({i*m+j, x*m+y});
                        // bench.insert({x*m+y, i*m+j});
                        insert(i*m + j, x*m + y);
                    }
                }
            }
        }
    }
    priority_queue<pair<int, pair<int, int>>> pq; // {-dist, {i, j}}
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dist[i][j] == 0) {
                pq.push({0, {i, j}});
            }
        }
    }
    while(!pq.empty()) {
        // Dijkstra
        auto temp = pq.top();
        pq.pop();
        int d = -temp.first;
        int a = temp.second.first;
        int b = temp.second.second;
        if(dist[a][b] < d) continue;
        for(int k = 0; k < 4; k++) {
            int x = a + shift[k][0];
            int y = b + shift[k][1];
            if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#' || grid[(a + x)/2][(b + y)/2] == '#') continue;
            int temp = ((a+x)/2)*m + ((b+y)/2);
            // if(bench.find({temp, x*m + y}) == bench.end()) continue;
            if(doesnt(temp, x*m + y)) continue;
            if(dist[x][y] > dist[a][b] + q) {
                dist[x][y] = dist[a][b] + q;
                pq.push({-dist[x][y], {x, y}});
            }
        }
        for(int k = 0; k < 4; k++) {
            int x = a + rot[k][0];
            int y = b + rot[k][1];
            if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#') continue;
            if(grid[a][y] == '#' && grid[x][b] == '#') continue;
            // if(bench.find({a*m + y, x*m + y}) == bench.end() && bench.find({x*m + b, x*m + y}) == bench.end()) continue;
            if(doesnt(a*m + y, x*m + y) && doesnt(x*m + b, x*m + y)) continue;
            if(dist[x][y] > dist[a][b] + p) {
                dist[x][y] = dist[a][b] + p;
                pq.push({-dist[x][y], {x, y}});
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(grid[i][j] == '#' || x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#') continue;
                ans = min(ans, dist[i][j] + dist[x][y]);
            }
        }
    }
    if(ans >= INF) ans = -1;
    cout << ans << '\n';
    
    return 0;
}