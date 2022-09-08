#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_lev = 18;

template<typename T, int z = 1>
struct sparse_table {
    int num[max_n];
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = z * a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
        for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
            for (int j = i; j <= n && j < i * 2; ++j) {
                num[j] = x;
            }
        }
    }

    T get_min(int l, int r) const {
        if (l > r) {
            return z * inf;
        }
        int lev = num[r - l + 1];
        return z * min(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};


int t, n, a[max_n];
sparse_table<int, 1> mn;
sparse_table<int, -1> mx;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        mn.init(n, a);
        mx.init(n, a);
        int x = 0, pos = n - 1;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            x = max(x, a[i]);
            while (pos >= 0 && a[pos] < x) {
                --pos;
            }
            if (pos - 1 <= i || a[pos] != x) {
                continue;
            }
            int j = pos;
            for (int k = max_lev - 1; k >= 0; --k) {
                int nj = j - (1 << k);
                if (i + 1 < nj && mn.get_min(i + 1, nj - 1) <= x && mx.get_min(nj, n - 1) == x) {
                    j = nj;
                }
            }
            //cout << i << " " << j << ": " << x << endl;
            if (mn.get_min(i + 1, j - 1) == mx.get_min(j, n - 1) && x == mx.get_min(j, n - 1)) {
                printf("YES\n%d %d %d\n", i + 1, j - i - 1, n - j);
                ok = true;
                break;
            }
        }
        if (!ok) {
            puts("NO");
        }
    }
    return 0;
}