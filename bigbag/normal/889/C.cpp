#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1000011, inf = 1011111111;

int fast_max(int n, int k, int a[]) {
    int ans = -1;
    int offset = 0;
    for (int i = 0; i < n; ++i)
        if (ans < a[i]) {
            ans = a[i];
            offset = 0;
        } else {
            offset = offset + 1;
            if (offset == k)
                return ans;
        }
    return ans;
}

int n;

int solve(int n, int k) {
    int p[n];
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    int res = 0;
    do {
        if (fast_max(n, k, p) == n - 1) {
            ++res;
        }
    } while (next_permutation(p, p + n));
    return res;
}

const int mod = 1000000007;

int a[max_n];

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int ok(int n, int k) {
    a[1] = 1;
    for (int i = 2; i <= k + 2; ++i) {
        a[i] = (1LL * a[i - 1] * i) % mod;
    }
    a[k + 2] += mod - a[k];
    a[k + 2] %= mod;
    int cur = 1;
    for (int j = k + 3 - k - 1; j <= k + 1; ++j) {
        cur = (1LL * cur * j) % mod;
    }
    for (int i = k + 3; i <= n; ++i) {
        a[i] = (1LL * i * a[i - 1]) % mod;
        int x = (1LL * a[i - k - 1] * cur) % mod;
        a[i] += mod - x;
        a[i] %= mod;
        cur = (1LL * cur * power(i - k - 1, mod - 2, mod)) % mod;
        cur = (1LL * cur * (i - 1)) % mod;
    }
    return a[n];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        res = (1LL * res * i) % mod;
    }
    res += mod - ok(n, k);
    res %= mod;
    cout << res << endl;
    return 0;
}