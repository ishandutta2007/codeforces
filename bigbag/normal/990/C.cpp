#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, bal[max_n], mn[max_n];
char s[max_n];
long long ans;
int q[max_n];

void solve() {
    memset(q, 0, sizeof(q));
    for (int i = 0; i < n; ++i) {
        if (mn[i] >= 0) {
            ans += q[bal[i]];
        }
        if (bal[i] <= 0) {
            if (-mn[i] < -bal[i] + 1) {
                ++q[-bal[i]];
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int len = strlen(s), cur = 0;
        for (int j = 0; j < len; ++j) {
            if (s[j] == '(') {
                ++cur;
            } else {
                --cur;
            }
            mn[i] = min(mn[i], cur);
        }
        bal[i] = cur;
        if (mn[i] == 0 && bal[i] == 0) {
            ++ans;
        }
    }
    solve();
    reverse(mn, mn + n);
    reverse(bal, bal + n);
    solve();
    printf("%I64d\n", ans);
    return 0;
}