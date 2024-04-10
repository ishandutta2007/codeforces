#include <bits/stdc++.h>

#define MAXN (60)

int n, k;
std::string ans[MAXN];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        if (i < 26) {
            ans[i] = 'A' + i;
        } else {
            ans[i] = "A";
            ans[i] += 'a' + i - 26;
        }
    }
    for (int i = 0; i + k <= n; ++i) {
        static char s[10];
        scanf("%s", s);
        if (s[0] == 'N') {
            ans[i + k - 1] = ans[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s%c", ans[i].c_str(), " \n"[i == n - 1]);
    }
    return 0;
}