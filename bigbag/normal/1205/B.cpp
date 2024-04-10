#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int max_b = 63;
const int max_m = 222;

int n, dist[max_m], f[max_m][max_m];
long long a[max_n];
vector<int> g[max_m];

bool get_bit(long long mask, int pos) {
    return (mask >> pos) & 1;
}

int fa, fb;

bool ok(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    return a != fa || b != fb;
}


void bfs(int v) {
    for (int i = 0; i < n; ++i) {
        dist[i] = inf;
    }
    dist[v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (ok(v, to) && dist[to] == inf) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    for (int b = 0; b < max_b; ++b) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += get_bit(a[i], b);
        }
        if (cnt >= 3) {
            puts("3");
            return 0;
        }
    }
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; ; ++i) {
        if (a[i] == 0) {
            n = i;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && (a[i] & a[j])) {
                f[i][j] = 1;
                g[i].push_back(j);
            }
        }
    }
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            for (int c = 0; c < n; ++c) {
                if (a != b && b != c && a != c && f[a][b] && f[b][c] && f[a][c]) {
                    puts("3");
                    return 0;
                }
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (f[i][j]) {
                fa = i;
                fb = j;
                if (fa > fb) {
                    swap(fa, fb);
                }
                bfs(i);
                if (dist[j] != inf) {
                    ans = min(ans, dist[j] + 1);
                }
            }
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}