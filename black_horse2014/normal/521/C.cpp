#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

#define N 100005
#define MOD 1000000007

char s[N];
int f[N], g[N], rev[N], a[N], pw[N];

int C(int n, int m) {
    if (n < m || m < 0) return 0;
    return 1LL * f[n] * g[m] % MOD * g[n - m] % MOD;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    
    int n, i, j, k, ans;
    scanf("%d%d", &n, &k);
    gets(s);
    gets(s);
    for (rev[1] = 1, i = 2; i < N; i++) {
        rev[i] = -1LL * rev[MOD % i] * (MOD / i) % MOD;
        if (rev[i] < 0) rev[i] += MOD;
    }
    for (f[0] = g[0] = i = 1; i < N; i++) f[i] = 1LL * f[i - 1] * i % MOD, g[i] = 1LL * g[i - 1] * rev[i] % MOD;
    for (pw[0] = i = 1; i < N; i++) pw[i] = 1LL * pw[i - 1] * 10 % MOD;
    if (k == 0) {
        for (ans = i = 0; i < n; i++) {
            ans += 1LL * (s[i] - '0') * pw[n - i - 1] % MOD;
            ans %= MOD;
        }
        printf("%d\n", ans);
        return 0;
    }
    a[0] = C(n - 2, k - 1);
    for (i = 1; i < n; i++) {
        a[i] = a[i - 1] + 1LL * C(n - i - 2, k - 1) * pw[i] % MOD;
        a[i] %= MOD;
    }
    for (ans = i = 0; i < n; i++) {
        if (i < n - 1) ans += 1LL * a[n - i - 2] * (s[i] - '0') % MOD;
        ans %= MOD;
        ans += 1LL * C(i, k) * pw[n - i - 1] % MOD * (s[i] - '0') % MOD;
        ans %= MOD;
    }
    printf("%d\n", ans);
    return 0;
}