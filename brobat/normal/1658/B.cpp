#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int MAXN = 1005;
    int fact[MAXN];
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 2) cout << 0 << endl;
        else cout << (fact[n/2] * fact[n/2] % MOD) << endl;
    }
    
    return 0;
}