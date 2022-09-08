/**
 *  created: 21/03/2021, 16:02:45
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 303333, inf = 1000111222;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T mx[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        f[v] = 0;
        if (l == r) {
            mx[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mx[2 * v] += f[v];
            mx[2 * v + 1] += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            mx[v] += value;
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }

    T get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mx[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, a[max_n], b[max_n];
long long dp[max_n];
segment_tree<long long> st;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    dp[0] = 0;
    vector<pair<int, int>> v;
    v.push_back({0, 0});
    for (int i = 1; i <= n; ++i) {
        while (a[i] <= v.back().second) {
            st.update(1, 0, n, v[v.size() - 2].first, v.back().first - 1, -b[v.back().first]);
            v.pop_back();
        }
        st.update(1, 0, n, v.back().first, i - 1, b[i]);
        v.push_back({i, a[i]});
        dp[i] = st.get_max(1, 0, n, 0, i - 1);
        st.update(1, 0, n, i, i, dp[i]);
        //cout << i << ": " << dp[i] << endl;
    }
    printf("%lld\n", dp[n]);
    return 0;
}