#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t; cin >> t;
    while (t--) {
        long long p, q, b;
        cin >> p >> q >> b;
        long long gc = gcd(p, q);
        p /= gc; q /= gc;

        bool bad = false;
        while (q != 1) {
            long long gc = gcd(q, b);
            if (gc == 1) {
                bad = true;
                break;
            }
            while (q % gc == 0)
                q /= gc;
        }

        if (bad) {
            cout << "Infinite\n";
        } else {
            cout << "Finite\n";
        }
        
    }

    return 0;
}