//#include <bits/stdc++.h>
#include <cstdio>
#include <set>
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

const int max_N = 2510;
using ll = long long;

struct P {
    ll x, y;
}p[max_N];

int n;

ll dot(const P &a, const P &b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }
    ll ans = 1ll * n * (n - 1) * (n - 2) * (n - 3) / 6;
    for (int i = 0; i < n; ++i) {
        std::vector<P> vec;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            vec.push_back({p[j].x - p[i].x, p[j].y - p[i].y});
        }
        std::sort(vec.begin(), vec.end(), [](const P &a, const P &b) {
            int ad = (a.y ? a.y : a.x) > 0;
            int bd = (b.y ? b.y : b.x) > 0;
            return ad == bd ? dot(a, b) > 0 : ad > bd;
        });
        for (int j = 0, k = 0; j < n - 1; ++j) {
            for (; k < j + n - 1 && dot(vec[j], vec[k % (n - 1)]) >= 0; ++k);
            ans -= 1ll * (k - j - 1) * (k - j - 2) / 2;
        }
    }
    printf("%lld\n", ans * (n - 4) / 2);
    return 0;
}