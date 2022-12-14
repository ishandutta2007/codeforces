#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k;

ll q(ll x) {
    printf("? %lld\n", x);
    fflush(stdout);
    scanf("%lld", &x);
    return x;
}

int main() {
    scanf("%lld%lld", &n, &k);
    if (n <= 100) {
        for (int i = 0; i < n * 2; i++) {
            q(1);
        }
        for (int i = 1; i <= n; i++) {
            if (q(i) == k && q(i % n + 1) > k) return !printf("! %d\n", i);
        }
    }
    q(1);
    int s = 1;
    for (int t = 1; ; t++) {
        if (s + t > n) {
            for (int i = n; ; i--) {
                if (q(i) == k) {
                    return !printf("! %d\n", i);
                }
            }
            break;
        }
        if (q(s + t) > k) {
            for (int i = s + t - 1; ; i--) {
                if (q(i) == k) {
                    return !printf("! %d\n", i);
                }
            }
            break;
        }
        s += t;
    }
}