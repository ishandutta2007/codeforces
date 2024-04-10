#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 33, inf = 111111111;

int n, m, k, a[max_n][max_n];
map <string, pair<int, int> > q;

void add(int x, int y, string s) {
    a[x][y] = 1;
    q[s] = make_pair(x, y);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int z = 0; z < k; ++z) {
        int t, x, y;
        string s;
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> s;
            int ff = 0;
            for (int i = x; i <= n; ++i) {
                int pp = 1;
                if (i == x) {
                    pp = y;
                }
                for (int j = pp; j <= m; ++j) {
                    if (a[i][j] == 0) {
                        add(i, j, s);
                        ff = 1;
                        break;
                    }
                }
                if (ff == 1) {
                    break;
                }
            }
        } else {
            cin >> s;
            if (!q.count(s) || q.count(s) && q[s].first == inf) {
                cout << "-1 -1" << endl;
            } else {
                pair <int, int> ans = q[s];
                cout << ans.first << ' ' << ans.second << endl;
                q[s] = make_pair(inf, 0);
                a[ans.first][ans.second] = 0;
            }
        }
    }
    return 0;
}