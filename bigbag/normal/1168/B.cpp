#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, r[max_n];
char s[max_n];
bitset<max_n> b1, b2;

void solve() {
    for (int i = 0; i < n; ++i) {
        b1[i] = s[i] - '0';
        b2[i] = s[n - 1 - i] - '0';
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            int pos = ((b1 >> (i + 1)) & (b2 >> (n - i)))._Find_first();
            if (pos != max_n) {
                r[i - pos - 1] = min(r[i - pos - 1], i + pos + 1);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (1) {
        scanf("%s", s);
        n = strlen(s);
    } else {
        n = 300000;
        for (int i = 0; i < n; ++i) {
            s[i] = '1';
        }
    }
    for (int i = 0; i < n; ++i) {
        r[i] = n;
    }
    solve();
    for (int i = 0; i < n; ++i) {
        s[i] = '1' - s[i] + '0';
    }
    solve();
    int mn = n;
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        mn = min(mn, r[i]);
        ans += n - mn;
    }
    printf("%I64d\n", ans);
    return 0;
}