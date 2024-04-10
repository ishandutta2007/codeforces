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

int n, k;
long long ans, f[max_n], rf[max_n];
string s;

long long power(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power((a * a) % mod, b / 2);
    }
    return (power(a, b - 1) * a) % mod;
}

long long get_c(long long n, long long k) {
    if (n < k) {
        return 0;
    }
    return (((f[n] * rf[k]) % mod) * rf[n - k]) % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> s;
    f[0] = 1;
    rf[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (f[i - 1] * i) % mod;
        rf[i] = power(f[i], mod - 2);
    }
    long long q = 0, pw = 1;
    for (int i = n - 1; i >= 0; --i) {
        ans += (s[i] - '0') * (q + pw * get_c(i, k));
        ans %= mod;
        //cout << q << "  ";
        q = q + pw * get_c(i - 1, k - 1);
        q %= mod;
        pw *= 10;
        pw %= mod;
    }
    cout << ans << endl;
    return 0;
}