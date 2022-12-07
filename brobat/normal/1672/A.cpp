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
        int x = 0;
        for(int i = 0; i < n; i++) {
            int y; cin >> y;
            x += y - 1;
        }
        cout << (x%2 ? "errorgorn" : "maomao90") << '\n';
    }
    
    return 0;
}