/**
 *  created: 28/11/2021, 18:26:26
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

struct Node {
    long long val, sum, mx, len;

    Node() {
    }

    Node(long long x): val(x), sum(x), mx(x), len(1) {

    }

    Node(long long val, long long sum, long long mx, long long len): val(val), sum(sum), mx(mx), len(len) {
    }

    void add(long long x) {
        //cout << "mx = " << mx << " -> " << mx + x << endl;
        sum += x * len;
        mx += x;
        val += x * len * (len + 1) / 2;
    }
};

Node merge(const Node &a, const Node &b) {
    return {
        a.val + a.sum * b.len + b.val,
        a.sum + b.sum,
        max(a.mx, b.mx),
        a.len + b.len
    };
}

struct segment_tree {
    long long f[4 * max_n];
    Node a[4 * max_n];

    void build(int v, int l, int r, long long arr[]) {
        f[v] = 0;
        if (l == r) {
            a[v] = Node(arr[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, arr);
        build(2 * v + 1, mid + 1, r, arr);
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }

    void push(int v) {
        if (f[v]) {
            a[2 * v].add(f[v]);
            a[2 * v + 1].add(f[v]);
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, long long value) {
        if (tl == l && tr == r) {
            f[v] += value;
            a[v].add(value);
            return;
        }
        int mid = (tl + tr) / 2;
        push(v);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }

    Node get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        push(v);
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return merge(get_sum(2 * v, tl, mid, l, mid), get_sum(2 * v + 1, mid + 1, tr, mid + 1, r));
    }

    int get_first(int v, int tl, int tr, long long val) {
        if (a[v].mx <= val) {
            return -1;
        }
        if (tl == tr) {
            //cout << "#$$$$ " << tl << "  " << val << " " << a[v].mx << endl;
            return tl;
        }
        push(v);
        int mid = (tl + tr) / 2;
        int res = get_first(2 * v, tl, mid, val);
        if (res != -1) {
            return res;
        }
        return get_first(2 * v + 1, mid + 1, tr, val);
    }
};

int n, m, q;
long long a[111], b[max_n];
segment_tree st;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = n - 1; i >= 1; --i) {
        a[i] -= a[i - 1];
    }
    for (int i = m - 1; i >= 1; --i) {
        b[i] -= b[i - 1];
    }
    st.build(1, 1, m - 1, b);
    while (q--) {
        int tp, k, d;
        cin >> tp >> k >> d;
        if (tp == 1) {
            for (int i = n - k; i < n; ++i) {
                a[i] += d;
            }
        } else {
            st.update(1, 1, m - 1, max(1, m - k), m - 1, d);
            if (k == m) {
                b[0] += d;
            }
            //cout << "########" << d << endl;
            /*for (int i = m - k; i < m; ++i) {
                b[i] += d;
            }*/
        }
        int x = 0, y = 0;
        long long ans = (a[0] + b[0]) * (n + m - 1);
        while (x + 1 < n && y + 1 < m) {
            int to = st.get_first(1, 1, m - 1, a[x + 1]) - 1;
            if (to == -2) {
                to = m - 1;
            }
            //cout << a[x + 1] << "    " << to << endl;
            if (y + 1 <= to) {
                Node nd = st.get_sum(1, 1, m - 1, y + 1, to);
                ans += nd.val + nd.sum * (n - 1 - x + m - 1 - to);
                y = to;
            }
            ans += a[x + 1] * (n - 1 - x + m - 1 - y);
            //cout << "#   " << a[x + 1] << " " << (n - 1 - x + m - 1 - y) << endl;
            ++x;
        }
        while (x + 1 < n) {
            ++x;
            ans += a[x] * (n - x);
        }
        if (y + 1 < m) {
            ans += st.get_sum(1, 1, m - 1, y + 1, m - 1).val;
        }
        cout << ans << "\n";
    }
    return 0;
}