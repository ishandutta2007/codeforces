#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, mod = 998244353, inf = 1000111222;
const int max_c = 505;
const int max_m = 2 * max_c;

const int max_lev = 20;
int mins[max_lev][max_n], num[max_n];

void get_all_mins(int n, int a[]) {
    for (int i = 0; i < n; ++i) {
        mins[0][i] = a[i];
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            mins[i][j] = min(mins[i - 1][j], mins[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

int get_min(int l, int r) {
    if (l > r) {
        return inf;
    }
    int lev = num[r - l + 1];
    return min(mins[lev][l], mins[lev][r - (1 << lev) + 1]);
}

int n, m, a[max_n], mn[max_m][max_m], dp[max_m][max_m];
int mn_pos[max_c], mx_pos[max_c];
bool bad[max_m][max_m];

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int get_dp(int l, int r) {
    return dp[r - l + 1][l];
}

void calc_mins() {
    for (int l = 0; l < n; ++l) {
        int x = inf;
        for (int r = l; r <= n; ++r) {
            x = min(x, a[r]);
            mn[l][r] = x;
        }
    }
}

void upd_a() {
    vector<int> v;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (i == mn_pos[a[i]] || i == mx_pos[a[i]]) {
            if (!v.empty() && v.back() == a[i]) {
                v.pop_back();
                pos.pop_back();
            }
            v.push_back(a[i]);
            pos.push_back(i);
        }
    }
    n = v.size();
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i) {
        a[i] = v[i];
    }
    calc_mins();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (get_min(pos[i], pos[j]) < mn[i][j]) {
                bad[i][j] = 1;
            }
        }
    }
}

void calc_poss() {
    for (int i = 0; i < max_c; ++i) {
        mn_pos[i] = inf;
        mx_pos[i] = -inf;
    }
    for (int i = 0; i < n; ++i) {
        mn_pos[a[i]] = min(mn_pos[a[i]], i);
        mx_pos[a[i]] = max(mx_pos[a[i]], i);
    }
}

void check() {
    set<int> q;
    for (int i = 0; i < n; ++i) {
        if (q.size() && *q.rbegin() > a[i]) {
            puts("0");
            exit(0);
        }
        if (mn_pos[a[i]] == i) {
            q.insert(a[i]);
        }
        if (mx_pos[a[i]] == i) {
            q.erase(a[i]);
        }
    }
}

int main() {
    //8freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }
    get_all_mins(n, a);
    calc_poss();
    check();
    upd_a();
    calc_poss();
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 1;
    }
    for (int len = 1; len <= n; ++len) {
        for (int L = 0; L + len <= n; ++L) {
            const int R = L + len - 1;
            int x = mn[L][R];
            if (mn_pos[x] < L || mx_pos[x] > R) {
                continue;
            }
            int cl = 0, cr = 0;
            for (int l = mn_pos[x]; l >= L && !bad[l][mn_pos[x]]; --l) {
                cl += mul(get_dp(L, l - 1), get_dp(l, mn_pos[x] - 1));
                cl %= mod;
            }
            for (int r = mx_pos[x]; r <= R && !bad[mx_pos[x]][r]; ++r) {
                cr += mul(get_dp(mx_pos[x] + 1, r), get_dp(r + 1, R));
                cr %= mod;
            }
            dp[len][L] = mul(cl, cr);
            if (mn_pos[x] != mx_pos[x]) {
                dp[len][L] = mul(dp[len][L], get_dp(mn_pos[x] + 1, mx_pos[x] - 1));
            }
            //cout << L << " " << R << ": " << dp[len][L] << endl;
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}