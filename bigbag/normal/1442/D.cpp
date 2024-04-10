#include <bits/stdc++.h>

using namespace std;

const int max_n = 3033, inf = 1000111222;

int n, k;
long long sum[max_n];
vector<int> a[max_n];
vector<long long> pref[max_n];

long long ans, dp[max_n];

void add(int l, int r) {
    for (int i = l; i <= r; ++i) {
        int mx = k;
        mx -= a[i].size();
        for (int x = mx; x >= 0; --x) {
            dp[x + a[i].size()] = max(dp[x + a[i].size()], dp[x] + sum[i]);
        }
    }
}

void solve(int l, int r) {
    if (l == r) {
        for (int x = 0; x <= k; ++x) {
            if (x + a[l].size() >= k) {
                long long add = 0;
                if (k - x - 1 >= 0) {
                    add = pref[l][k - x - 1];
                }
                ans = max(ans, dp[x] + add);
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    vector<long long> tmp(dp, dp + k + 1);
    add(mid + 1, r);
    solve(l, mid);
    copy(tmp.begin(), tmp.end(), dp);
    add(l, mid);
    solve(mid + 1, r);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int len;
        scanf("%d", &len);
        a[i].resize(len);
        pref[i].resize(len);
        for (int &x : a[i]) {
            scanf("%d", &x);
        }
        pref[i][0] = a[i][0];
        for (int j = 1; j < len; ++j) {
            pref[i][j] = pref[i][j - 1] + a[i][j];
        }
        sum[i] = pref[i][len - 1];
    }
    solve(0, n - 1);
    cout << ans << "\n";
    return 0;
}