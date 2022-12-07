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
        int x = a*d;
        int y = b*c;
        if(x == y) cout << 0 << '\n';
        else {
            if(a == 0 || c == 0) cout << 1 << '\n';
            else if((x/y)*y == x || (y/x)*x == y) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }
    
    return 0;
}