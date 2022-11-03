#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const int max_primes = 11;
const int primes[max_primes] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
const int max_n = 1e3 + 100;

int n;
double dp[max_primes][max_n];
int f[max_primes][max_n];
int pr[max_primes][max_n];

double go(int cp, int n) {
    if (f[cp][n])
        return dp[cp][n];
    f[cp][n] = true;
    if (n == 1) {
        dp[cp][n] = 0.0;
        pr[cp][n] = 0;
        return 0.0;
    }
    dp[cp][n] = log(primes[cp]) * (n - 1);
    pr[cp][n] = n - 1;
    for (int i = n - 1; i > 1; --i)
        if (n % i == 0) {
            double r = log(primes[cp]) * (i - 1);
            r += go(cp + 1, n / i);
            if (r < dp[cp][n]) {
                dp[cp][n] = r;
                pr[cp][n] = i - 1;
            }
        }
    return dp[cp][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    go(0, n);
    ll res = 1;
    for (int cp = 0; n > 1; ++cp) {
        for (int i = 0; i < pr[cp][n]; ++i)
            res *= primes[cp];
        n /= pr[cp][n] + 1;
    }
    cout << res << endl;
    return 0;
}