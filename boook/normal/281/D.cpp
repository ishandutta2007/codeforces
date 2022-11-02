#include <bits/stdc++.h>
using namespace std;
#define maxn 100009

int n, x[maxn], l[maxn], r[maxn];

int L(int now, int val) { return x[now] > val ? now : L(l[now], val); }
int R(int now, int val) { return x[now] > val ? now : R(r[now], val); }

int main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> x[i];

    x[0] = x[n + 1] = 2e9;
    for (int i = 1; i <= n; ++ i)
        l[i] = L(i - 1, x[i]);
    for (int i = n; i >= 1; -- i)
        r[i] = R(i + 1, x[i]);

    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        if (l[i] >= 1) ans = max(ans, x[i] ^ x[l[i]]);
        if (r[i] <= n) ans = max(ans, x[i] ^ x[r[i]]);
    }
    cout << ans << "\n";
    return 0;
}