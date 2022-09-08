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

struct tree {
    pair<int, int> maxs[4 * max_n];
    void build(int v, int l, int r) {
        maxs[v] = make_pair(0, l);
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
    }
    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            maxs[v] = make_pair(value, l);
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
    pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
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

int n, d, dp[max_n], par[max_n], last[max_n];
long long a[max_n], b[max_n];
map<long long, int> q;
tree t;

void init() {
    int cnt = 0;
    for (int i = 0; i < n;) {
        q[b[i]] = cnt;
        ++cnt;
        int poz = i;
        while (poz < n && b[i] == b[poz]) {
            ++poz;
        }
        i = poz;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    init();
    t.build(1, 0, n - 1);
    int ans = -1, poz;
    for (int i = 0; i < n; ++i) {
        long long maxx = a[i] - d, minx = a[i] + d;
        int l, r;
        pair<int, int> p(0, -1);
        l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (b[mid] <= maxx) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (b[l] <= maxx) {
            pair<int, int> pp = t.get_max(1, 0, n - 1, 0, q[b[l]]);
            //cout << i << ": " << 0 << " " << q[b[l]] << endl;
            if (pp.first == 0) {
                pp.second = -1;
            }
            p = max(p, pp);
        }
        l = -1, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (b[mid] >= minx) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (b[r] >= minx) {
            pair<int, int> pp = t.get_max(1, 0, n - 1, q[b[r]], n - 1);
            //cout << i << ":: " << q[b[r]] << " " << n - 1 << endl;
            if (pp.first == 0) {
                pp.second = -1;
            }
            p = max(p, pp);
        }
        dp[i] = p.first + 1;
        par[i] = -1;
        if (p.second != -1) {
            par[i] = last[p.second];
        }
        last[q[a[i]]] = i;
        //cout << i << " - " << dp[i] << " " << par[i] << endl;
        //cout << i << " update(" << q[a[i]] << " <- " << dp[i] << ")\n";
        t.update(1, 0, n - 1, q[a[i]], dp[i]);
        if (dp[i] > ans) {
            ans = dp[i];
            poz = i;
        }
    }
    cout << ans << endl;
    vector<int> av;
    while (poz != -1) {
        av.push_back(poz + 1);
        poz = par[poz];
    }
    for (int i = ans - 1; i >= 0; --i) {
        cout << av[i] << " ";
    }
    return 0;
}