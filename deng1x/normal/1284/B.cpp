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

const int max_N = 1000010;
using ll = long long;

int n;
std::vector<int> vec;

ll cnt[max_N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l;
        scanf("%d", &l);
        int tmp = INT_MAX;
        bool flag = false;
        std::pair<int, int> pr = {INT_MAX, INT_MIN};
        for (int j = 0; j < l; ++j) {
            int x;
            scanf("%d", &x);
            if (tmp < x) {
                flag = true;
            }
            tmp = std::min(tmp, x);
            pr.first = std::min(pr.first, x);
            pr.second = std::max(pr.second, x);
        }
        if (!flag) {
            ++cnt[pr.second];
            vec.push_back(pr.first);
        }
    }

    for (int i = max_N - 1; i >= 1; --i) {
        cnt[i - 1] += cnt[i];
    }

    ll ans = 0, tmp = 0;
    for (auto &v : vec) {
        ans += cnt[v + 1];
        tmp += 1;
    }

    printf("%lld\n", ans + 1ll * n * n - 1ll * tmp * tmp);
}