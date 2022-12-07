#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int l, r, a;
        cin >> l >> r >> a;
        if(l/a == r/a) {
            cout << r/a + r%a << endl;
        } else if(r % a == a - 1) {
            cout << r/a + r%a << endl;
        } else {
            cout << (r - a)/a + (a - 1) << endl;
        }
    }
    
    return 0;
}