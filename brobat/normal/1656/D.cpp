#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    int k = 0;
    while(n % 2 == 0) {
        n /= 2;
        k++;
    }
    if(n == 1) {
        cout << -1 << endl;
        return;
    }
    int x = 1ll<<(k + 1);
    if(x > n) {
        cout << n << endl;
    } else {
        cout << x << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}