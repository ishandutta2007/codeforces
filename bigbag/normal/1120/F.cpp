#include <bits/stdc++.h>

using namespace std;

struct line {
    long long k;
    long long b;

    line(): k(0), b(0) {
    }

    line(long long k, long long b): k(k), b(b) {
    }

    long long get(long long x) const {
        return k * x + b;
    }
};

const int max_x = 100111;
const long long inf = 1000111222000111222LL;

struct tree {
    line a[4 * max_x];

    tree() {
        for (int i = 0; i < 4 * max_x; ++i) {
            a[i] = {0, inf};
        }
    }

    void update(int v, int l, int r, line &ln) {
        int mid = (l + r) / 2;
        if (a[v].get(mid) > ln.get(mid)) {
            swap(a[v], ln);
        }
        if (l == r) {
            return;
        }
        if (a[v].get(l) > ln.get(l)) {
            update(2 * v, l, mid, ln);
        }
        if (a[v].get(r) > ln.get(r)) {
            update(2 * v + 1, mid + 1, r, ln);
        }
    }

    long long get_min(int v, int l, int r, int x) {
        long long res = a[v].get(x);
        if (l == r) {
            return res;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            res = min(res, get_min(2 * v, l, mid, x));
        } else {
            res = min(res, get_min(2 * v + 1, mid + 1, r, x));
        }
        return res;
    }
};

struct line_container {
    tree t;

    void add(line l) {
        t.update(1, 0, max_x - 1, l);
    }

    long long get_min(int x) {
        return t.get_min(1, 0, max_x - 1, x);
    }
};

const int max_n = 100111;

int n, c, d;
int t[max_n], tp[max_n], p[max_n];
long long cnt[2][max_n], sum[2][max_n], dp[max_n], val[max_n], val2[max_n], mn[2];
line_container l[2];

void get_all_p() {
    const int mxt = d / c;
    int pos = n;
    for (int i = n; i >= 0; --i) {
        while (pos > 0 && t[i] - t[pos - 1] <= mxt) {
            --pos;
        }
        p[i] = pos;
    }
}

void upd(int j) {
    val[j] = dp[j] + 1LL * c * t[j] + 1LL * d * cnt[tp[j]][j - 1];
    val[j] += 1LL * d * cnt[tp[j] ^ 1][p[j] - 1];
    val[j] += 1LL * c * (1LL * t[j] * (cnt[tp[j] ^ 1][j - 1] - cnt[tp[j] ^ 1][p[j] - 1]) - (sum[tp[j] ^ 1][j - 1] - sum[tp[j] ^ 1][p[j] - 1]));

    val2[j] = dp[j] + 1LL * c * t[j] + 1LL * d * cnt[tp[j]][j - 1];
    val2[j] += 1LL * c * (1LL * t[j] * cnt[tp[j] ^ 1][j - 1] - sum[tp[j] ^ 1][j - 1]);
    l[tp[j]].add({-1LL * c * t[j], val2[j]});
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &c, &d);
    for (int i = 1; i <= n; ++i) {
        char ctp;
        scanf("%d %c", &t[i], &ctp);
        tp[i] = (ctp == 'W');
    }
    t[0] = -1000111222;
    ++n;
    scanf("%d", &t[n]);
    ++n;
    t[n] = t[n - 1];
    tp[n] = 1;
    for (int i = 1; i <= n; ++i) {
        cnt[tp[i]][i] = 1;
        sum[tp[i]][i] = t[i];
        sum[0][i] += sum[0][i - 1];
        cnt[0][i] += cnt[0][i - 1];
        sum[1][i] += sum[1][i - 1];
        cnt[1][i] += cnt[1][i - 1];
    }
    get_all_p();
    mn[0] = mn[1] = inf;
    upd(n);
    upd(n - 1);
    int pos = n;
    for (int i = n - 2; i >= 1; --i) {
        long long y = -1LL * c * t[i] - 1LL * d * cnt[tp[i] ^ 1][i] - 1LL * d * cnt[tp[i]][i];
        long long y2 = y + 1LL * d * cnt[tp[i]][i] + 1LL * c * sum[tp[i]][i];
        while (p[pos] >= i + 1) {
            mn[tp[pos]] = min(mn[tp[pos]], val[pos]);
            --pos;
        }
        dp[i] = mn[tp[i] ^ 1] + y;
        long long x = l[tp[i] ^ 1].get_min(cnt[tp[i]][i]);
        dp[i] = min(dp[i], x + y2);
        upd(i);
    }
    long long ans = inf;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, 1LL * (i - 1) * d + dp[i]);
        //cout << i << ": " << dp[i] << endl;
    }
    printf("%I64d\n", ans);
    return 0;
}