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

const int max_n = 101111, inf = 1111111112;

struct tree {
    pair<int, int> mins[4 * max_n];
    void build(int v, int l, int r) {
        if (l == r) {
            mins[v] = make_pair(0, l);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mins[v] = min(mins[2 * v], mins[2 * v + 1]);
    }
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            mins[v] = make_pair(value, l);
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
    pair<int, int> get_min(int v, int tl, int tr, int l, int r) {
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

struct state {
    int a, b, c, d, id;
    void read() {
        scanf("%d%d%d%d", &a, &b, &c, &d);
    }
    bool operator < (const state &s) const {
        return (a < s.a) || (a == s.a && id < s.id);
    }
};

int n, p[max_n], dp[max_n];
tree t;
state a[max_n];
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        a[i].read();
        a[i].id = i + 1;
    }
    sort(a, a + n);
    t.build(1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        t.update(1, 0, n - 1, i, a[i].b);
    }
    a[n].c = 0;
    a[n].d = 0;
    memset(dp, -1, sizeof(dp));
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int x = a[v].c;
        int y = a[v].d;
        int l = -1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid].a <= x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (l == -1) {
            continue;
        }
        while (true) {
            pair<int, int> pp = t.get_min(1, 0, n - 1, 0, l);
            if (pp.first == inf || pp.first > y) {
                break;
            }
            int to = pp.second;
            if (dp[to] == -1) {
                dp[to] = dp[v] + 1;
                p[to] = v;
                q.push(to);
                t.update(1, 0, n - 1, to, inf);
            }
        }
    }
    int poz;
    for (int i = 0; i < n; ++i) {
        if (a[i].id == n) {
            poz = i;
            break;
        }
    }
    if (dp[poz] == -1) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", dp[poz] + 1);
    while (poz != n) {
        ans.push_back(poz);
        poz = p[poz];
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", a[ans[i]].id);
    }
    printf("\n");
    return 0;
}