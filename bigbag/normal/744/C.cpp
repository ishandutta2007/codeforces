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

const int max_n = 16, max_x = 133, inf = 1011111111;

int n, a[max_n], b[max_n], dp[1 << max_n][max_x];
char tp[max_n];
int suma, sumb;
int cnta[1 << max_n], cntb[1 << max_n];
int alla[1 << max_n], allb[1 << max_n];

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

void write(int mask, const string s = "") {
    for (int i = 0; i < n; ++i) {
        cout << get_bit(mask, i);
    }
    cout << s;
}

bool check(int x) {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int ca = cnta[mask];
        int cb = cntb[mask];
        for (int q = 0; q < max_x; ++q) {
            int w = dp[mask][q];
            if (w == -1) {
                continue;
            }
            //write(mask, " ");
            //cout << q << " " << w << endl;
            for (int nxt = 0; nxt < n; ++nxt) {
                if (!get_bit(mask, nxt)) {
                    int nmask = mask | (1 << nxt);
                    int cca = min(ca, a[nxt]);
                    int ccb = min(cb, b[nxt]);
                    if (x >= alla[nmask] - q - cca && x >= allb[nmask] - w - ccb) {
                        dp[nmask][q + cca] = max(dp[nmask][q + cca], w + ccb);
                    }
                }
            }
        }
    }
    for (int i = 0; i < max_x; ++i) {
        if (dp[(1 << n) - 1][i] != -1) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tp[i] >> a[i] >> b[i];
        suma += a[i];
        sumb += b[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        cnta[i] = 0;
        cntb[i] = 0;
        alla[i] = 0;
        allb[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (get_bit(i, j)) {
                if (tp[j] == 'R') {
                    ++cnta[i];
                } else {
                    ++cntb[i];
                }
                alla[i] += a[j];
                allb[i] += b[j];
            }
        }
    }
    //cout << check(1) << endl;
    //return 0;
    int r = max(suma, sumb);
    int l = max(-1, r - 200);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r + n << endl;
    return 0;
}