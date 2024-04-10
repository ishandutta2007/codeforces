//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstring>

const int max_N = 250010;
using ll = long long;
int n, m;

int fact[max_N];

int main() {
    scanf("%d%d", &n, &m);

    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = 1ll * fact[i - 1] * i % m;

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll tmp = 1ll * (n - i + 1) * (n - i + 1) % m;
        tmp = 1ll * tmp * fact[i] % m;
        tmp = 1ll * tmp * fact[n - i] % m;
        ans = (ans + tmp) % m;
    }
    printf("%lld\n", ans);
}