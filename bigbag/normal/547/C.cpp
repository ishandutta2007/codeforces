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

const int max_n = 200002, inf = 1111111111;
const int max_p = 500005;

int n, q, a[max_n], z[max_p], cnt[max_p], used[max_n];
long long ans;

int get_cnt(int x) {
    int res = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            int d = i;
            res += cnt[d] * z[d];
            d = x / i;
            if (i < d) {
                res += cnt[d] * z[d];
            }
        }
    }
    return res;
}

void add(int x, int f) {
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            int d = i;
            cnt[d] += f;
            d = x / i;
            if (i < d) {
                cnt[d] += f;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 2; i < max_p; ++i) {
        int x = i;
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                x /= j;
                ++z[i];
                if (x % j == 0) {
                    z[i] = 0;
                    x = 0;
                    break;
                }
            }
        }
        if (x == 0) {
            continue;
        }
        if (x > 1) {
            ++z[i];
        }
        if (z[i] % 2 == 1) {
            z[i] = 1;
        } else {
            z[i] = -1;
        }
    }
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        //cout << z[a[i]] << " ";
    }
    int sz = 0;
    while (q--) {
        int x;
        scanf("%d", &x);
        --x;
        int res;
        if (used[x]) {
            add(a[x], -1);
            used[x] = 0;
            --sz;
            ans -= (sz - get_cnt(a[x]));
        } else {
            used[x] = 1;
            ans += sz - get_cnt(a[x]);
            add(a[x], 1);
            ++sz;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}