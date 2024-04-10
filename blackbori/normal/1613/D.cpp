#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 998244353;

ll X[505050], Y[505050];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t, n, i, v, a, s;
    
    for (cin >> t; t--; ) {
        cin >> n;
        fill(X, X + n + 5, 0);
        fill(Y, Y + n + 5, 0);
        Y[(-1) + 2] = 1; s = 0;
        for (i = 1; i <= n; i++) {
            cin >> a;
            
            v = X[(a + 2) + 2];
            X[(a + 2) + 2] = (X[(a + 2) + 2] + v) % mod;
            s = (s + v) % mod;
            
            v = (X[(a) + 2] + Y[(a - 2) + 2]) % mod;
            X[(a) + 2] = (X[(a) + 2] + v) % mod;
            s = (s + v) % mod;
            
            v = (Y[(a) + 2] + Y[(a - 1) + 2]) % mod;
            Y[(a) + 2] = (Y[(a) + 2] + v) % mod;
            s = (s + v) % mod;
        }
        cout << s << "\n";
    }
    
    return 0;
}