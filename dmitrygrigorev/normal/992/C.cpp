#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int fp(int a, int b) {
    if (b == 0) return 1;
    int t = fp(a, b / 2);
    if (b % 2 == 0) return mod(t * t);
    else return mod(mod(t * t) * a);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x, k;
    cin >> x >> k;

    if (x == 0) {
        cout << "0\n";
        return 0;
    }

    if (k == 0) cout << mod(2 * x) << '\n';
    else {
        int a = mod(2 * x - 1);
        cout << mod(2 * a * fp(2, k - 1) + 1) << '\n';
    }
    
    return 0;
}