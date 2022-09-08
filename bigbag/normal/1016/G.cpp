#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, max_p = 33333, inf = 1000111222;

int n, masks[max_p], all[max_p];
long long x, y, a[max_n];
vector<long long> p;

long long divide(long long x) {
    for (long long d : p) {
        while (x % d == 0) {
            x /= d;
        }
    }
    return x;
}

void factorize(long long y) {
    long long Y = y;
    for (int i = 2; i <= 1000000; ++i) {
        if (y % i == 0) {
            while (y % i == 0) {
                y /= i;
            }
            p.push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        long long x = divide(a[i]);
        long long g = __gcd(x, y);
        if (g > 1 && g != y) {
            p.push_back(g);
            if (g * g != y) {
                p.push_back(y / g);
            }
            return;
        }
    }
    /*for (int i = 0; i < n; ++i) {
        if (Y % a[i]) {
            continue;
        }
        long long cur = x;
        while (true) {
            long long lcm = (a[i] / __gcd(a[i], cur)) * cur;
            if (lcm == Y) {
                break;
            }
            cur *= Y / lcm;
        }
        cur = divide(cur / x);
        long long g = __gcd(cur, y);
        if (g > 1 && g != y) {
            p.push_back(g);
            if (g * g != y) {
                p.push_back(y / g);
            }
            return;
        }
    }*/
    if (y > 1) {
        p.push_back(y);
    }
}

int get_mask(long long x) {
    int mask = 0;
    for (int j = 0; j < p.size(); ++j) {
        if (x % p[j] == 0) {
            mask += 1 << j;
        }
    }
    return mask;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%I64d%I64d", &n, &x, &y);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    if (y % x) {
        puts("0");
        return 0;
    }
    factorize(y);
    for (int i = 0; i < n; ++i) {
        if (a[i] % x) {
            continue;
        }
        int mask = get_mask(a[i] / x);
        ++masks[((1 << p.size()) - 1) ^ mask];
    }
    for (int mask = max_p - 1; mask >= 0; --mask) {
        for (int submask = mask; submask > 0; submask = mask & (submask - 1)) {
            all[submask] += masks[mask];
        }
        all[0] += masks[mask];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (y % a[i]) {
            continue;
        }
        long long cur = x;
        while (true) {
            long long lcm = (a[i] / __gcd(a[i], cur)) * cur;
            if (lcm == y) {
                break;
            }
            cur *= y / lcm;
        }
        cur /= x;
        ans += all[get_mask(cur)];
    }
    printf("%I64d\n", ans);
    return 0;
}