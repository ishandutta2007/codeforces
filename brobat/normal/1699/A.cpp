#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 2 == 1) cout << -1 << '\n';
        else cout << 0 << " " << 0 << " " << n/2 << '\n';
    }
    
    return 0;
}