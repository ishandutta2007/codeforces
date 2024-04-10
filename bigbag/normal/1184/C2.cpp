#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 300333, inf = 1000111222;
const int max_x = 4000444;

struct tree {
    int f[4 * max_x], mx[4 * max_x];

    tree() {
        memset(f, 0, sizeof(f));
        memset(mx, 0, sizeof(mx));
    }

    void push(int v) {
        if (f[v]) {
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            mx[2 * v] += f[v];
            mx[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (tl == l && tr == r) {
            f[v] += x;
            mx[v] += x;
            return;
        }
        push(v);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, x);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, x);
        } else {
            update(2 * v, tl, mid, l, mid, x);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, x);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }
};

int n, r, x[max_n], y[max_n];
vector<pair<int, int>> v;
tree t;

void add(int x, int val) {
    t.update(1, 0, max_x - 1, max(0, x - r), x, val);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        int q = y[i] - x[i];
        int w = y[i] + x[i];
        v.push_back({q, w + max_x / 2});
    }
    r *= 2;
    sort(v.begin(), v.end());
    int ans = 0, pos = 0;
    for (int i = 0; i < v.size(); ++i) {
        while (pos < v.size() && v[pos].first - v[i].first <= r) {
            add(v[pos].second, 1);
            ++pos;
        }
        ans = max(ans, t.mx[1]);
        add(v[i].second, -1);
    }
    printf("%d\n", ans);
    return 0;
}