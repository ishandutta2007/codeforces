#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui32;
const long long INFLL = 1e18;

using namespace std;

const int MAXN = 100000;
const int MAXK = 3000 + 5;

struct rect {
    int x1, y1, x2, y2, index;
} a[MAXN + 1];

int sum[MAXK + 1][MAXK + 1], boundX[MAXK + 1][MAXK + 1][2], boundY[MAXK + 1][MAXK + 1][2];
bool onEnd[MAXK + 1][MAXK + 1][4];

vector<pair<int, int> > g[MAXK + 1];

int getSumOnRect(int x1, int y1, int x2, int y2) {
    int s = sum[x2][y2];

    if (x1 > 0) {
        s -= sum[x1 - 1][y2];
    }
    if (y1 > 0) {
        s -= sum[x2][y1 - 1];
    }
    if (x1 > 0 && y1 > 0) {
        s += sum[x1 - 1][y1 - 1];
    }

    return s;
}

bool checkRect(int x1, int y1, int x2, int y2) {
    //cout << "!!! " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    --x2;
    --y2;

    if (x2 < 0 || y2 < 0) {
        return false;
    }

    if (y2 > MAXK) {
        return false;
    }
    if (!onEnd[x1][y1][0] || !onEnd[x2][y1][1] || !onEnd[x2][y2][2] || !onEnd[x1][y2][3]) {
        return false;
    }
    if (boundX[y1][x2][0] - (x1 - 1 >= 0 ? boundX[y1][x1 - 1][0] : 0) != x2 - x1 + 1) {
        return false;
    }
    if (boundX[y2][x2][1] - (x1 - 1 >= 0 ? boundX[y2][x1 - 1][1] : 0) != x2 - x1 + 1) {
        return false;
    }
    if (boundY[x1][y2][0] - (y1 - 1 >= 0 ? boundY[x1][y1 - 1][0] : 0) != y2 - y1 + 1) {
        return false;
    }
    if (boundY[x2][y2][1] - (y1 - 1 >= 0 ? boundY[x2][y1 - 1][1] : 0) != y2 - y1 + 1) {
        return false;
    }

    return getSumOnRect(x1, y1, x2, y2) == (x2 - x1 + 1) * (y2 - y1 + 1);
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        a[i].index = i;

        for (int j = a[i].x1; j < a[i].x2; j++) {
            for (int k = a[i].y1; k < a[i].y2; k++) {
                ++sum[j][k];
            }
        }

        for (int j = a[i].x1; j < a[i].x2; j++) {
            ++boundX[a[i].y1][j][0];
            ++boundX[a[i].y2 - 1][j][1];
        }

        for (int j = a[i].y1; j < a[i].y2; j++) {
            ++boundY[a[i].x1][j][0];
            ++boundY[a[i].x2 - 1][j][1];
        }

        onEnd[a[i].x1][a[i].y1][0] = true;
        onEnd[a[i].x2 - 1][a[i].y1][1] = true;
        onEnd[a[i].x2 - 1][a[i].y2 - 1][2] = true;
        onEnd[a[i].x1][a[i].y2 - 1][3] = true;
    }

    for (int i = 0; i <= MAXK; i++) {
        for (int j = 0; j <= MAXK; j++) {
            if (j > 0) {
                boundX[i][j][0] += boundX[i][j - 1][0];
                boundX[i][j][1] += boundX[i][j - 1][1];

                boundY[i][j][0] += boundY[i][j - 1][0];
                boundY[i][j][1] += boundY[i][j - 1][1];
            }

            if (i > 0) {
                sum[i][j] += sum[i - 1][j];
            }
            if (j > 0) {
                sum[i][j] += sum[i][j - 1];
            }
            if (i > 0 && j > 0) {
                sum[i][j] -= sum[i - 1][j - 1];
            }

            //cout << i << " " << j << " " << sum[i][j] << "\n";
        }
    }

    for (int i = 0; i < n; i++) {
        g[a[i].y1].push_back({ a[i].x1, a[i].x2 });
    }

    int X1 = -1, Y1 = -1, X2 = -1, Y2 = -1;

    for (int i = 0; i <= MAXK; i++) {
        sort(g[i].begin(), g[i].end());

        for (int l = 0; l < (int)g[i].size(); l++) {
            for (int r = l; r < (int)g[i].size(); r++) {
                if (r > l && g[i][r - 1].second != g[i][r].first) {
                    break;
                }

                int len = g[i][r].second - g[i][l].first;

                if (checkRect(g[i][l].first, i, g[i][r].second, i + len)) {
                    X1 = g[i][l].first;
                    Y1 = i;
                    X2 = g[i][r].second;
                    Y2 = i + len;
                }
            }
        }
    }

    if (X1 != -1) {
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            if (X1 <= a[i].x1 && Y1 <= a[i].y1 && a[i].x2 <= X2 && a[i].y2 <= Y2) {
                vec.push_back(i);
            }
        }
        printf("YES %d\n", (int)vec.size());
        for (auto x : vec) {
            printf("%d ", x + 1);
        }
    } else {
        printf("NO\n");
    }
    return 0;
}