#include <map>
#include <set>
#include <stack>
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

const int max_n = 1011, mod = 1000000007, inf = 1011111111;
const long double lg = log2(3);

bool cmp(int a2, int a3, int b2, int b3) {
    if ((a2 <= b2) == (a3 <= b3)) {
        return a2 <= b2 && a3 <= b3;
    }
    int o2 = min(a2, b2), o3 = min(a3, b3);
    a2 -= o2;
    b2 -= o2;
    a3 -= o3;
    b3 -= o3;
    long double q = a2 + a3 * lg;
    long double w = b2 + b3 * lg;
    return q <= w;
}

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int n, ans2, ans3;
int cntx[max_n][max_n][4];
int cnty[max_n][max_n][4];
int nxty[max_n][max_n], prx[max_n][max_n];
int nxtx[max_n][max_n], pry[max_n][max_n];
char s[max_n][max_n];

int getx(int i, int l, int r, int tp) {
    if (l == 0) {
        return cntx[i][r][tp];
    }
    return cntx[i][r][tp] - cntx[i][l - 1][tp];
}

int gety(int i, int l, int r, int tp) {
    if (l == 0) {
        return cnty[r][i][tp];
    }
    return cnty[r][i][tp] - cnty[l - 1][i][tp];
}

void solve1() {
    for (int i = 0; i < n; ++i) {
        nxtx[i][n] = n;
        for (int j = n - 1; j >= 0; --j) {
            nxtx[i][j] = nxtx[i][j + 1];
            if (s[i][j] == 0) {
                nxtx[i][j] = j;
            }
        }
        prx[i][0] = -1;
        if (s[i][0] == 0) {
            prx[i][0] = 0;
        }
        for (int j = 1; j < n; ++j) {
            prx[i][j] = prx[i][j - 1];
            if (s[i][j] == 0) {
                prx[i][j] = j;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        nxty[n][i] = n;
        for (int j = n - 1; j >= 0; --j) {
            nxty[j][i] = nxty[j + 1][i];
            if (s[j][i] == 0) {
                nxty[j][i] = j;
            }
        }
        pry[0][i] = -1;
        if (s[0][i] == 0) {
            pry[0][i] = 0;
        }
        for (int j = 1; j < n; ++j) {
            pry[j][i] = pry[j - 1][i];
            if (s[j][i] == 0) {
                pry[j][i] = j;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cntx[i][0][s[i][0]] = 1;
        for (int j = 1; j < n; ++j) {
            cntx[i][j][0] = cntx[i][j - 1][0];
            cntx[i][j][1] = cntx[i][j - 1][1];
            cntx[i][j][2] = cntx[i][j - 1][2];
            cntx[i][j][3] = cntx[i][j - 1][3];
            ++cntx[i][j][s[i][j]];
        }
    }
    for (int i = 0; i < n; ++i) {
        cnty[0][i][s[0][i]] = 1;
        for (int j = 1; j < n; ++j) {
            cnty[j][i][0] = cnty[j - 1][i][0];
            cnty[j][i][1] = cnty[j - 1][i][1];
            cnty[j][i][2] = cnty[j - 1][i][2];
            cnty[j][i][3] = cnty[j - 1][i][3];
            ++cnty[j][i][s[j][i]];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int d = min(min(nxtx[i][j] - j, j - prx[i][j]), min(nxty[i][j] - i, i - pry[i][j]));
            if (d == 0) {
                continue;
            }
            int c2 = getx(i, j - d + 1, j + d - 1, 2);
            int c3 = getx(i, j - d + 1, j + d - 1, 3);
            c2 += gety(j, i - d + 1, i + d - 1, 2);
            c3 += gety(j, i - d + 1, i + d - 1, 3);
            c2 -= (s[i][j] == 2);
            c3 -= (s[i][j] == 3);
            //cout << i << " " << j << " d = " << d << "  : " << c2 << " " << c3 << endl;
            if (cmp(ans2, ans3, c2, c3)) {
                ans2 = c2;
                ans3 = c3;
                //cout << i << " " << j << " d = " << d << "  : " << c2 << " " << c3 << endl;
            }
        }
    }
}

int lx[2 * max_n], rx[2 * max_n];
int ly[2 * max_n], ry[2 * max_n];
int sumx[2 * max_n][max_n][4];
int sumy[2 * max_n][max_n][4];
int cnt[4];

int g1(int num, int l, int r, int tp) {
    if (l == 0) {
        return sumx[num][r][tp];
    }
    return sumx[num][r][tp] - sumx[num][l - 1][tp];
}

int g2(int num, int l, int r, int tp) {
    if (l == 0) {
        return sumy[num][r][tp];
    }
    return sumy[num][r][tp] - sumy[num][l - 1][tp];
}

void get(int x, int y, int d) {
    int n1 = x - y + n;
    int n2 = x + y;
    for (int i = 0; i < 4; ++i) {
        cnt[i] = g1(n1, y - d + 1, y + d - 1, i) + g2(n2, y - d + 1, y + d - 1, i);
        cnt[i] -= (s[x][y] == i);
    }
}

void solve2() {
    for (int i = 0; i < 2 * max_n; ++i) {
        lx[i] = inf;
        rx[i] = -inf;
        ly[i] = inf;
        ry[i] = -inf;
    }
    for (int i = 1; i <= 2 * n - 1; ++i) {
        for (int x = 0; x < n; ++x) {
            int y = x + n - i;
            if (0 <= y && y < n) {
                if (y) {
                    sumx[i][y][0] = sumx[i][y - 1][0];
                    sumx[i][y][1] = sumx[i][y - 1][1];
                    sumx[i][y][2] = sumx[i][y - 1][2];
                    sumx[i][y][3] = sumx[i][y - 1][3];
                }
                ++sumx[i][y][s[x][y]];
                lx[i] = min(lx[i], y);
                rx[i] = max(rx[i], y);
            }
        }
    }
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int x = n - 1; x >= 0; --x) {
            int y = i - x;
            if (0 <= y && y < n) {
                if (y) {
                    sumy[i][y][0] = sumy[i][y - 1][0];
                    sumy[i][y][1] = sumy[i][y - 1][1];
                    sumy[i][y][2] = sumy[i][y - 1][2];
                    sumy[i][y][3] = sumy[i][y - 1][3];
                }
                ++sumy[i][y][s[x][y]];
                ly[i] = min(ly[i], y);
                ry[i] = max(ry[i], y);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int numx = i - j + n;
            int numy = i + j;
            int d = min(min(j - lx[numx] + 1, rx[numx] - j + 1), min(j - ly[numy] + 1, ry[numy] - j + 1)), nd = 0;
            for (int dd = 1024; dd; dd /= 2) {
                if (nd + dd <= d) {
                    get(i, j, nd + dd);
                    if (cnt[0] == 0) {
                        nd += dd;
                    }
                }
            }
            get(i, j, nd);
            if (cmp(ans2, ans3, cnt[2], cnt[3])) {
                ans2 = cnt[2];
                ans3 = cnt[3];
                //cout << i << " " << j << " d = " << d << "  : " << c2 << " " << c3 << endl;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < n; ++j) {
            s[i][j] -= '0';
            sum += s[i][j];
        }
    }
    solve1();
    solve2();
    if (sum == 0) {
        printf("%d\n", 0);
    } else {
        printf("%d\n", (1LL * power(2, ans2, mod) * power(3, ans3, mod)) % mod);
    }
    return 0;
}