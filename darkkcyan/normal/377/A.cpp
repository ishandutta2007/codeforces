#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m, k; cin >> n >> m >> k;
    vector<string> maze(n);
    for (auto& i: maze) cin >> i;
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    vector<int> parent(n * m, -1), childcnt(n * m , 0);
    bool checked = 0;
    for (int i = n; i-- and !checked; ) for (int f = m; f-- and !checked; ) {
        if (maze[i][f] == '#') continue;
        checked = true;
        queue<pair<int, int>> qu;
        qu.push({i, f});
        for (; qu.size(); qu.pop()) {
            int r = qu.front().first, c = qu.front().second;
            for (int dir = 4; dir--; ) {
                int nr = r + dr[dir], nc = c + dc[dir];
                if (nr >= n or nr < 0 or nc >= m or nc < 0) continue;
                if (maze[nr][nc] != '.') continue;
                if (parent[nr * m + nc] != -1) continue;
                parent[nr * m + nc] = r * m + c;
                ++childcnt[r * m + c];
                qu.push({nr, nc});
            }
        }
    }
    set<tuple<int, int>> prio;
    for (int i = n * m; i--; ) 
        if (maze[i / m][i % m] == '.') prio.insert({childcnt[i], i});
    
    while (k--) {
        auto [cnt, u] = *prio.begin();
        prio.erase(prio.begin());
        maze[u / m][u % m] = 'X';
        if (parent[u] == -1) continue;
        prio.erase({childcnt[parent[u]], parent[u]});
        --childcnt[parent[u]];
        prio.insert({childcnt[parent[u]], parent[u]});
    }
    for (auto& i: maze) cout << i << '\n';
}