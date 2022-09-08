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

const int max_n = 101111, max_lev = 20, inf = 1111111111;

int n, s, cnt, a[max_n], dp[max_n];
int mins[max_lev][max_n], maxs[max_lev][max_n], num[max_n];

void get_all_mins() {
    for (int i = 0; i < n; ++i) {
        mins[0][i] = a[i];
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            mins[i][j] = min(mins[i - 1][j], mins[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

void get_all_maxs() {
    for (int i = 0; i < n; ++i) {
        maxs[0][i] = a[i];
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            maxs[i][j] = max(maxs[i - 1][j], maxs[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int get_min(int l, int r) {
    if (l > r) {
        return inf;
    }
    int lev = num[r - l + 1];
    return min(mins[lev][l], mins[lev][r - (1 << lev) + 1]);
}

int get_max(int l, int r) {
    if (l > r) {
        return -inf;
    }
    int lev = num[r - l + 1];
    return max(maxs[lev][l], maxs[lev][r - (1 << lev) + 1]);
}

struct tree {
    int mins[4 * max_n];
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            mins[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        mins[v] = min(mins[2 * v], mins[2 * v + 1]);
    }
    int get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mins[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &s, &cnt);
    if (n < cnt) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    get_all_mins();
    get_all_maxs();
    if (get_max(0, cnt - 1) - get_min(0, cnt - 1) > s) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i + 1 < cnt; ++i) {
        dp[i] = inf;
        t.update(1, 0, n - 1, i, dp[i]);
    }
    dp[cnt - 1] = 1;
    t.update(1, 0, n - 1, cnt - 1, dp[cnt - 1]);
    for (int i = cnt; i < n; ++i) {
        int l = -1, r = i;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (get_max(mid, i) - get_min(mid, i) <= s) {
                r = mid;
            } else {
                l = mid;
            }
        }
        dp[i] = inf;
        //cout << i << " - " << r << " " << i - cnt << endl;
        if (r == 0) {
            dp[i] = 1;
        } else if (r <= i - cnt + 1) {
            dp[i] = t.get_min(1, 0, n - 1, r - 1, i - cnt) + 1;
        }
        if (dp[i] > inf) dp[i] = inf;
        t.update(1, 0, n - 1, i, dp[i]);
    }
    for (int i = 0; i < n; ++i) {
        //cout << i << " " << dp[i] << endl;
    }
    if (dp[n - 1] == inf) dp[n - 1] = -1;
    printf("%d\n", dp[n - 1]);
    return 0;
}