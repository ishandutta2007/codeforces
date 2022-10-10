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

int k;
ve<long> a;
void read() {
    scanf("%d", &k);
    a.resize(k);
    for (int i = 0; i < k; ++i) scanf("%d", &a[i]);
    partial_sum(a.begin(), a.end(), a.begin());
}

const long mod = 1e9 + 7;

struct fac {
    ve<long> dd;
    fac() : dd(1, 1) {}

    long operator[](int i) {
        while (sz(dd) <= i) dd.push_back((dd.back() * sz(dd)) % mod);
        return dd[i];
    }
} fac;

long mpow(long base, long m) {
    long ans = 1;
    for (; m > 0; m >>= 1) {
        if (m & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
    }
    return ans;
}

struct rfac {
    ve<long> dd;
    rfac() {}
    long operator[] (int i) {
        while (sz(dd) <= i) dd.push_back(mpow(fac[sz(dd)], mod - 2));
        return dd[i];
    }
} rfac;

long c(long k, long n) { return ((fac[n] * rfac[k]) % mod * rfac[n - k]) % mod; }

long process() {
    long dp[2] = {1, 1};
    for (int i = 1; i < k; ++i) {
        long t = c(a[i - 1], a[i] - 1);
        dp[i & 1] = (dp[~i & 1] * t) % mod;
    }
    return dp[~k & 1];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    cout << process();

    return 0;
}