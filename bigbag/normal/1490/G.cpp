/**
 *  created: 16/02/2021, 16:59:54
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, m, a[max_n];
long long sum[max_n];
vector<pair<long long, int>> v;

long long solve(long long x) {
    if (sum[n - 1] <= 0) {
        if (v.back().first < x) {
            return -1;
        }
        auto it = lower_bound(v.begin(), v.end(), make_pair(x, -inf));
        return it->second;
    }
    long long full = (x - v.back().first);
    if (full <= 0) {
        full = 0;
    } else {
        full = (full + sum[n - 1] - 1) / sum[n - 1];
    }
    x -= full * sum[n - 1];
    assert(x > 0);
    auto it = lower_bound(v.begin(), v.end(), make_pair(x, -inf));
    return full * n + it->second;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        v.clear();
        long long mx = -1LL * inf * inf;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            sum[i] = a[i];
            if (i) {
                sum[i] += sum[i - 1];
            }
            if (sum[i] > mx) {
                v.push_back({sum[i], i});
                mx = sum[i];
            }
        }
        while (m--) {
            int x;
            scanf("%d", &x);
            printf("%lld ", solve(x));
        }
        puts("");
    }
    return 0;
}