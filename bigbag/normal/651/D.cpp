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

const int max_n = 555555, inf = 1111111111;

int n, a, b, t, ans, dp[max_n];
char s[max_n];

void solve() {
    char c = '#';
    int x = 0;
    for (int i = 1; i < n; ++i) {
        x += a;
        if (c != s[i]) {
            x += b;
        }
        ++x;
        dp[i] = x;
        c = 'h';
        //cout << i << " " << dp[i] << endl;
    }
    x = 0;
    int cnt = t, res = 0, tm = 0;
    c = 'h';
    do {
        --cnt;
        if (c != s[x]) {
            cnt -= b;
        }
        if (cnt < 0) {
            break;
        }
        ++res;
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int q = 0;
            if (c == s[1]) {
                q = b;
            }
            if (tm + dp[mid] - q <= cnt) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (x) {
            l = min(l, x - 1);
        }
        ans = max(ans, res + l);
        //cout << x << " : " << res << "  " << l << "  res = " << res + l << "   " << cnt << "    tm = " << tm << endl;
        --x;
        cnt -= a;
        tm += a;
        if (x == -1) {
            x += n;
        }
    } while (x != 0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%s", &n, &a, &b, &t, s);
    solve();
    if (n > 1) {
        reverse(s + 1, s + n);
        solve();
    }
    printf("%d\n", ans);
    return 0;
}