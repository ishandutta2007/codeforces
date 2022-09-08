#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, mod = 1000000009;

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int n, a, b, k, x;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%s", &n, &a, &b, &k, s);
    int cura = power(a, n, mod), curb = 1;
    int reva = power(a, mod - 2, mod);
    for (int i = 0; i < k; ++i) {
        int y = mul(cura, curb);
        if (s[i] == '-') {
            y = (mod - y) % mod;
        }
        x += y;
        x %= mod;
        cura = mul(cura, reva);
        curb = mul(curb, b);
    }
    int A = power(reva, k, mod);
    int B = power(b, k, mod);
    int C = mul(A, B);
    int m = (n + 1) / k;
    int coef;
    if (C == 1) {
        coef = m;
    } else {
        coef = (power(C, m, mod) + mod - 1) % mod;
        coef = mul(coef, power((C + mod - 1) % mod, mod - 2, mod));
    }
    printf("%d\n", mul(x, coef));
    return 0;
}