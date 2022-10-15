#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n;
int m;
vector<int> g[N];
vector<int> g2[N];
int l[N];
int r[N];
int p;
int sol[N];

void dfs(int a) {
        p++;
        l[a] = p;
        for (auto &b : g[a]) {
                if (l[b] == 0) {
                        g2[a].push_back(b);
                        dfs(b);
                }
        }
        r[a] = p;
}

struct Segment {
        int l;
        int r;
};

vector<Segment> c[N];

struct Data {
        int v;
        int val_t;
        bool val_send;
};

vector<vector<Data>> temporary;

int t[4 * N];
bool send[4 * N];

void add(int v) {
        temporary.back().push_back({v, t[v], send[v]});
}

void push(int v, int tl, int tr) {
        if (send[v]) {
                t[v] = tr - tl + 1;
                if (tl < tr) {
                        send[2 * v] = send[2 * v + 1] = 1;
                }
                send[v] = 0;
        }
}

void make(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (tr < l || r < tl) {
                return;
        }
        if (l <= tl && tr <= r) {
                send[v] = 1;
                push(v, tl, tr);
                return;
        }
        int tm = (tl + tr) / 2;
        make(2 * v, tl, tm, l, r);
        make(2 * v + 1, tm + 1, tr, l, r);
        t[v] = t[2 * v] + t[2 * v + 1];
}

void make(int tl, int tr) {
        make(1, 1, n, tl, tr);
}

void add_all(int v, int tl, int tr, int l, int r) {
        add(v);
        if (tr < l || r < tl) {
                if (tl < tr) {
                        add(2 * v);
                        add(2 * v + 1);
                }
                return;
        }
        if (l <= tl && tr <= r) {
                if (tl < tr) {
                        add(2 * v);
                        add(2 * v + 1);
                }
                return;
        }
        int tm = (tl + tr) / 2;
        add_all(2 * v, tl, tm, l, r);
        add_all(2 * v + 1, tm + 1, tr, l, r);
}

void roll_back() {
        for (auto &it : temporary.back()) {
                t[it.v] = it.val_t;
                send[it.v] = it.val_send;
        }
        temporary.pop_back();
}

void dfs2(int a) {
        temporary.push_back({});
        for (auto &it : c[a]) {
                add_all(1, 1, n, it.l, it.r);
        }
        for (auto &it : c[a]) {
                make(it.l, it.r);
        }
        sol[a] = t[1];
        for (auto &b : g[a]) {
                dfs2(b);
        }
        roll_back();
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> m;
        for (int i = 1; i < n; i++) {
                int a, b;
                cin >> a >> b;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        dfs(1);
        for (int i = 1; i <= n; i++) {
                g[i] = g2[i];
        }
        while (m--) {
                int a, b, l1, r1, l2, r2;
                cin >> a >> b;
                l1 = l[a];
                r1 = r[a];
                l2 = l[b];
                r2 = r[b];
                c[a].push_back({l1, r1});
                c[a].push_back({l2, r2});
                c[b].push_back({l1, r1});
                c[b].push_back({l2, r2});
        }
        dfs2(1);
        for (int i = 1; i <= n; i++) {
                if (sol[i]) {
                        sol[i]--;
                }
                cout << sol[i] << " ";
        }
        cout << "\n";
}