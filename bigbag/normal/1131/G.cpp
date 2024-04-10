#include <bits/stdc++.h>

using namespace std;

const int max_n = 10001110;
const long long inf = 1000111222000111222LL;

struct tree {
    int t[max_n];

    void clr() {
        for (int i = 0; i < max_n; ++i) {
            t[i] = 1000111222;
        }
    }

    int get_min(int r) {
        r = max_n - r - 1;
        int res = 1000111222;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res = min(res, t[r]);
        }
        return res;
    }

    void update(int i, int x) {
        i = max_n - i - 1;
        for (; i < max_n; i = (i | (i + 1))) {
            t[i] = min(t[i], x);
        }
    }
};

int n, h[max_n], l[max_n], r[max_n];
long long cost[max_n], dp[max_n];
tree t;

void read() {
    int blocks;
    scanf("%d%d", &blocks, &n);
    vector<vector<int>> a(blocks), b(blocks);
    for (int i = 0; i < blocks; ++i) {
        int k;
        scanf("%d", &k);
        a[i].resize(k);
        b[i].resize(k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a[i][j]);
        }
        for (int j = 0; j < k; ++j) {
            scanf("%d", &b[i][j]);
        }
    }
    int q;
    scanf("%d", &q);
    int pos = 0;
    while (q--) {
        int id, mul;
        scanf("%d%d", &id, &mul);
        --id;
        for (int i = 0; i < a[id].size(); ++i) {
            h[pos + i] = a[id][i];
            cost[pos + i] = 1LL * mul * b[id][i];
        }
        pos += a[id].size();
    }
}

void get_l(int l[]) {
    t.clr();
    for (int i = 0; i < n; ++i) {
        if (h[i] == 1 || i == 0) {
            l[i] = i;
        } else {
            l[i] = t.get_min(i - h[i] + 1);
        }
        t.update(i, l[i]);
    }
}

int main() {
    //freopen("output.txt", "w", stdout);
    read();
    get_l(l);
    reverse(h, h + n);
    get_l(r);
    reverse(h, h + n);
    reverse(r, r + n);
    for (int i = 0; i < n; ++i) {
        r[i] = n - 1 - r[i];

    }
    priority_queue<pair<long long, int>> q;
    for (int i = 0; i < n; ++i) {
        dp[i] = cost[i];
        if (l[i]) {
            dp[i] += dp[l[i] - 1];
        }
        pair<long long, int> p(-inf, -1);
        while (q.size()) {
            p = q.top();
            if (r[p.second] < i) {
                q.pop();
                p.first = -inf;
            } else {
                break;
            }
        }
        p.first *= -1;
        dp[i] = min(dp[i], p.first);
        long long ndp = cost[i];
        if (i) {
            ndp += dp[i - 1];
        }
        q.push(make_pair(-ndp, i));
    }
    printf("%I64d\n", dp[n - 1]);
    return 0;
}