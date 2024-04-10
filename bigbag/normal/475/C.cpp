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

const int max_n = 1011, inf = 1111111111;

int n, m, cntall, a[max_n][max_n];
string s[max_n];

int sum(int lx, int rx, int ly, int ry) {
    int q = a[rx][ry], w = 0, e = 0, r = 0;
    if (ly > 0) {
        w = a[rx][ly - 1];
    }
    if (lx > 0) {
        e = a[lx - 1][ry];
    }
    if (ly > 0 && lx > 0) {
        r = a[lx - 1][ly - 1];
    }
    //printf("sum %d %d %d %d = %d\n", q, w, e, r, q - w - e + r);
    return q - w - e + r;
}

int Findx(int x) {
    for (int i = 0; i < m; ++i) {
        if (s[x][i] == 'X') {
            return i;
        }
    }
    return -1;
}

int Findy(int y) {
    for (int i = 0; i < n; ++i) {
        if (s[i][y] == 'X') {
            return i;
        }
    }
    return -1;
}

bool check1(int lx, int ly, int rx, int ry) {
    int s = (rx - lx + 1) * (ry - ly + 1);
    while (true) {
        //cout << lx << " " << ly << "   " << rx << " " << ry << endl;
        int cnt = sum(lx, rx, ly, ry);
        if (cnt != s) {
            //cout << "error1\n";
            return false;
        }
        int f1 = 0, f2 = 0;
        if (sum(rx + 1, n - 1, ly, ly) > 0) {
            f1 = 1;
        }
        if (sum(lx, lx, ry + 1, m - 1) > 0) {
            f2 = 1;
        }
        if (f1 == 1 && f2 == 1) {
            //cout << "error2\n";
            return false;
        }
        if (f1 == 0 && f2 == 0) {
            if (sum(rx + 1, n - 1, ly, m - 1) + sum(lx, n - 1, ry + 1, m - 1) > 0) {
                //cout << "error3\n";
                return false;
            }
            return true;
        }
        if (f1 == 1) {
            ++lx;
            ++rx;
        } else {
            ++ly;
            ++ry;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        s[i] += '.';
        for (int j = 0; j < s[i].length(); ++j) {
            if (s[i][j] == 'X') {
                ++cntall;
            }
        }
    }
    ++m;
    for (int i = 0; i < m; ++i) {
        s[n] += '.';
    }
    ++n;
    if (s[0][0] == 'X') {
        a[0][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        a[i][0] = a[i - 1][0];
        if (s[i][0] == 'X') {
            ++a[i][0];
        }
    }
    for (int i = 1; i < m; ++i) {
        a[0][i] = a[0][i - 1];
        if (s[0][i] == 'X') {
            ++a[0][i];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            if (s[i][j] == 'X') {
                ++a[i][j];
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/
    int mnx, mny, mxx, mxy;
    for (int i = 0; i < n; ++i) {
        int f = 0;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'X') {
                mnx = i;
                f = 1;
                break;
            }
        }
        if (f == 1) break;
    }
    for (int i = 0; i < m; ++i) {
        int f = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j][i] == 'X') {
                mny = i;
                f = 1;
                break;
            }
        }
        if (f == 1) break;
    }
    if (s[mnx][mny] == '.') {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        if (s[mnx][i] == 'X') {
            mxy = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i][mny] == 'X') {
            mxx = i;
        }
    }
    int xxx = sum(mnx, mxx, mny, mxy), ans = inf;
    if (xxx == cntall) {
        if (xxx == (mxx - mnx + 1) * (mxy - mny + 1)) {
            cout << min(mxx - mnx + 1, mxy - mny + 1) << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    //cout << "!" << mnx << " " << mxx << endl;
    //cout << "!" << mny << " " << mxy << endl;
    int poz = Findx(mxx + 1);
    if (poz != -1) {
        if (check1(mnx, mny, mxx, mxy - poz + mny)) {
            ans = min(ans, (mxx - mnx + 1) * (mxy - poz + 1));
        }
    }
    //cout << endl << endl;
    poz = Findy(mxy + 1);
    if (poz != -1) {
        //cout << poz << endl;
        if (check1(mnx, mny, mxx - poz + mnx, mxy)) {
            ans = min(ans, (mxy - mny + 1) * (mxx - poz + 1));
        }
    }
    if (ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}