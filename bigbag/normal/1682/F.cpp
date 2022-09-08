/**
 *  created: 22/05/2022, 18:32:15
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, mod = 1000000007;

void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

int mul(long long a, long long b) {
    a %= mod;
    a += mod;
    a %= mod;
    b %= mod;
    b += mod;
    b %= mod;
    return a * b % mod;
}

template<typename T>
struct segment_tree {
    T sum[4 * max_n];

    void build(int v, int l, int r, int a[]) {
        if (l == r) {
            sum[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void update(int v, int l, int r, int x, T value) {
        if (l == r) {
            sum[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

int n, q, a[max_n], ab[max_n], ans[max_n];
long long b[max_n];
segment_tree<long long> st1, st2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    for (int i = n; i >= 1; --i) {
        a[i] += mod - a[i - 1];
        a[i] %= mod;
    }
    rotate(a, a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        ab[i] = mul(a[i], b[i]);
    }
    st1.build(1, 1, n, ab);
    st2.build(1, 1, n, a);
    vector<pair<long long, array<int, 3>>> all;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        all.push_back({b[l - 1], {l, r, i}});
    }
    sort(all.begin(), all.end());
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 1);
    sort(ids.begin(), ids.end(), [&](int i, int j) {
            return b[i] < b[j];
         });
    int pos = 0;
    for (auto [B, arr] : all) {
        auto [l, r, id] = arr;
        while (pos < ids.size() && b[ids[pos]] < B) {
            st1.update(1, 1, n, ids[pos], (mod - mul(a[ids[pos]], b[ids[pos]])) % mod);
            st2.update(1, 1, n, ids[pos], (mod - a[ids[pos]]) % mod);
            ++pos;
        }
        int res = st1.get_sum(1, 1, n, l, r - 1) % mod;
        dec(res, mul(B, st2.get_sum(1, 1, n, l, r - 1)));
        ans[id] = res;
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}