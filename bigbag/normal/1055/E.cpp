#include <bits/stdc++.h>

using namespace std;

const int max_n = 1505, inf = 1000111222;

int n, s, m, k, a[max_n], b[max_n], dp[2][max_n];
pair<int, int> p[max_n];
vector<int> l, r;
vector<int> diff;

int get_sum(int l, int r) {
    if (l == 0) {
        return b[r];
    }
    return b[r] - b[l - 1];
}

bool check(int x) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] <= x;
        if (i) {
            b[i] += b[i - 1];
        }
    }
    memset(dp, 0, sizeof(dp));
    int q1 = 0, q2 = 1, res = 0;
    for (int cnt = 1; cnt <= m; ++cnt) {
        int pos = l.size() - 1, mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (pos >= 0 && i <= l[pos]) {
                mx = max(mx, get_sum(l[pos], r[pos]) + dp[q1][r[pos] + 1]);
                --pos;
            }
            dp[q2][i] = mx;
            if (pos >= 0 && i <= r[pos]) {
                dp[q2][i] = max(dp[q2][i], get_sum(i, r[pos]) + dp[q1][r[pos] + 1]);
            }
            res = max(res, dp[q2][i]);
        }
        swap(q1, q2);
    }
    return res >= k;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &s, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        diff.push_back(a[i]);
    }
    for (int i = 0; i < s; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second);
        --p[i].first;
        --p[i].second;
    }
    sort(diff.begin(), diff.end());
    diff.erase(unique(diff.begin(), diff.end()), diff.end());
    sort(p, p + s);
    l.push_back(p[0].first);
    r.push_back(p[0].second);
    for (int i = 1; i < s; ++i) {
        if (r.back() >= p[i].second) {
            continue;
        }
        l.push_back(p[i].first);
        r.push_back(p[i].second);
    }
    int l = -1, r = diff.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(diff[mid])) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == diff.size()) {
        puts("-1");
    } else {
        printf("%d\n", diff[r]);
    }
    return 0;
}