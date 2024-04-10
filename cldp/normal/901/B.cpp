#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 210;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    memset(x, 0, sizeof(x));
    x[0][0] = 1;
    x[1][1] = 1;
    for (int i = 2; i <= N; ++i) {
        int y[MAXN];
        memset(y, 0, sizeof(y));
        y[0] = x[i - 2][0];
        for (int j = 1; j <= i; ++j) y[j] = x[i - 1][j - 1] + x[i - 2][j];
        bool flag = true;
        for (int j = 0; j <= i; ++j) flag &= (y[j] >= -1 && y[j] <= 1);
        if (flag) {
            for (int j = 0; j <= i; ++j) x[i][j] = y[j];
            continue;
        }

        memset(y, 0, sizeof(y));
        y[0] = -x[i - 2][0];
        for (int j = 1; j <= i; ++j) y[j] = x[i - 1][j - 1] - x[i - 2][j];
        flag = true;
        for (int j = 0; j <= i; ++j) flag &= (y[j] >= -1 && y[j] <= 1);
        if (flag) {
            for (int j = 0; j <= i; ++j) x[i][j] = y[j];
            continue;
        }
    }

    cout << N << endl;
    for (int i = 0; i <= N; ++i) cout << x[N][i] << " ";
    cout << endl;
    cout << N - 1 << endl;
    for (int i = 0; i <= N - 1; ++i) cout << x[N - 1][i] << " ";
    cout << endl;


    return 0;
}