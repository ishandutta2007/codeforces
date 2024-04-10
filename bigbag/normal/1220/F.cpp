#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;


struct tree {
    int a[4 * max_n], f[4 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
    }
    void push(int v, int l, int r) {
        if (f[v] != 0) {
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            a[2 * v] += f[v];
            a[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tl == l && tr == r) {
            f[v] += value;
            a[v] += value;
            return;
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }
    int get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
    void write(int v, int l, int r) {
        if (l == r) {
            cout << l << ' ' << r << " - " << a[v] << " (" << f[v] << ")\n";
            return;
        }
        cout << l << ' ' << r << " - " << a[v] << " (" << f[v] << ")\n";
        int mid = (l + r) / 2;
        write(2 * v, l, mid);
        write(2 * v + 1, mid + 1, r);
    }
} t;

int n, a[max_n], p[max_n], l[max_n], r[max_n];
vector<int> v;
vector<int> g[max_n], order;

void dfs2(int v) {
    l[v] = order.size();
    order.push_back(v);
    for (int to : g[v]) {
        dfs2(to);
    }
    r[v] = order.size();
    t.update(1, 0, n, l[v], r[v] - 1, 1);
}

void clr() {
    order.clear();
    memset(p, -1, sizeof(p));
    for (int i = 0; i < max_n; ++i) {
        g[i].clear();
    }
    t = tree();
}


vector<int> solve(vector<int> v) {
    if (v.empty()) {
        return {};
    }
    clr();
    reverse(v.begin(), v.end());
    int root = v[0];
    set<int> q{root};
    vector<int> all;
    for (int i = 1; i < v.size(); ++i) {
        auto it = q.upper_bound(v[i]);
        if (it == q.end()) {
            --it;
            p[v[i]] = *it;
            q.insert(v[i]);
        } else {
            r[v[i]] = *it;
            if (it == q.begin()) {
                root = v[i];
                p[*it] = root;
            } else {
                p[v[i]] = p[*it];
                p[*it] = v[i];
            }
            q.erase(it, q.end());
            q.insert(v[i]);
        }
    }
    for (int x : v) {
        //cout << root << ", " << x << " " << p[x] << endl;
        if (p[x] != -1) {
            g[p[x]].push_back(x);
        }
    }
    dfs2(root);
    vector<int> res;
    for (int i = v.size() - 1; i >= 0; --i) {
        //cout << v[i] << ": " << l[v[i]] << " " << r[v[i]] << endl;
        /*for (int j = i; j >= 0; --j) {
            cout << v[j] << " ";
        }
        cout << "  res = " << t.get_max(1, 0, n, 0, n) << endl;*/
        res.push_back(t.get_max(1, 0, n, 0, n));
        t.update(1, 0, n, l[v[i]], r[v[i]] - 1, -1);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] < a[pos]) {
            pos = i;
        }
    }
    rotate(a, a + pos + 1, a + n);
    for (int i = n - 2; i >= 0; --i) {
        v.push_back(a[i]);
    }
    reverse(v.begin(), v.end());
    vector<int> h1 = solve(v);
    reverse(v.begin(), v.end());
    vector<int> h2 = solve(v);
    int sd = 0, mn = n;
    for (int i = 0; i < h1.size(); ++i) {
        int r = 0;
        int l = h1[h1.size() - 1 - i];
        if (i) {
            r = h2[i - 1];
        }
        int res = 1 + max(l, r);
        //cout << i << ": " << res << ", " << l << " " << r << endl;
        if (mn > res) {
            mn = res;
            sd = i;
        }
    }
    sd += pos + 1;
    sd %= n;
    printf("%d %d\n", mn, sd);
    return 0;
}