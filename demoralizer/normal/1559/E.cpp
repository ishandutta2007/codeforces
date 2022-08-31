#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define loopr(i, a, b) for (int i = (int)a; i >= (int)b; --i)
#define count_1(n) __builtin_popcountll(n)
#define pb push_back
#define pc putchar
#define gc getchar
#define itoc(c) ((char)(((int)'0') + c))
#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)
#define mid(s, e) (s + (e - s) / 2)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
const int MOD = 998244353;

int modpow(int a, int b, int mod) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a;
        res %= mod;
        a = a * a;
        a %= mod;
    }
    return res;
}
int po(int a, int b) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a;
        a = a * a;
    }
    return res;
}

int dp[50][100001];

int solve(int n, int m, vvi a, int div) {}
std::chrono::steady_clock::time_point endt;

template <int N = 100'000>
struct MU {
    vector<int> primes, mu;
    vector<char> is_prime;
    vector<int> sqfree;
    MU() {
        is_prime.assign(N + 1, true);
        is_prime[0] = is_prime[1] = false;
        mu.resize(N + 1);
        mu[1] = 1;
        for (int i = 2; i <= N; ++i) {
            if (is_prime[i]) mu[i] = -1, primes.push_back(i);
            for (int j = 0; j < primes.size() && i * primes[j] <= N; ++j) {
                is_prime[i * primes[j]] = false;
                if (i % primes[j] == 0) {
                    mu[i * primes[j]] = 0;
                    break;
                } else {
                    mu[i * primes[j]] = -mu[i];
                }
            }
        }
        // special case
        sqfree.push_back(1);
        for (int i = 2; i <= N; ++i)
            if (mu[i]) sqfree.push_back(i);
    }
};

MU mu;

void testcases(int test) {
    int n, mm;
    cin >> n >> mm;
    vector<array<int, 2>> aa(n);
    loop(i, 0, n) cin >> aa[i][0] >> aa[i][1];
    vector<long long int> num(mm + 1);
    for (auto div : mu.sqfree) {
        int m = mm / div;
        if (m == 0) break;
        vector<array<int, 2>> a = aa;
        loop(i, 0, n) {
            a[i][1] /= div;
            a[i][0] = (a[i][0] + div - 1) / div;
            a[i][1] -= a[i][0];
            m -= a[i][0];
        }
        if (m < 0) continue;
        loop(i, 0, a[0][1] + 1) dp[0][i] = 1;
        loop(i, 1, n) {
            loop(j, 1, m + 1) {
                dp[i - 1][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
                if (dp[i - 1][j] >= MOD) dp[i - 1][j] -= MOD;
            }
            loop(j, 0, m + 1) {
                int r = (j - a[i][1] >= 1) ? dp[i][j - a[i][1] - 1] : 0;
                dp[i][j] = (dp[i - 1][j] - r + MOD);
                if (dp[i][j] >= MOD) dp[i][j] -= MOD;
                if (i == n - 1) {
                    num[div] = (num[div] + dp[n - 1][j]);
                    if (num[div] >= MOD) num[div] -= MOD;
                }
            }
        }
    }
    loopr(i, mm, 1) {
        for (int j = 2 * i; j <= mm; j += i) {
            num[i] = (num[i] - num[j] + MOD);
            if (num[i] >= MOD) num[i] -= MOD;
        }
    }
    cout << num[1] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    loop(i, 0, t) testcases(i);
}