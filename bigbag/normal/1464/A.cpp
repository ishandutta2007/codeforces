/**
 *  created: 20/12/2020, 17:12:43
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, k, x[max_n][2], f[2][max_n], used[max_n];
int ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            f[0][i] = f[1][i] = -1;
            used[i] = 0;
        }
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &x[i][0], &x[i][1]);
            --x[i][0];
            --x[i][1];
            f[0][x[i][0]] = i;
            f[1][x[i][1]] = i;
        }
        ans = 0;
        for (int i = 0; i < k; ++i) {
            if (x[i][0] == x[i][1]) {
                continue;
            }
            ++ans;
            if (!used[i]) {
                bool cycle = 0;
                if (f[0][x[i][1]] != -1 && f[1][x[i][0]] != -1) {
                    cycle = 1;
                    int v = i, tp = 0;
                    do {
                        //cout << "$" << v << endl;
                        used[v] = 1;
                        if (f[tp][x[v][tp ^ 1]] == -1) {
                            cycle = 0;
                            break;
                        }
                        v = f[tp][x[v][tp ^ 1]];
                        //tp ^= 1;
                    } while (v != i);
                    //cout << "#" << v << " " << 1 << endl;
                    ans += cycle;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}