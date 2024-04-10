#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, inf = 1000111222;

namespace hungarian {

namespace internal {

const int N = 444;

long long c[N][N];
long long fx[N], fy[N], d[N];
int mx[N], my[N], trace[N], arg[N];
queue<int> q;
int start, finish, n;

const long long inf = 1e18;

void init(const vector<vector<int>> &a) {
    const int init_n = a.size();
    const int init_m = a[0].size();
    n = max(init_n, init_m);
    assert(n < N);
    for (int i = 1; i <= n; ++i) {
        fy[i] = mx[i] = my[i] = 0;
        for (int j = 1; j <= n; ++j) {
            if (i <= init_n) {
                if (j <= init_m) {
                    c[i][j] = a[i - 1][j - 1];
                    assert(c[i][j] < inf);
                } else {
                    c[i][j] = inf;
                }
            } else {
                c[i][j] = 0;
            }
        }
    }
}

inline long long getC(int u, int v) {
    return c[u][v] - fx[u] - fy[v];
}

void initBFS() {
    while (!q.empty()) {
        q.pop();
    }
    q.push(start);
    for (int i = 0; i <= n; ++i) {
        trace[i] = 0;
    }
    for (int v = 1; v <= n; ++v) {
        d[v] = getC(start, v);
        arg[v] = start;
    }
    finish = 0;
}

void findAug() {
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; ++v) {
            if (!trace[v]) {
                long long w = getC(u, v);
                if (!w) {
                    trace[v] = u;
                    if (!my[v]) {
                        finish = v;
                        return;
                    }
                    q.push(my[v]);
                }
                if (d[v] > w) {
                    d[v] = w;
                    arg[v] = u;
                }
            }
        }
    }
}

void subX_addY() {
    long long delta = inf ;
    for (int v = 1; v <= n; ++v) {
        if (trace[v] == 0 && d[v] < delta) {
            delta = d[v];
        }
    }
    fx[start] += delta;
    for (int v = 1; v <= n; ++v) {
        if (trace[v]) {
            int u = my[v];
            fy[v] -= delta;
            fx[u] += delta;
        } else {
            d[v] -= delta;
        }
    }
    for (int v = 1; v <= n; ++v) {
        if (!trace[v] && !d[v]) {
            trace[v] = arg[v];
            if (!my[v]) {
                finish = v; return;
            }
            q.push(my[v]);
        }
    }
}

void Enlarge() {
    do {
        int u = trace[finish];
        int nxt = mx[u];
        mx[u] = finish;
        my[finish] = u;
        finish = nxt;
    } while (finish);

}

pair<vector<int>, long long> MinCost() {
    for (int u = 1; u <= n; ++u) {
        fx[u] = c[u][1];
        for (int v = 1; v <= n; ++v) {
            fx[u] = min(fx[u], c[u][v]);
        }
    }
    for (int v = 1; v <= n; ++v) {
        fy[v] = c[1][v] - fx[1];
        for (int u = 1; u <= n; ++u) {
            fy[v] = min(fy[v], c[u][v] - fx[u]);
        }
    }
    for (int u = 1; u <= n;++u) {
        start = u;
        initBFS();
        findAug();
        while (!finish) {
            subX_addY();
            findAug();
        }
        Enlarge();
    }
    long long sum = 0;
    for (int u = 1; u <= n; ++u) {
        if (c[u][mx[u]] != inf) {
            sum += c[u][mx[u]];
        }
    }
    vector<int> res{mx + 1, mx + n + 1};
    return {res, sum};
}

}

pair<vector<int>, long long> min_cost(const vector<vector<int>> &a) {
    internal::init(a);
    auto res = internal::MinCost();
    res.first.resize(a.size() + 1);
    for (int &id : res.first) {
        --id;
        if (id >= a[0].size()) {
            id = -1;
        }
    }
    return res;
}

pair<vector<int>, long long> max_cost(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int &x : a[i]) {
            x *= -1;
        }
    }
    auto res = min_cost(a);
    res.second *= -1;
    return res;
}

}

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> v(n, vector<int> (2 * n));
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < 2 * n; ++j) {
                v[i][j] = abs(a[i] - j - 1);
            }
        }
        cout << hungarian::min_cost(v).second << "\n";
    }
    return 0;
}