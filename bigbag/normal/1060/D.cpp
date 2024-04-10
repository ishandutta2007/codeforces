#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, l[max_n], r[max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    ans = n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        ans += l[i];
        ans += r[i];
    }
    sort(l, l + n);
    sort(r, r + n);
    for (int i = 0; i < n; ++i) {
        ans -= min(l[i], r[i]);
    }
    cout << ans << "\n";
    return 0;
}