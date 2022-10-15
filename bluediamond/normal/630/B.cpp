#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ld bin(ld a, int b) {
    ld r = 1;
    while (b) {
        if (b & 1) {
            r = r * a;
        }
        a = a * a;
        b >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ld a;
    int t;
    cin >> a >> t;
    ld r = a * bin(1.000000011, t);
    cout << fixed << setprecision(6) << r << "\n";

    return 0;
}