/**
 *  created: 17/03/2021, 16:57:56
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_x = 10001111;

int t, n, k, a[max_n];
int mnd[max_x];

void calc_mnd() {
    mnd[1] = 1;
    for (int i = 2; i < max_x; ++i) {
        if (!mnd[i]) {
            mnd[i] = i;
            for (int j = 2 * i; j < max_x; j += i) {
                if (!mnd[j]) {
                    mnd[j] = i;
                }
            }
        }
    }
}

int upd(int x) {
    int res = 1;
    while (x > 1) {
        int d = mnd[x], cnt = 0;
        while (x % d == 0) {
            ++cnt;
            x /= d;
        }
        if (cnt % 2) {
            res *= d;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    calc_mnd();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            a[i] = upd(a[i]);
        }
        set<int> q;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (q.count(a[i])) {
                q.clear();
                ++ans;
            }
            q.insert(a[i]);
        }
        ++ans;
        printf("%d\n", ans);
    }
    return 0;
}