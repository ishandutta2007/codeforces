#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
bool home = 1;

const int N = 2000 + 7;
bitset<N> b[N];
int n;
int m;
int team[N];
vector<int> g[N];
bool vis[N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }

        int tests;
        cin >> tests;
        for (int tc = 1; tc <= tests; tc++) {
                cin >> n >> m;
                for (int i = 1; i <= n; i++) {
                        b[i] = 0;
                        g[i].clear();
                        vis[i] = 0;
                        team[i] = 0;
                }
                for (int i = 1; i <= m; i++) {
                        int a, b;
                        cin >> a >> b;
                        g[a].push_back(b);
                        g[b].push_back(a);
                }
                bool isOk = true;
                for (int i = 1; i <= n; i++) {
                        if ((int) g[i].size() % 2 == 1) {
                                isOk = false;
                                break;
                        }
                }
                if (isOk) {
                        cout << "1\n";
                        for (int i = 1; i <= n; i++) {
                                cout << "1 ";
                        }
                        cout << "\n";
                        continue;
                }
                for (int i = 1; i <= n; i++) {
                        for (auto &j : g[i]) {
                                b[i][j] = 1;
                        }
                        if ((int) g[i].size() % 2 == 1) {
                                b[i][i] = 1;
                                b[i][n + 1] = 1;
                        }
                }
                for (int j = 1; j <= n; j++) {
                        int pos = -1;
                        for (int i = 1; i <= n; i++) {
                                if (b[i][j] && !vis[i]) {
                                        pos = i;
                                        break;
                                }
                        }
                        if (pos == -1) continue;
                        vis[pos] = 1;
                        for (int i = 1; i <= n; i++) {
                                if (b[i][j] && i != pos) {
                                        b[i] ^= b[pos];
                                }
                        }
                }


                cout << "2\n";
                for (int i = n; i >= 1; i--) {
                        int first = -1;
                        for (int j = 1; j <= n; j++) {
                                if (b[i][j]) {
                                        first = j;
                                        break;
                                }
                        }
                        if (first != -1) {
                                team[first] = b[i][n + 1];
                                for (int j = first + 1; j <= n; j++) {
                                        if (b[i][j]) {
                                                team[first] ^= team[j];
                                        }
                                }
                        }
                }
                for (int i = 1; i <= n; i++) {
                        cout << 1 + team[i] << " ";
                }
                cout << "\n";
        }


}