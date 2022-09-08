#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, x, y, cnt;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%s", &n, &x, &y, s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++cnt;
        }
        while (i + 1 < n && s[i] == s[i + 1]) {
            ++i;
        }
    }
    long long ans = min(1LL * cnt * y, 1LL * (cnt - 1) * x + y);
    if (cnt == 0) {
        ans = 0;
    }
    cout << ans << "\n";
    return 0;
}