#include <bits/stdc++.h>

using namespace std;

long long solve(long long n, long long m) {
    if (n > m) {
        swap(n, m);
    }
    if (n == 1) {
        long long res = (m / 6) * 6;
        m %= 6;
        if (m >= 4) {
            res += 2 * (m - 3);
        }
        return res;
    }
    if (n == 2) {
        if (m <= 2) {
            return 0;
        }
        if (m == 3) {
            return 4;
        }
        if (m == 7) {
            return 12;
        }
        return n * m;
    }
    if (n % 2 == 0 || m % 2 == 0) {
        return n * m;
    }
    return n * m - 1;
}

int get_num(int n, int m, int x, int y) {
    return x * m + y;
}

const int max_n = 1111;

char used[max_n];
int to[max_n];
vector<int> g[max_n];

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (int go : g[v]) {
        if (to[go] == -1 || dfs(to[go])) {
            to[go] = v;
            return true;
        }
    }
    return false;
}

int triv(int n, int m) {
    memset(to, -1, sizeof(to));
    int res = 0, all = n * m;
    for (int i = 0; i < all; ++i) {
        g[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        bool cur = i % 2;
        for (int j = 0; j < m; ++j) {
            if (cur) {
                for (int dx = -3; dx <= 3; ++dx) {
                    for (int dy = -3; dy <= 3; ++dy) {
                        if (abs(dx) + abs(dy) == 3) {
                            int nx = i + dx, ny = j + dy;
                            if (0 <= nx && 0 <= ny && nx < n && ny < m) {
                                //cout << i << " " << j << " -> " << nx << " " << ny << endl;
                                g[get_num(n, m, i, j)].push_back(get_num(n, m, nx, ny));
                            }
                        }
                    }
                }
            }
            cur ^= 1;
        }
    }
    for (int i = 0; i < all; ++i) {
        memset(used, 0, sizeof(used));
        res += dfs(i);
    }
    return 2 * res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (1) {
        long long n, m;
        cin >> n >> m;
        cout << solve(n, m) << "\n";
    } else {
        for (int n = 1; n <= 30; ++n) {
            for (int m = 1; m <= 30; ++m) {
                int my = solve(n, m);
                int ok = triv(n, m);
                if (my != ok) {
                    cout << n << " " << m << endl;
                    cout << "my: " << my << endl;
                    cout << "ok: " << ok << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}