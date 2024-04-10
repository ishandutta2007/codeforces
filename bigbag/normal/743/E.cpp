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

const int max_n = 1111, max_p = 9, inf = 1011111111;

int n, a[max_n], nxtx[max_n][max_p], nxt[max_n][max_n];

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

bool check(int len, int mask) {
    int p[max_p];
    for (int i = 0; i < 8; ++i) {
        p[i] = i + 1;
    }
    //int F = 0;
    do {
        //++F;
        int pos = 0, f = 1;
        for (int i = 0; i < 8; ++i) {
            //if (F == 1) cout << i << " " << pos << endl;
            pos = nxtx[pos][p[i]];
            //if (F == 1) cout << i << " " << pos << endl;
            if (pos == n) {
                f = 0;
                break;
            }
            pos = nxt[pos][len + get_bit(mask, p[i] - 1)];
            if (pos == n) {
                f = 0;
                break;
            }
            ++pos;
        }
        if (f) {
            /*for (int i = 0; i < 8; ++i) {
                cout << p[i];
            }
            cout << endl;
            int pos = 0, f = 1;
            for (int i = 0; i < 8; ++i) {

                pos = nxtx[pos][p[i]];
                cout << i << " " << pos << endl;
                if (pos == n) {
                    f = 0;
                    break;
                }
                pos = nxt[i][len];
                if (pos == n) {
                    f = 0;
                    break;
                }
                ++pos;
            }*/
            return true;
        }
    } while (next_permutation(p, p + 8));
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= 8; ++i) {
        nxtx[n][i] = n;
    }
    for (int i = 0; i < max_n; ++i) {
        nxt[n][i] = n;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j <= 8; ++j) {
            nxtx[i][j] = nxtx[i + 1][j];
        }
        nxt[i][1] = i;
        int pos = nxtx[i][a[i]];
        for (int j = 2; j < max_n; ++j) {
            nxt[i][j] = nxt[pos][j - 1];
        }
        nxtx[i][a[i]] = i;
    }
    //cout << check(2) << endl;
    //return 0;
    int l = 0, r = 133;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid, 0)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (l == 0) {
        set<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.insert(a[i]);
        }
        cout << ans.size() << endl;
        return 0;
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << 8); ++mask) {
        if (check(l, mask)) {
            int x = 0;
            for (int i = 0; i < 8; ++i) {
                x += get_bit(mask, i);
            }
            ans = max(ans, x);
        }
    }
    cout << ans + 8 * l << endl;
    return 0;
}