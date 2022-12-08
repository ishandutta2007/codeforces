#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inv2 = (mod + 1) / 2;
int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod);
    return ans;
}
int pwinv2[1000010];
int ans[1000010];
int delta[1000010];
int n;
void Add(int &x, int y) { if ((x += y) >= mod) x -= mod; }
void rmain() {
    scanf("%d", &n);
    pwinv2[0] = 1;
    for (int i = 1; i <= n; i++) delta[i] = 0, pwinv2[i] = 1ll * pwinv2[i - 1] * inv2 % mod;
    for (int i = n, s = 0; i > 0; i--) {
        Add(s, delta[i]);
        int l = i / 2, cur = pwinv2[i - l - (i == n)];
        // cerr << i << ' ' << cur << ' ' << s << endl;
        cur = 1ll * cur * (mod + 1 - s) % mod;
        Add(delta[l], cur);
        ans[i] = cur;
    }
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}