#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n;
long long p, q, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    while (n--) {
        scanf("%I64d%I64d%I64d", &p, &q, &b);
        while (true) {
            long long g = __gcd(q, b);
            if (g == 1) {
                break;
            }
            while (q % g == 0) {
                q /= g;
            }
        }
        if (p % q == 0) {
            puts("Finite");
        } else {
            puts("Infinite");
        }
    }
    return 0;
}