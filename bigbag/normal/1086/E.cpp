#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;
const int mod = 998244353;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power(mul(a, a), b / 2);
    }
    return mul(a, power(a, b - 1));
}

int inv(int x) {
    return power(x, mod - 2);
}

const int max_f = 2022;

int f[max_f], rf[max_f];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_f; ++i) {
        f[i] = mul(i, f[i - 1]);
    }
    rf[max_f - 1] = inv(f[max_f - 1]);
    for (int i = max_f - 2; i > 0; --i) {
        rf[i] = mul(i + 1, rf[i + 1]);
    }
}

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    return mul(f[n], mul(rf[k], rf[n - k]));
}

int n, ans, a[max_n][max_n], Used[max_n];

int get_order(int a[max_n]) {
    int res = 0;
    memset(Used, 0, sizeof(Used));
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < a[i]; ++j) {
            cnt += 1 - Used[j];
        }
        res += mul(cnt, f[n - 1 - i]);
        res %= mod;
        Used[a[i]] = 1;
    }
    return res;
}

int Y[max_n][max_n], pos[max_n];

struct tree {
    int t[max_n];

    void add(int i, int x) {
        for (; i < max_n; i = (i | (i + 1))) {
            t[i] += x;
        }
    }

    int get_sum(int r) const {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }

    int get_sum(int l, int r) const {
        if (l == 0) {
            return get_sum(r);
        }
        return get_sum(r) - get_sum(l - 1);
    }

    bool find(int x) const {
        return get_sum(x, x) == 1;
    }

    void clr() {
        memset(t, 0, sizeof(t));
    }
};

tree used, more;

int calc_x(int n) {
    int res = 0;
    for (int i = 0; i <= n; ++i) {
        int add = mul(get_c(n, i), f[n - i]);
        if (i % 2) {
            add = mod - add;
        }
        res += add;
        res %= mod;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            --a[i][j];
        }
    }
    int X = calc_x(n);
    int order1 = get_order(a[0]);
    int ans = mul(order1, power(X, n - 1));
    for (int cnt = 0; cnt < n; ++cnt) {
        Y[cnt][0] = calc_x(cnt);
        for (int occ = 1; occ <= cnt; ++occ) {
            Y[cnt][occ] = (Y[cnt][occ - 1] + Y[cnt - 1][occ - 1]) % mod;
        }
    }
    //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pos[a[i - 1][j]] = j;
        }
        int occ = 0;
        int add = 0;
        used.clr();
        more.clr();
        for (int x = 0; x < n; ++x) {
            if (pos[x] > 0) {
                more.add(x, 1);
            }
        }
        for (int j = 0; j < n; ++j) {
            int cnt_more = more.get_sum(a[i][j] - 1);
            int cnt_used = used.get_sum(a[i][j] - 1);
            if (a[i - 1][j] < a[i][j]) {
                if (more.find(a[i - 1][j])) {
                    --cnt_more;
                }
                if (used.find(a[i - 1][j])) {
                    --cnt_used;
                }
            }
            int cnt_not_more = a[i][j] - cnt_more - cnt_used;
            if (a[i - 1][j] < a[i][j]) {
                --cnt_not_more;
            }
            add += mul(cnt_more, Y[n - j - 1][occ + 1]);
            add %= mod;
            add += mul(cnt_not_more, Y[n - j - 1][occ]);
            add %= mod;
            /*for (int x = 0; x < a[i][j]; ++x) {
                if (!used[x] && x != a[i - 1][j]) {
                    int real_occ = occ;
                    if (pos[x] > j) {
                        ++real_occ;
                    }
                    add += Y[n - j - 1][real_occ];
                    add %= mod;
                }
            }*/
            if (more.find(a[i][j])) {
                more.add(a[i][j], -1);
            }
            if (more.find(a[i - 1][j + 1])) {
                more.add(a[i - 1][j + 1], -1);
            }
            used.add(a[i][j], 1);
            if (pos[a[i][j]] > j) {
                ++occ;
            }
            if (used.find(a[i - 1][j + 1])) {
                --occ;
            }
        }
        //cout << i << ": " << add << " " << power(X, n - i - 1) << endl;
        ans += mul(add, power(X, n - i - 1));
        ans %= mod;
    }
    printf("%d\n", ans);
    //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    return 0;
}