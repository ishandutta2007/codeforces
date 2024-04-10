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

const int max_n = 33, inf = 1111111111;

int n, a[max_n], b[max_n], c[max_n], pw[15], f[max_n];
int ans = -inf, mask1 = -1, mask2 = -1;
map<pair<int, int>, pair<int, int> > m;

void get_f(int mask, int n) {
    for (int i = 0; i < n; ++i) {
        f[i] = mask % 3;
        mask /= 3;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    if (n == 1) {
        int i = 0;
        if (a[i] == 0 && b[i] == 0) {
            cout << "LM" << endl;
        } else if (a[i] == 0 && c[i] == 0) {
            cout << "LW" << endl;
        } else if (b[i] == 0 && c[i] == 0) {
            cout << "MW" << endl;
        } else {
            cout << "Impossible" << endl;
        }
        return 0;
    }
    pw[0] = 1;
    for (int i = 1; i < 15; ++i) {
        pw[i] = pw[i - 1] * 3;
    }
    int x = (n + 1) / 2;
    int y = n - x;
    for (int mask = 0; mask < pw[y]; ++mask) {
        get_f(mask, y);
        int q = 0, w = 0, e = 0;
        for (int i = x; i < n; ++i) {
            int qq, ww, ee;
            if (f[i - x] == 0) {
                qq = a[i];
                ww = b[i];
                ee = 0;
            } else if (f[i - x] == 1) {
                qq = a[i];
                ww = 0;
                ee = c[i];
            } else {
                qq = 0;
                ww = b[i];
                ee = c[i];
            }
            q += qq;
            w += ww;
            e += ee;
        }
        int dw = w - q;
        int de = e - q;
        if (!m.count(make_pair(dw, de))) {
            m[make_pair(dw, de)] = make_pair(q, mask);
        } else {
            int res = m[make_pair(dw, de)].first;
            if (res < q) {
                m[make_pair(dw, de)] = make_pair(q, mask);
            }
        }
    }

    for (int mask = 0; mask < pw[x]; ++mask) {
        get_f(mask, x);
        int q = 0, w = 0, e = 0;
        for (int i = 0; i < x; ++i) {
            int qq, ww, ee;
            if (f[i] == 0) {
                qq = a[i];
                ww = b[i];
                ee = 0;
            } else if (f[i] == 1) {
                qq = a[i];
                ww = 0;
                ee = c[i];
            } else {
                qq = 0;
                ww = b[i];
                ee = c[i];
            }
            q += qq;
            w += ww;
            e += ee;
        }
        int dw = q - w;
        int de = q - e;
        //cout << mask << " : " << q << " " << w << " " << e << endl;
        if (m.count(make_pair(dw, de))) {
            pair<int, int> p = m[make_pair(dw, de)];
            q += p.first;
            if (ans < q) {
                ans = q;
                mask1 = mask;
                mask2 = p.second;
            }
        }
    }
    if (ans == -inf) {
        cout << "Impossible" << endl;
        return 0;
    }
    //cout << ans << endl;
    get_f(mask1, x);
    for (int i = 0; i < x; ++i) {
        if (f[i] == 0) {
            cout << "LM" << endl;
        } else if (f[i] == 1) {
            cout << "LW" << endl;
        } else {
            cout << "MW" << endl;
        }
    }
    get_f(mask2, y);
    for (int i = 0; i < y; ++i) {
        if (f[i] == 0) {
            cout << "LM" << endl;
        } else if (f[i] == 1) {
            cout << "LW" << endl;
        } else {
            cout << "MW" << endl;
        }
    }
    return 0;
}