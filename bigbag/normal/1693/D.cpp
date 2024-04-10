/**
 *  created: 16/06/2022, 19:04:25
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n], nxt[max_n];
map<pair<int, int>, int> dp;

int get_dp(int i_dec, int i_inc) {
    //cout << "#" << i_dec << " " << i_inc << endl;
    pair<int, int> p(i_dec, i_inc);
    auto it = dp.find(p);
    if (it != dp.end()) {
        return it->second;
    }
    int nxt = max(i_dec, i_inc) + 1;
    if (nxt == n) {
        return dp[p] = (n - 1);
    }
    if (a[i_dec] < a[i_inc]) {
        if (a[nxt] < a[i_dec]) {
            return dp[p] = get_dp(nxt, i_inc);
        }
        if (a[nxt] > a[i_inc]) {
            return dp[p] = get_dp(i_dec, nxt);
        }
        return dp[p] = (nxt - 1);
    }
    if (a[i_dec] < a[nxt]) {
        return dp[p] = get_dp(i_dec, nxt);
    }
    if (a[i_inc] > a[nxt]) {
        return dp[p] = get_dp(nxt, i_inc);
    }
    assert(a[i_inc] < a[nxt] && a[nxt] < a[i_dec]);
    if (nxt + 1 == n) {
        return dp[p] = nxt;
    }
    if (a[nxt] < a[nxt + 1]) {
        return dp[p] = get_dp(i_dec, nxt);
    }
    return dp[p] = get_dp(nxt, i_inc);
}

int get_max(int i) {
    int to = nxt[i];
    if (to + 1 == n) {
        return to;
    }
    if (a[i] < a[i + 1]) {
        if (a[to - 1] < a[to + 1]) {
            return max(get_dp(to, to + 1),
                       get_dp(to + 1, to - 1));
        }
        return get_dp(to + 1, to - 1);
    }
    if (a[to - 1] > a[to + 1]) {
        return max(get_dp(to + 1, to),
                   get_dp(to - 1, to + 1));
    }
    return get_dp(to - 1, to + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = i;
        if (i + 1 < n) {
            nxt[i] = nxt[i + 1];
            if ((a[i] < a[i + 1]) != (a[i + 1] < a[i + 2])) {
                nxt[i] = i + 1;
            }
        }
    }
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        //cout << i << ": " << get_max(i) << endl;
        ans += get_max(i) - i + 1;
    }
    cout << ans << "\n";
    return 0;
}