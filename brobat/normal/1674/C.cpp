#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = (int)1E18;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        string t;
        cin >> s >> t;
        int n = (int)s.length();
        bool c = false;
        for(auto x : t) if(x == 'a') c = true;
        if(c && (int)t.length() > 1) cout << -1 << '\n';
        else {
            if(c) cout << 1 << '\n';
            else cout << binpow(2, n) << '\n';
        }
    }
    
    return 0;
}