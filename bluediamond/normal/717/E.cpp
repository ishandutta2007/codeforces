#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 7;
int n;
int c[N];
vector<int> g[N];
vector<int> path;
vector<int> sol;

void find_path(int a, int p) {
        path.push_back(a);
        for (auto &b : g[a]) {
                if (b != p) {
                        find_path(b, a);
                        return;
                }
        }
}

void add(int a) {
        sol.push_back(a);
        c[a] ^= 1;
}

void dfs(int a, int p) {
        add(a);
        for (auto &b : g[a]) {
                if (b != p) {
                        int before = (int) sol.size();
                        dfs(b, a);
                        if (before < (int) sol.size()) {
                                add(a);
                        }
                }
        }
        if (!c[a]) {
                add(p);
                add(a);
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++) {
                cin >> c[i];
                if (c[i] < 0) {
                        c[i] = 0;
                }
        }
        c[1] ^= 1;
        for (int i = 1; i < n; i++) {
                int x, y;
                cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        find_path(1, -1);
        for (int i = 0; i + 1 < (int) path.size(); i++) {
                int a = path[i];
                int b = path[i + 1];
                int p = -1;
                if (i > 0) {
                        p = path[i - 1];
                }
                add(a);

                for (auto &c : g[a]) {
                        if (c != p && c != b) {
                                int before = (int) sol.size();
                                dfs(c, a);
                                if (before < (int) sol.size()) {
                                        add(a);
                                }
                        }
                }

                if (!c[a]) {
                        add(b);
                        add(a);
                }
        }
        int b = path.back();
        if (!c[b]) {
                add(b);
        }
        for (auto &x : sol) {
                cout << x << " ";
        }
        cout << "\n";
}