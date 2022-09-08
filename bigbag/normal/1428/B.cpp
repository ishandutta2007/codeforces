#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int t, n;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &n, s);
        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = 0; i < n; ++i) {
            c1 += s[i] == '>' || s[i] == '-';
            c2 += s[i] == '<' || s[i] == '-';
        }
        if (c1 == n || c2 == n) {
            printf("%d\n", n);
        } else {
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '-' || s[(i + n - 1) % n] == '-') {
                    ++ans;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}