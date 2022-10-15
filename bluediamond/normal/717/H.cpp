#include <bits/stdc++.h>

using namespace std;

mt19937 rng((long long) (new char));
const int N = 50000 + 7;
const int T = 1000000 + 7;
int n;
int m;
int t;
int col[N];
vector<int> g[N];
vector<int> a[N];
int d[T];
int p[N];

void dfs(int a) {
        int cnt1 = 0;
        int cnt2 = 0;
        for (auto &b : g[a]) {
                if (col[b] == 1) {
                        cnt1++;
                }
                if (col[b] == 2) {
                        cnt2++;
                }
        }
        if (cnt1 < cnt2) {
                col[a] = 1;
        } else {
                col[a] = 2;
        }
        for (auto &b : g[a]) {
                if (col[b] == 0) {
                        dfs(b);
                }
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
                int x, y;
                cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
                if (col[i] == 0) {
                        dfs(i);
                }
        }
        for (int i = 1; i <= n; i++) {
                int l;
                cin >> l;
                a[i].resize(l);
                for (int j = 0; j < l; j++) {
                        cin >> a[i][j];
                        t = max(t, a[i][j]);
                }
        }
        while (1) {
                for (int i = 1; i <= t; i++) {
                        d[i] = 1 + rng() % 2;
                }
                bool ok = 1;
                for (int i = 1; i <= n; i++) {
                        bool have = 0;
                        for (auto &j : a[i]) {
                                if (d[j] == col[i]) {
                                        p[i] = j;
                                        have = 1;
                                        break;
                                }
                        }
                        if (have == 0) {
                                ok = 0;
                                break;
                        }
                }
                if (ok) {
                        break;
                }
        }
        for (int i = 1; i <= n; i++) {
                cout << p[i] << " ";
        }
        cout << "\n";
        for (int i = 1; i <= t; i++) {
                cout << d[i] << " ";
        }
        cout << "\n";

}