#include <bits/stdc++.h>

using namespace std;

const int max_n = 800088;

struct tree {
    pair<int, int> a[4 * max_n];
    void update(int v, int tl, int tr, int poz, int x) {
        if (tl == tr) {
            a[v] = make_pair(x, -poz);
            return;
        }
        int mid = (tl + tr) / 2;
        if (poz <= mid) {
            update(2 * v, tl, mid, poz, x);
        } else {
            update(2 * v + 1, mid + 1, tr, poz, x);
        }
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }
    pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int N, t[max_n];

void update(int i, int x) {
    for (; i <= N; i = (i | (i + 1))) {
        t[i] = max(t[i], x);
    }
}

int get_max(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res = max(res, t[r]);
    }
    return res;
}

int n, m, h[max_n], a[max_n], b[max_n];
int dp[max_n], f[max_n], ans1[max_n], ans2[max_n];
int num[2][max_n], sz[2];
tree tt;
vector<int> all;
vector<pair<int, int> > q1[max_n], q2[max_n];

int rev(int x) {
    return N - x + 1;
}

int get(int x) {
    vector<int>::iterator it = lower_bound(all.begin(), all.end(), x);
    return it - all.begin() + 1;
}

void proc() {
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 0; i < n; ++i) {
        h[i] = get(h[i]);
    }
    for (int i = 0; i < m; ++i) {
        b[i] = get(b[i]);
    }
    N = all.size();
    all.clear();
}

void add(int tp, int x) {
    num[tp][sz[tp]] = x;
    ++sz[tp];
    tt.update(1, 0, n - 1, x, -5);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
        all.push_back(h[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        --a[i];
        all.push_back(b[i]);
    }
    proc();
    for (int i = 0; i < m; ++i) {
        q1[a[i]].push_back(make_pair(b[i], i));
        q2[a[i]].push_back(make_pair(b[i], i));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q1[i].size(); ++j) {
            ans1[q1[i][j].second] = get_max(q1[i][j].first - 1);
        }
        dp[i] = get_max(h[i] - 1) + 1;
        update(h[i], dp[i]);
    }
    int ans = get_max(N);
    if (2 == 2) {
        int q1 = 0, q2 = 1;
        for (int i = 0; i < n; ++i) {
            tt.update(1, 0, n - 1, i, dp[i]);
            if (dp[i] == ans) {
                add(q1, i);
            }
        }
        for (int i = ans; i > 0; --i) {
            if (sz[q1] == 1) {
                f[num[q1][0]] = 1;
            }
            if (i == 1) {
                break;
            }
            sz[q2] = 0;
            int l = 0;
            for (int j = 0; j < sz[q1]; ++j) {
                int r = num[q1][j] - 1;
                if (l <= r) {
                    while (true) {
                        pair<int, int> p = tt.get_max(1, 0, n - 1, l, r);
                        p.second *= -1;
                        if (p.first < i - 1) {
                            break;
                        }
                        if (h[p.second] < h[r + 1]) {
                            add(q2, p.second);
                        } else {
                            tt.update(1, 0, n - 1, p.second, -5);
                        }
                    }
                }
            }
            swap(q1, q2);
        }
    }
    memset(t, 0, sizeof(t));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < q2[i].size(); ++j) {
            ans2[q2[i][j].second] = get_max(rev(q2[i][j].first + 1));
        }
        dp[i] = get_max(rev(h[i] + 1)) + 1;
        update(rev(h[i]), dp[i]);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", max(ans - f[a[i]], ans1[i] + ans2[i] + 1));
    }
    return 0;
}