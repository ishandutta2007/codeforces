#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
#define double long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long k, d, t; cin >> k >> d >> t;
    long long x = (k + d - 1) / d;
    d *= x;

    assert(d >= k);

    double b = 0, e = 3e18;
    for (int it = 0; it < 100; ++it) {
        double m = (b + e) / 2;

        double tm = 0;
        double make_each_d = 1.0 * k / t + 1.0 * (d - k) / 2 / t;
        
        double ds = m / d;
        double fds = floor(ds);
        double make = make_each_d * fds;
        ds -= fds;

        ds *= d;
        if (ds < k) {
            make += ds / t;
        } else {
            make += 1.0 * k / t + (ds - k) / 2 / t;
        }

        if (make > 1) {
            e = m;
        } else {
            b = m;
        }
    }
    cout << fixed << setprecision(20) << (b + e) / 2 << endl;

    
    return 0;
}