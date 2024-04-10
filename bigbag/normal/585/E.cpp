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

const int max_n = 511111, max_x = 11111111, inf = 1000000007;

int n, a[max_n], f[max_x], p[max_x], cnt[max_x], pw[max_n];
vector<int> v[max_n];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

void ok(int &x) {
    x %= inf;
    if (x < 0) {
        x += inf;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 2; i < max_x; ++i) {
        f[i] = -1 - f[i];
        for (int k = 2; i * k < max_x; ++k) {
            f[i * k] += f[i];
            if (p[i] == 0 && p[i * k] == 0) {
                p[i * k] = i;
            }
        }
        if (p[i] == 0) {
            p[i] = i;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int x = a[i];
        while (x > 1) {
            if (v[i].size() == 0 || v[i].back() != p[x]) {
                v[i].push_back(p[x]);
            }
            x /= p[x];
        }
        for (int j = 0; j < (1 << v[i].size()); ++j) {
            x = 1;
            for (int k = 0; k < v[i].size(); ++k) {
                if (get_bit(j, k)) {
                    x *= v[i][k];
                }
            }
            ++cnt[x];
        }
    }
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (pw[i - 1] * 2) % inf;
    }
    int ans = 0, all = 0;
    for (int i = 2; i < max_x; ++i) {
        all -= (f[i] * (pw[cnt[i]] - 1));
        ok(all);
    }
    for (int i = 0; i < n; ++i) {
        int pl = all;
        for (int j = 0; j < (1 << v[i].size()); ++j) {
            int x = 1;
            for (int k = 0; k < v[i].size(); ++k) {
                if (get_bit(j, k)) {
                    x *= v[i][k];
                }
            }
            pl += (f[x] * (pw[cnt[x]] - 1));
            ok(pl);
        }
        ok(pl);
        ans += pl;
        ok(ans);
    }
    printf("%d\n", ans);
    return 0;
}