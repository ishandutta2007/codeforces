#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
Let o(x) = x|x0 + x|x1 + x|x2 + x|x3 + ...
Let a(x) = X&x0 + x&x1 + x&x2 + x&x3 + ...
Then ans is o(x0)a(x0) + o(x1)a(x1) + .... 
*/

const int MOD = (int)1E9 + 7;


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        vector <int> sb(60, 0); // sb[i] --> number of set bits in position i.
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            for(int j = 0; j < 60; j++) {
                if((v[i] >> j) & 1) sb[j]++;
            }
        }
        vector <int> o(n, 0), a(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 60; j++) {
                int x = (1ll << j) % MOD * sb[j] % MOD;
                int y = (1ll << j) % MOD * n % MOD;
                if((v[i] >> j) & 1) {
                    o[i] = (o[i] + y) % MOD;
                    a[i] = (a[i] + x) % MOD;
                } else {
                    o[i] = (o[i] + x) % MOD;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + o[i] * a[i]) % MOD;
        }
        cout << ans << '\n';
    }
    
    return 0;
}