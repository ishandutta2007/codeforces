#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n], used[max_n], cnt[max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[a[i]]) {
            cnt[i] = 1;
            used[a[i]] = 1;
        }
        if (i) {
            cnt[i] += cnt[i - 1];
        }
    }
    memset(used, 0, sizeof(used));
    for (int i = n - 1; i > 0; --i) {
        if (!used[a[i]]) {
            used[a[i]] = 1;
            ans += cnt[i - 1];
        }
    }
    cout << ans << "\n";
    return 0;
}