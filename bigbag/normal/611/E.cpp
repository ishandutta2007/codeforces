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

const int max_n = 222222, inf = 1111111111;

int ans, n, a[3], x[max_n], f[max_n];
vector<int> v;

bool check(int cnt, int ca, int cb, int cc, int all) {
    int l1 = 0, r1 = cc - cnt - 1, l2 = cc, r2 = v.size();
    --r2;
    if (r2 - cc + 1 <= cnt + all) {
        int qqq = cnt + all - (r2 - cc + 1);
        r1 -= qqq;
        if (r1 < cb) {
            r1 -= all;
            if (r1 < ca) {
                r1 -= all;
                if (r1 < 0) {
                    return true;
                }
                return false;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &a[0], &a[1], &a[2]);
    sort(a, a + 3);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        if (x[i] > a[0] + a[1] + a[2]) {
            printf("-1\n");
            return 0;
        }
    }
    sort(x, x + n);
    for (int i = 0; i < n; ++i) {
        if (x[i] > a[1] + a[2]) {
            ++ans;
            f[i] = 1;
        }
    }
    int ca = 0, cb = 0, cc = 0;
    for (int i = 0; i < n; ++i) {
        if (f[i]) {
            continue;
        }
        if (x[i] > a[0] + a[2]) {
            ++ans;
            f[i] = 1;
            ++ca;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f[i]) {
            continue;
        }
        if (x[i] > a[0] + a[1] && x[i] > a[2]) {
            ++ans;
            f[i] = 1;
            ++cb;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f[i]) {
            continue;
        }
        if (x[i] > a[2]) {
            ++ans;
            f[i] = 1;
            ++cc;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (f[i]) {
            continue;
        }
        if (ca && a[0] >= x[i]) {
            --ca;
            f[i] = 1;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (f[i]) {
            continue;
        }
        if (cb && a[1] >= x[i]) {
            --cb;
            f[i] = 1;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (f[i]) {
            continue;
        }
        if (cc && a[2] >= x[i]) {
            --cc;
            f[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f[i] == 0) {
            v.push_back(x[i]);
        }
    }
    if (v.size()) {
        ca = v.size();
        cb = v.size();
        cc = v.size();
        /*for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << "  ans = " << ans << endl;*/
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] > a[0]) {
                ca = i;
                break;
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] > a[1]) {
                cb = i;
                break;
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] > a[0] + a[1]) {
                cc = i;
                break;
            }
        }
        int res = v.size();
        for (int i = 0; i <= cc; ++i) {
            int l = -1, r = v.size();
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (check(i, ca, cb, cc, mid)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            res = min(res, i + r);
        }
        ans += res;
    }
    printf("%d\n", ans);
    return 0;
}