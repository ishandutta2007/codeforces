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

const int max_n = 202222, inf = 1111111111;

struct tree {
    int f[4 * max_n], mx[4 * max_n];
    long long sum[4 * max_n];
    tree() {
        memset(sum, 0, sizeof(sum));
        memset(f, 0, sizeof(f));
        memset(mx, 0, sizeof(mx));
    }
    void push(int v, int l, int r) {
        if (l == r) {
            return;
        }
        if (f[v] != 0) {
            int mid = (l + r) / 2;
            mx[2 * v] = f[v];
            sum[2 * v] = 1LL * f[v] * (mid - l + 1);
            mx[2 * v + 1] = f[v];
            sum[2 * v + 1] = 1LL * f[v] * (r - mid);
            f[2 * v] = f[v];
            f[2 * v + 1] = f[v];
            f[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int value) {
        push(v, tl, tr);
        if (tl == l && tr == r) {
            if (mx[v] < value) {
                f[v] = value;
                mx[v] = value;
                sum[v] = 1LL * (r - l + 1) * value;
                return;
            }
            if (l == r) {
                return;
            }
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            if (mx[2 * v + 1] < value) {
                update(2 * v, tl, mid, l, mid, value);
            }
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }
    long long get_sum(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
    void write(int v, int l, int r) {
        if (l == r) {
            cout << l << " " << r << " - " << sum[v] << "   " << f[v] << endl;
            return;
        }
        int mid = (l + r) / 2;
        write(2 * v, l, mid);
        write(2 * v + 1, mid + 1, r);
        cout << l << " " << r << " - " << sum[v] << "   " << f[v] << endl;
    }
};

int n, a[max_n], cnt[max_n], last[max_n];
vector<int> g[max_n];
tree t;

void proc() {
    int res = 0;
    int cnt[max_n];
    memset(cnt, 0, sizeof(cnt));
    for (int i = n - 1; i >= 0; --i) {
        t.update(1, 0, n - 1, i, i, res);
        for (int j = 0; j < g[a[i]].size(); ++j) {
            ++cnt[g[a[i]][j]];
            if (cnt[g[a[i]][j]] >= 2) {
                res = max(res, g[a[i]][j]);
            }
        }
    }
    if (0) {
        for (int i = 0; i < n; ++i) {
            cout << t.get_sum(1, 0, n - 1, i, i) << " ";
        }
        cout << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 1; i < max_n; ++i) {
        for (int j = i; j < max_n; j += i) {
            g[j].push_back(i);
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (int j = 0; j < g[a[i]].size(); ++j) {
            last[g[a[i]][j]] = i;
        }
    }
    proc();
    long long ans = t.get_sum(1, 0, n - 1, 0, n - 1);
    for (int i = 0; i + 1 < n; ++i) {
        int L = i + 1, R = n - 1;
        for (int j = 0; j < g[a[i]].size(); ++j) {
            ++cnt[g[a[i]][j]];
            int l = L, r = R;
            if (cnt[g[a[i]][j]] == 1) {
                r = last[g[a[i]][j]] - 1;
            }
            if (l <= r) {
                //cout << l << " " << r << " : " << g[a[i]][j] << endl;
                t.update(1, 0, n - 1, l, r, g[a[i]][j]);
            }
        }
        /*cout << i << " : ";
        for (int j = i + 1; j < n; ++j) {
            cout << t.get_sum(1, 0, n - 1, j, j) << " ";
        }
        cout << endl;*/
        ans += t.get_sum(1, 0, n - 1, i + 1, n - 1);
    }
    printf("%I64d\n", ans);
    return 0;
}