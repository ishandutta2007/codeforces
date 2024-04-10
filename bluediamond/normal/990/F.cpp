#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define vi vector<int>
const int N = (int) 2e5 + 7;
int n;
int m;
int s[N];
int x[N];
int y[N];
vi g[N];
bool vis[N];
int sol[N];

void dfs(int a) {
        vis[a] = 1;
        for (auto &i : g[a]) {
                int b = x[i] ^ y[i] ^ a;
                if (vis[b] == 0) {
                        dfs(b);
                        if (x[i] == a) {
                                sol[i] += s[b];
                        } else {
                                sol[i] -= s[b];
                        }
                        s[a] += s[b];
                        s[b] = 0;
                }
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int zoom = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
                cin >> s[i];
                zoom += s[i];
        }
        if (zoom != 0) {
                cout << "Impossible\n";
                return 0;
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
                cin >> x[i] >> y[i];
                g[x[i]].pb(i);
                g[y[i]].pb(i);
        }
        dfs(1);
        cout << "Possible\n";
        for (int i = 1; i <= m; i++) {
                cout << sol[i] << "\n";
        }
}