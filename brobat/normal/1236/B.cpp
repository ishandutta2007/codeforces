#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n, m, ans;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1; // Shifts each bit right by 1. b = 10110, b>>1 = 01011, b>>2 = 00101, b>>3 = 00010, etc.
    }   
    return res%MOD;
}

void solve() {
    cin >> n >> m;
    ans = binpow(2, m);
    ans -= 1;
    ans %= MOD;
    ans = binpow(ans, n);
    cout << ans%MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}