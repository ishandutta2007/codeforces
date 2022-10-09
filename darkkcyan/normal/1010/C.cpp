#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define maxn 101010
llong n, k;
bool ans[maxn] = {0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    llong m = k;
    for (llong i = n; i--; ) {
        llong u; cin >> u;
        u = __gcd(u, k);
        m = __gcd(m, u);
    }
    int cnt = 0;
    for (llong t = 0; !ans[t]; (t += m) %= k, ++cnt) ans[t] = 1;
    cout << cnt << '\n';
    for (int i = 0; i < k; ++i) 
        if (ans[i]) cout << i << ' ';
    return 0;
}