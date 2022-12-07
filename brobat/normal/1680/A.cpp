#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > c) {
            swap(a, c);
            swap(b, d);
        }
        if(c <= b) {
            cout << max(a, c) << '\n';
        } else {
            cout << a + c << '\n';
        }
    }
    
    return 0;
}