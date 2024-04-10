/**
 *  created: 14/01/2021, 16:48:25
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n, m, sum[max_n], mx[max_n], mn[max_n];
int mx_pref[max_n], mn_pref[max_n];

int get_max(int l, int r) {
    int res = mx_pref[l - 1];
    res = max(res, sum[l - 1] + mx[r + 1] - sum[r]);
    return res;
}

int get_min(int l, int r) {
    int res = mn_pref[l - 1];
    res = min(res, sum[l - 1] + mn[r + 1] - sum[r]);
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        string s = read();
        for (int i = 0; i < n; ++i) {
            int x = 1;
            if (s[i] == '-') {
                x = -1;
            }
            sum[i + 1] = sum[i] + x;
        }
        mx[n + 1] = -inf;
        mn[n + 1] = inf;
        for (int i = n; i >= 0; --i) {
            mx[i] = max(mx[i + 1], sum[i]);
            mn[i] = min(mn[i + 1], sum[i]);
        }
        for (int i = 1; i <= n; ++i) {
            mx_pref[i] = max(mx_pref[i - 1], sum[i]);
            mn_pref[i] = min(mn_pref[i - 1], sum[i]);
        }
        while (m--) {
            int l, r;
            scanf("%d%d", &l, &r);
            int mx = get_max(l, r);
            int mn = get_min(l, r);
            //cout << mn << " " << mx << ": ";
            printf("%d\n", mx - mn + 1);
        }
    }
    return 0;
}