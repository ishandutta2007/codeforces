#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

long n, k;
const long mod = 1e9 + 7;

inline long mfix(long a) {
    if (a > mod) a %= mod;
    return a;
}

long mpow(long base, long m) {
    long ans = 1;
    for (; m > 0; m >>= 1) {
        if (m & 1) ans = mfix(ans * base);
        base = mfix(base * base);
    }
    return ans;
}

struct fac {
    ve<long> d, rd;
    fac() : d(1, 1), rd(1, 1) {}
    void get(int i) {
        while (sz(d) <= i)
            d.push_back(mfix(d.back() * sz(d))),
            rd.push_back(mpow(d.back(), mod - 2));
    }
    long operator[](int i) { get(i); return d[i]; }
    long inv(int i) { get(i); return rd[i]; }
} fac;

long c(long n, long k) {
    if (k > n) return 0;
    return mfix((fac[n] * fac.inv(k)) % mod * fac.inv(n - k));
}

ve<ve<long> > dp;
long process() {
    long ans = 0;
    dp.resize(k + 1, ve<long>(n + 1));
    dp[1].assign(n + 1, 1);
    for (long i = 1; i <= n; ++i) {
        for (long f = i * 2; f <= n; f += i) {
            for (int g = 1; g < k; ++g)
                dp[g + 1][f] = mfix(dp[g + 1][f] + dp[g][i]);
        }
    }

    for (int i = 1; i <= n; ++i)
    for (int f = 1; f <= k; ++f) {
        ans = mfix(ans + mfix(dp[f][i] * c(k - 1, f - 1)));
    }

    return ans;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> k;
    cout << process();

    return 0;
}