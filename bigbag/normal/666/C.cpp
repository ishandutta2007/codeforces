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

const int max_n = 111111, mod = 1000000007;

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int k, t, f[max_n], rf[max_n], pw[2][max_n], rpw[max_n], ans[max_n], a[max_n];
vector<int> n[max_n], num[max_n];
char s[max_n];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * f[i - 1] * i) % mod;
        rf[i] = power(f[i], mod - 2, mod);
    }
}

int get_c(int n, int k) {
    int res = (1LL * f[n] * rf[k]) % mod;
    res = (1LL * res * rf[n - k]) % mod;
    return res;
}

/*int solve(int n, int k) {
    if (k > n) {
        return 0;
    }
    int res = 0;
    for (int i = n; i >= k; --i) {
        int x = (1LL * get_c(i - 1, k - 1) * pw[0][i - k]) % mod;
        x = (1LL * x * pw[1][n - i]) % mod;
        res += x;
        res %= mod;
    }
    return res;
}*/

const int N = 100001;

int solve2(int n, int k) {
    if (k > n) {
        return 0;
    }
    return (1LL * a[n] * rpw[N - n]) % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    for (int q = 0; q < 2; ++q) {
        pw[q][0] = 1;
        for (int i = 1; i < max_n; ++i) {
            pw[q][i] = (1LL * pw[q][i - 1] * (25 + q)) % mod;
            rpw[i] = power(pw[q][i], mod - 2, mod);
        }
    }
    scanf("%d", &t);
    scanf("%s", s);
    k = strlen(s);
    for (int i = 0; i < t; ++i) {
        int tp, N;
        scanf("%d", &tp);
        if (tp == 1) {
            scanf("%s", s);
            k = strlen(s);
        } else {
            scanf("%d", &N);
            n[k].push_back(N);
            num[k].push_back(i);
        }
    }
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < max_n; ++i) {
        if (n[i].size()) {
            int res = 0;
            k = i;
            for (int j = k; j <= N; ++j) {
                int x = (1LL * get_c(j - 1, k - 1) * pw[0][j - k]) % mod;
                x = (1LL * x * pw[1][N - j]) % mod;
                res += x;
                res %= mod;
                a[j] = res;
            }
            for (int j = 0; j < n[i].size(); ++j) {
                ans[num[i][j]] = solve2(n[i][j], i);
            }
        }
    }
    for (int i = 0; i < t; ++i) {
        if (ans[i] != -1) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}