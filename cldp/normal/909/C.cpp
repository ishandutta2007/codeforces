#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010;
const int INF = 1000000007;
const double PI = acos(-1.0);

char c[MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    memset(f, -1, sizeof(f));
    f[0][0] = 1;
    g[0][0] = 1;
    c[0] = 's';
    for (int i = 1; i <= N; ++i) {
        cin >> c[i];
        if (c[i - 1] == 'f') {
            for (int j = 0; j <= i; ++j) f[i][j + 1] = f[i - 1][j];
        } else {
            bool flag = true;
            for (int j = i; j >= 0; --j) {
                if (flag && f[i - 1][j] == -1) continue;
                flag = false;
                f[i][j] = g[i - 1][j];
            }
        }
        g[i][i] = 0;
        for (int j = i - 1; j >= 0; --j) {
            g[i][j] = g[i][j + 1];
            if (f[i][j] == -1) continue;
            g[i][j] = (g[i][j + 1] + f[i][j]) % INF;
        }
    }

    cout << g[N][0] << endl;
    return 0;
}