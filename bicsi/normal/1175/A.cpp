#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

long long Solve(long long n, long long k) {
    long long ans = 0;
    while (n) {
        long long rem = n % k;
        if (rem == 0) {
            n /= k;
            ans += 1;
        } else {
            n -= rem;
            ans += rem;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        long long n, k; cin >> n >> k;
        cout << Solve(n, k) << '\n';
    }

    return 0;
}