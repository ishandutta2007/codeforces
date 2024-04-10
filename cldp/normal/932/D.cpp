#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 400010;
const int INF = 1000000007;
const double PI = acos(-1.0);

long long f[MAXN][20]; // log step max
long long g[MAXN][20]; // log step sum
int fa[MAXN][20]; // log step father
int ff[MAXN][20]; // log step useful father
long long val[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int a, cnt = 1;
    long long p, q, last = 0;
    val[0] = INF;
    for (int j = 0; j < 20; ++j) g[0][j] = f[1][j] = f[0][j] = INF;

    for (int i = 0; i < N; ++i) {
        cin >> a >> p >> q;
        p = p ^ last;
        q = q ^ last;
        if (a == 1) {
          // cout << i << ": " << a << " " << p << " " << q << endl;
            ++cnt;
            fa[cnt][0] = p;
            val[cnt] = q;
            f[cnt][0] = val[p];
            for (int j = 1; j < 20; ++j) {
                fa[cnt][j] = fa[fa[cnt][j - 1]][j - 1];
                f[cnt][j] = max(f[cnt][j - 1], f[fa[cnt][j - 1]][j - 1]);
            }


         //   cout << "cnt: " << cnt << endl;
         //   for (int j = 0; j < 5; ++j) cout << fa[cnt][j] << " "; cout << endl;
         //   for (int j = 0; j < 5; ++j) cout << f[cnt][j] << " "; cout << endl;

            int temp = cnt;
            for (int j = 19; j >= 0; --j) {
                if (f[temp][j] >= val[cnt]) continue;
                temp = fa[temp][j];
            }
            temp = fa[temp][0];

          //  cout << "temp: " << temp << endl;

            ff[cnt][0] = temp;
            g[cnt][0] = q;
            for (int j = 1; j < 20; ++j) {
                ff[cnt][j] = ff[ff[cnt][j - 1]][j - 1];
                g[cnt][j] = g[cnt][j - 1] + g[ff[cnt][j - 1]][j - 1];
            }

        //    for (int j = 0; j < 5; ++j) cout << g[cnt][j] << " "; cout << endl;
         //   for (int j = 0; j < 5; ++j) cout << ff[cnt][j] << " "; cout << endl;

        } else {
         //  cout << i << ": " << a << " " << p << " " << q << endl;
            long long ans = 0;
            for (int j = 19; j >= 0; --j) {
                if (ff[p][j] == 0) continue;
                if (g[p][j] <= q) {
                    ans += (1 << j);
                    q -= g[p][j];
                    p = ff[p][j];
                }
            }
            if (val[p] <= q) ++ans;
            cout << ans << endl;
            last = ans;
        }
    }
    return 0;
}