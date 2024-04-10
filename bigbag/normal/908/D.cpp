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

const int max_n = 2111, inf = 1011111111;
const int mod = 1000000007;

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int divmod(int a, int b) {
    return (1LL * a * power(b, mod - 2, mod)) % mod;
}

int k, pa, pb, p, q;
int dp[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> pa >> pb;
    p = divmod(pa, pa + pb);
    q = divmod(pb, pa + pb);
    int p1 = (p + mod - 1) % mod;
    int q1 = p;
    for (int cnt = 0; cnt < max_n; ++cnt) {
        if (cnt >= k) {
            dp[k][cnt] = cnt;
        } else {
            dp[k][cnt] = (1LL * divmod(divmod(p, p1), p1) * q) % mod;
            dp[k][cnt] += cnt + k;
            dp[k][cnt] %= mod;
        }
    }
    for (int a = k - 1; a >= 1; --a) {
        for (int cnt = max_n - 1; cnt >= 0; --cnt) {
            if (cnt >= k) {
                dp[a][cnt] = cnt;
            } else {
                dp[a][cnt] = (1LL * p * dp[a + 1][cnt]) % mod;
                dp[a][cnt] += (1LL * q * dp[a][cnt + a]) % mod;
                dp[a][cnt] %= mod;
            }
        }
    }

    cout << (1LL * p * divmod(dp[1][0], q1 % mod)) % mod << endl;
    return 0;
}