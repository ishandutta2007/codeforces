#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1011111, max_lev = 21, inf = 1111111111;

struct tree {
    int a[4 * max_n], f[4 * max_n];
    tree() {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
    }
    void push(int v, int l, int r) {
        if (f[v] != 0) {
            a[v] += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tl == l && tr == r) {
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
        a[v] = min(a[2 * v] + f[2 * v], a[2 * v + 1] + f[2 * v + 1]);
    }
    int get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v] + f[v];
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
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
};

int n, a[2][max_n], cl[2][max_n], num[2][max_n], f[max_n], sum[max_n];
pair<int, pair<int, int> > p[max_n], p2[max_n];
string s;
tree t;

bool cmp(int a, int b) {
    return s[a] < s[b] || s[a] == s[b] && a < b;
}

void my_sort() {
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; ++i) {
        ++sum[p[i].second.first + 1];
    }
    for (int i = 1; i < n; ++i) {
        sum[i] += sum[i - 1];
    }
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        p2[sum[p[i].second.first]++] = p[i];
    }
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; ++i) {
        ++sum[p2[i].first + 1];
    }
    for (int i = 1; i < n; ++i) {
        sum[i] += sum[i - 1];
    }
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        p[sum[p2[i].first]++] = p2[i];
    }
}

int f1 = 0, f2 = 1;

void get_suffix_array() {
    for (int i = 0; i < n; ++i) {
        a[0][i] = i;
    }
    sort(a[0], a[0] + n, cmp);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        num[0][a[0][i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        while (i + 1 < n && s[a[0][i]] == s[a[0][i + 1]]) {
            cl[0][i] = cnt;
            ++i;
        }
        cl[0][i] = cnt;
        ++cnt;
    }
    for (int lev = 1, len = 1; len <= n; ++lev, len *= 2) {
        for (int i = 0; i < n; ++i) {
            p[i] = make_pair(cl[f1][num[f1][i]], make_pair(cl[f1][num[f1][(i + len) % n]], i));
        }
        //my_sort();
        sort(p, p + n);
        for (int i = 0; i < n; ++i) {
            a[f2][i] = p[i].second.second;
            num[f2][a[f2][i]] = i;
        }
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            while (i + 1 < n && p[i].first == p[i + 1].first && p[i].second.first == p[i + 1].second.first) {
                cl[f2][i] = cnt;
                ++i;
            }
            cl[f2][i] = cnt;
            ++cnt;
        }
        swap(f1, f2);
        if (cnt == n) {
            return;
        }
    }
}

int main() {
    cin >> s;
    n = s.length();
    get_suffix_array();
    int bal = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++bal;
        } else {
            --bal;
        }
        t.update(1, 0, n - 1, i, i, bal);
    }
    for (int i = 0; i < n; ++i) {
        int mn = t.get_min(1, 0, n - 1, 0, n - 1);
        if (bal > 0) {
            if (mn >= 0) {
                f[i] = 1;
            }
        } else {
            if (mn - bal >= 0) {
                f[i] = 1;
            }
        }
        int x = 1;
        if (s[i] == '(') {
            x = -1;
        }
        if (i + 1 < n) {
            t.update(1, 0, n - 1, i + 1, n - 1, x);
        }
        if (i) {
            t.update(1, 0, n - 1, 0, i - 1, x);
        }
        t.update(1, 0, n - 1, i, i, bal - t.get_min(1, 0, n - 1, i, i));
    }
    if (bal < 0) {
        for (int i = 0; i < -bal; ++i) {
            printf("(");
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f[a[f1][i]] == 1) {
            int poz = a[f1][i];
            for (int j = 0; j < n; ++j) {
                printf("%c", s[(j + poz) % n]);
            }
            break;
        }
    }
    if (bal > 0) {
        for (int i = 0; i < bal; ++i) {
            printf(")");
        }
    }
    return 0;
}