#include <bits/stdc++.h>

using ll = long long;

int n;

ll calc(int x) {
    int k = (n - 1) / x;
    return 1ll * (k + 1) * (1ll * k * x + 2) / 2;
}

int main() {
    scanf("%d", &n);
    std::vector<ll> vec;
    for (int i = 1; i * i <= n; ++i) {
        if (!(n % i)) {
            vec.push_back(calc(i));
            if (i * i != n) {
                vec.push_back(calc(n / i));
            }
        }
    }
    std::sort(vec.begin(), vec.end());
    int m = (int)vec.size();
    for (int i = 0; i < m; ++i) {
        printf("%lld%c", vec[i], " \n"[i + 1 == m]);
    }
    return 0;
}