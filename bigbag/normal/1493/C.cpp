/**
 *  created: 06/03/2021, 16:16:13
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int max_c = 26;

int t, n, k, cnt[max_c], need[max_c];
char s[max_n];

bool check(int mx) {
    int tot = 0;
    for (int i = 0; i < max_c; ++i) {
        need[i] = 0;
        if (cnt[i] % k) {
            need[i] = k - (cnt[i] % k);
        }
        tot += need[i];
    }
    return tot <= mx;
}

void solve() {
    for (int i = n - 1; i >= 0; --i) {
        --cnt[s[i] - 'a'];
        for (int c = s[i] + 1; c <= 'z'; ++c) {
            ++cnt[c - 'a'];
            bool res = check(n - i - 1);
            --cnt[c - 'a'];
            if (res) {
                for (int j = 0; j < i; ++j) {
                    printf("%c", s[j]);
                }
                printf("%c", c);
                int tot = accumulate(need, need + max_c, 0), all = n - i - 1;
                for (int j = tot; j < all; ++j) {
                    printf("a");
                }
                for (int c2 = 0; c2 < max_c; ++c2) {
                    for (int j = 0; j < need[c2]; ++j) {
                        printf("%c", c2 + 'a');
                    }
                }
                puts("");
                return;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%s", &n, &k, s);
        if (n % k) {
            puts("-1");
            continue;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }
        bool ok = 1;
        for (int i = 0; i < max_c; ++i) {
            if (cnt[i] % k) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            puts(s);
            continue;
        }
        solve();
    }
    return 0;
}