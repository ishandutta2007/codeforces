#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n;
vector<int> g2[N];
vector<int> g[N];
bool vis[N];
vector<pair<int, int>> sol;
int lim;

void build(int a) {
        vis[a] = 1;
        for (auto &b : g2[a]) {
                if (vis[b] == 0) {
                        build(b);
                        g[a].push_back(b);
                }
        }
}

void add(int a, int t) {
        sol.push_back({a, t});
}

void dfs(int a, int t) {
        add(a, t);
        if (a != 1) {
                int wannabe = t - 1;
                int lft = (int) g[a].size();
                for (auto &b : g[a]) {
                        if (t == lim) {
                                t = wannabe - lft;
                                add(a, t);
                        }
                        lft--;
                        dfs(b, t + 1);
                        add(a, t + 1);
                        t++;
                }
                if (t > wannabe) {
                        add(a, wannabe);
                }
                if (t < wannabe) {
                        cout << "error on " << a << "\n";
                }
        } else {
                for (auto &b : g[a]) {
                        dfs(b, t + 1);
                        add(a, t + 1);
                        t++;
                }
        }
}

void print() {
        cout << (int) sol.size() << "\n";
        for (auto &it : sol) {
                cout << it.first << " " << it.second << "\n";
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i < n; i++) {
                int a, b;
                cin >> a >> b;
                g2[a].push_back(b);
                g2[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
                lim = max(lim, (int) g2[i].size());
        }
        build(1);
        dfs(1, 0);
        print();
}