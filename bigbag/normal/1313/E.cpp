#include <bits/stdc++.h>

using namespace std;

const int max_n = 1500555, inf = 1000111222;

struct tree {
    long long a[4 * max_n], f[4 * max_n];

    void clr() {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
    }

    void push(int v, int l, int r) {
        if (f[v] != 0) {
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            int mid = (l + r) / 2;
            a[2 * v] += (mid - l + 1) * f[v];
            a[2 * v + 1] += (r - mid) * f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, long long value) {
        if (tl == l && tr == r) {
            a[v] += (r - l + 1) * value;
            f[v] += value;
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
        a[v] = (a[2 * v] + a[2 * v + 1]);
    }

    long long get_sum(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (tl == l && tr == r) {
            return a[v];
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

void get_z_function(const string &s, int z[]) {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); ++i) {
        z[i] = 0;
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < s.length() && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

int n, m, z[2][max_n], mx[2][max_n], cnt[2][max_n];
string a[2], s, rs;
long long ans;
tree t;
vector<int> v[max_n];

void proc1() {
    t.clr();
    for (int i = 0; i < max_n; ++i) {
        v[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        if (mx[0][i]) {
            v[i + m - 1].push_back(max(1, m - mx[0][i]));
        }
    }
    for (int i = 0; i < n; ++i) {
        t.update(1, 0, m, 0, mx[1][i], 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int l : v[i]) {
            ans -= t.get_sum(1, 0, m, l, m - 1);
        }
        t.update(1, 0, m, 0, mx[1][i], -1);
    }
}

void proc2() {
    t.clr();
    for (int i = 0; i < max_n; ++i) {
        v[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        if (mx[1][i]) {
            v[i + 1].push_back(max(1, m - mx[1][i]));
        }
    }
    for (int i = 0; i < n; ++i) {
        t.update(1, 0, m, 0, mx[0][i], 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int l : v[i]) {
            ans -= t.get_sum(1, 0, m, l, m - 1);
        }
        t.update(1, 0, m, 0, mx[0][i], -1);
    }
}

int get_sum(int tp, int l, int r) {
    if (!l) {
        return cnt[tp][r];
    }
    return cnt[tp][r] - cnt[tp][l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    a[0] = read();
    a[1] = read();
    s = read();
    rs = s;
    reverse(rs.begin(), rs.end());
    get_z_function(s + "#" + a[0], z[0]);
    string ra1 = a[1];
    reverse(ra1.begin(), ra1.end());
    get_z_function(rs + "#" + ra1, z[1]);
    for (int i = s.length() + 1; i <= s.length() + n; ++i) {
        mx[0][i - (s.length() + 1)] = z[0][i];
        mx[1][n - 1 - (i - (s.length() + 1))] = z[1][i];
    }
    proc1();
    //cout << "#" << ans << endl;
    proc2();
    //cout << "#" << ans << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            ++cnt[i][mx[i][j]];
        }
        for (int j = 1; j <= m; ++j) {
            cnt[i][j] += cnt[i][j - 1];
        }
    }
    for (int i = 1; i < m; ++i) {
        const int s0 = get_sum(0, i, m);
        const int s1 = get_sum(1, m - i, m);
        //cout << i << ": " << s0 << " " << s1 << endl;
        ans += 1LL * s0 * s1;
    }
    printf("%I64d\n", ans);
    return 0;
}