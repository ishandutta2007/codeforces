#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 300005;
int n, m, p, q;
i64 dis[N];
string s[N];

inline int ID(int x, int y) {
    return (x - 1) * m + y;
}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dir[] = {'U', 'L', 'D', 'R'};

int find(char c) {
    for (int i = 0; i < 4; ++i) {
        if (c == dir[i]) {
            return i;
        }
    }
    return -1;
}

bool check(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m && s[x][y] != '#';
}

struct node {
    int u;
    i64 d;
    inline bool operator<(const node &rhs) const {
        return d > rhs.d;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }

    memset(dis, 0x3f, sizeof dis);
    priority_queue<node> pq;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '.') {
                dis[ID(i, j)] = 0;
                pq.push({ID(i, j), 0});
            }
        }
    }

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int u = cur.u;
        if (dis[u] != cur.d) {
            continue;
        }
        int x = (u - 1) / m + 1;
        int y = (u - 1) % m + 1;

        for (int k = 0; k < 4; ++k) {
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            if (check(x1, y1)) {
                int d = find(s[x1][y1]);
                if (d != -1) {
                    int x2 = x1 + dx[d];
                    int y2 = y1 + dy[d];
                    int v = ID(x2, y2);
                    i64 val = dis[u] + (abs(x - x2) == 1 ? p : q);
                    if (dis[v] > val) {
                        dis[v] = val;
                        pq.push({v, val});
                    }
                }
            }
        }
    }

    i64 ans = 1e18;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (check(i, j)) {
                // printf("dis(%d, %d) = %lld\n", i, j, dis[ID(i, j)]);
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (check(x, y)) {
                        ans = min(ans, dis[ID(i, j)] + dis[ID(x, y)]);
                    }
                }
            }
        }
    }

    if (ans > 1e16) {
        ans = -1;
    }
    cout << ans << "\n";

    return 0;
}