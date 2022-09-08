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

const int max_n = 1111111, inf = 1000000007;

int n, k, a[max_n], t[max_n];
pair<int, int> b[max_n];
long long l;
vector<vector<int> > dp;

void proc() {
    sort(b, b + n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        while (i + 1 < n && b[i].first == b[i + 1].first) {
            a[b[i].second] = cnt;
            ++i;
        }
        a[b[i].second] = cnt;
        ++cnt;
    }
}

void update(int i, int x) {
    for (; i <= n; i = (i | (i + 1))) {
        t[i] += x;
        t[i] %= inf;
        if (t[i] < 0) {
            t[i] += inf;
        }
    }
}

int get(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += t[r];
        res %= inf;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> l >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = make_pair(a[i], i);
    }
    proc();
    dp.resize(k);
    for (int i = 0; i < k; ++i) {
        dp[i].resize(n);
    }
    for (int i = 0; i < n; ++i) {
        dp[0][i] = 1;
        update(a[i], 1);
    }
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = get(a[j]);
        }
        for (int j = 0; j < n; ++j) {
            int x = dp[i][j] - dp[i - 1][j];
            x %= inf;
            if (x < 0) {
                x += inf;
            }
            update(a[j], x);
        }
    }
    long long all = l / n;
    int ans = 0, to = l % n;
    for (int cnt = 0; cnt < k; ++cnt) {
        if (cnt + 1 <= all) {
            int C = (all - cnt) % inf;
            for (int i = 0; i < n; ++i) {
                int pl = (1LL * dp[cnt][i] * C) % inf;
                ans += pl;
                ans %= inf;
                //cout << cnt + 1 << " : " << pl << endl;
            }
        }
        if (cnt <= all) {
            int C = 1;
            for (int i = 0; i < to; ++i) {
                int pl = (1LL * dp[cnt][i] * C) % inf;
                ans += pl;
                ans %= inf;
                //cout << cnt + 1 << " :: " << pl << endl;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}