#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int l, r, x;
        cin >> l >> r >> x;
        int a, b;
        cin >> a >> b;
        if(a == b) {
            cout << 0 << '\n';
            continue;
        }
        if(a > b) swap(a, b);
        if(b - a >= x) {
            cout << 1 << '\n';
            continue;
        }
        if(max(a - l, r - b) >= x) {
            cout << 2 << '\n';
        } else if(min(b - l, r - a) >= x) {
            cout << 3 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    
    return 0;
}