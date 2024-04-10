#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, max_lev = 20, mod = 1000000007;

int n, k, a[max_n], mx[max_lev][max_n], dp[max_n];
multiset<int> q;

void add(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    --k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = n - k + 1; i < n; ++i) {
        q.insert(a[i]);
    }
    for (int i = n - k; i >= 0; --i) {
        q.insert(a[i]);
        mx[0][i] = *q.rbegin();
        for (int lev = 1; lev < max_lev; ++lev) {
            long long nxt = i + (1LL << (lev - 1)) * k;
            int val = mx[lev - 1][i];
            if (nxt < n) {
                val = max(val, mx[lev - 1][nxt]);
            }
            mx[lev][i] = val;
        }

        int cur = i;
        for (int lev = max_lev - 1; lev >= 0; --lev) {
            long long nxt = cur + (1LL << lev) * k;
            if (nxt <= n && mx[lev][cur] <= mx[0][i]) {
                cur = nxt;
            }
        }
        dp[i] = (1LL * mx[0][i] * ((cur - i) / k)) % mod;
        if (cur < n) {
            add(dp[i], dp[cur]);
        }
        //cout << i << " -> " << cur << "   " << mx[0][i] << " " << mx[1][i] << ", dp = " << dp[i] << endl;
        q.erase(q.find(a[i + k - 1]));
    }
    int ans = 0;
    for (int i = 0; i + k < n; ++i) {
        int first = max(a[i], mx[0][i + 1]);
        int cur = i + k + 1;
        for (int lev = max_lev - 1; lev >= 0; --lev) {
            long long nxt = cur + (1LL << lev) * k;
            if (nxt <= n && mx[lev][cur] <= first) {
                cur = nxt;
            }
        }
        int pl = (1LL * first * (1 + (cur - i - k - 1) / k)) % mod;
        if (cur < n) {
            add(pl, dp[cur]);
        }
        add(ans, pl);
        //cout << i << ": " << pl << "   " << cur << endl;
    }
    printf("%d\n", ans);
    return 0;
}