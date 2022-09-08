#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int t[max_n];

void update(int i, int x) {
    for (; i < max_n; i = (i | (i + 1))) {
        t[i] = min(t[i], x);
    }
}

int get_min(int r) {
    int res = inf;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res = min(res, t[r]);
    }
    return res;
}

int n, a[max_n], dp[max_n];
vector<int> v;

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < max_n; ++i) {
        t[i] = inf;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i] *= 2;
        a[i + n] = a[i + 2 * n] = a[i];
        v.push_back(a[i]);
    }
    n *= 3;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    dp[n] = n;
    for (int i = n - 1; i >= 0; --i) {
        int x = compress(a[i] / 2) - 1;
        dp[i] = min(dp[i + 1], get_min(x));
        update(compress(a[i]), i);
    }
    for (int i = 0; i < n / 3; ++i) {
        if (dp[i] == n) {
            dp[i] = -1;
        } else {
            dp[i] -= i;
        }
        printf("%d ", dp[i]);
    }
    puts("");
    return 0;
}