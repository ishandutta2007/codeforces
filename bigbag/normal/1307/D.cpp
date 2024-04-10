#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

struct tree {
    int t[max_n];

    void init() {
        fill(t, t + max_n, -inf);
    }

    void update(int i, int x) {
        i = max_n - 1 - i;
        for (; i < max_n; i = (i | (i + 1))) {
            t[i] = max(t[i], x);
        }
    }

    int get_max(int r) const {
        r = max_n - 1 - r;
        r = min(r, max_n - 1);
        int res = -inf;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res = max(res, t[r]);
        }
        return res;
    }
};

int n, m, k, d[2][max_n];
vector<int> g[max_n], ok;

void bfs(int st, int d[]) {
    for (int i = 0; i < n; ++i) {
        d[i] = -1;
    }
    queue<int> q;
    q.push(st);
    d[st] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (d[to] == -1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
}

tree t;

bool check(int x) {
    t.init();
    for (int v : ok) {
        int mx = t.get_max(x - 1 - d[1][v]);
        if (mx >= x - 1 - d[0][v]) {
            return true;
        }
        t.update(d[0][v], d[1][v]);
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    ok.resize(k);
    for (int &x : ok) {
        scanf("%d", &x);
        --x;
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(0, d[0]);
    bfs(n - 1, d[1]);
    /*for (int i = 0; i < n; ++i) {
        cout << d[0][i] << " " << d[1][i] << endl;
    }
    cout << check(3) << endl;
    return 0;*/
    int l = 1, r = d[0][n - 1] + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);
    return 0;
}