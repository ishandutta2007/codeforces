#include <bits/stdc++.h>

using namespace std;

const int max_n = 303333, inf = 1000111222;

int n, a[max_n];
map<int, int> q[2];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        a[i] ^= a[i - 1];
        ++q[i % 2][a[i]];
    }
    for (int l = 1; l <= n; ++l) {
        --q[l % 2][a[l]];
        ans += q[(l % 2) ^ 1][a[l - 1]];
    }
    cout << ans << "\n";
    return 0;
}