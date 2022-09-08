#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;
const int max_b = 19;

int n, q, a[max_n], dist[max_b];
vector<int> nxt[max_b][max_b];

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

bool solve(int st, int fin) {
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < max_b; ++i) {
        dist[i] = n;
        if (get_bit(a[st], i)) {
            dist[i] = st;
            q.push({-dist[i], i});
            if (get_bit(a[fin], i)) {
                return true;
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int v = p.second;
        if (dist[v] != -p.first) {
            continue;
        }
        for (int to = 0; to < max_b; ++to) {
            if (v == to) {
                continue;
            }
            int X = v, Y = to;
            if (X > Y) {
                swap(X, Y);
            }
            if (dist[to] > nxt[X][Y][dist[v]] && nxt[X][Y][dist[v]] <= fin) {
                if (get_bit(a[fin], to)) {
                    return true;
                }
                dist[to] = nxt[X][Y][dist[v]];
                q.push({-dist[to], to});
            }
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < max_b; ++i) {
        for (int j = i + 1; j < max_b; ++j) {
            nxt[i][j].resize(n, n);
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < max_b; ++i) {
        for (int j = i + 1; j < max_b; ++j) {
            for (int pos = n - 1; pos >= 0; --pos) {
                if (get_bit(a[pos], i) && get_bit(a[pos], j)) {
                    nxt[i][j][pos] = pos;
                } else if (pos + 1 < n) {
                    nxt[i][j][pos] = nxt[i][j][pos + 1];
                }
            }
        }
    }
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        bool ok = solve(x, y);
        if (ok) {
            puts("Shi");
        } else {
            puts("Fou");
        }
    }
    return 0;
}