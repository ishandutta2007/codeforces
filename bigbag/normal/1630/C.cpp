/**
 *  created: 27/01/2022, 18:18:22
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, max_lev = 19, inf = 1000111222;

template<typename T, int z = 1> // z = -1 for maximum
struct sparse_table {
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = z * a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get_min(int l, int r) const {
        if (l > r) {
            return z * inf;
        }
        const int lev = 31 - __builtin_clz(r - l + 1);
        return z * min(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};

int n, a[max_n], last[max_n];
int mx[max_n];
sparse_table<int, -1> st;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        last[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        mx[i] = last[a[i]];
    }
    st.init(n, mx);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (mx[i] > i) {
            int r = mx[i], cnt = 1;
            while (st.get_min(i, r) > r) {
                ++cnt;
                r = st.get_min(i, r);
            }
            ans += r - i - cnt;
            i = r;
        }
    }
    cout << ans << "\n";
    return 0;
}