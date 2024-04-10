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

const int max_n = 111111, inf = 1111111111;
const long double pi = 2 * acos((long double) (0));

struct tree {
    long long maxs[4 * max_n];
    void update(int v, int l, int r, int x, long long value) {
        if (l == r) {
            maxs[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        maxs[v] = max(maxs[2 * v], maxs[2 * v + 1]);
    }
    long long get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return maxs[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

tree t;

int n, b[max_n];
long long a[max_n], dp[max_n];

void proc() {
    pair<long long, int> p[max_n];
    for (int i = 0; i < n; ++i) {
        p[i] = make_pair(a[i], i);
    }
    sort(p, p + n);
    int cnt = 1;
    for (int i = 0; i < n; ) {
        int poz = i;
        while (i < n && p[poz].first == p[i].first) {
            b[p[i].second] = cnt;
            ++i;
        }
        ++cnt;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int h, r;
        scanf("%d%d", &r, &h);
        a[i] = 1LL * r * r * h;
    }
    proc();
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = t.get_max(1, 0, n, 0, b[i] - 1) + a[i];
        t.update(1, 0, n, b[i], dp[i]);
        ans = max(ans, dp[i]);
        //cout << a[i] << " " << b[i] << " : " << dp[i] << endl;
    }
    printf("%.10f\n", (double) (pi * ans));
    return 0;
}