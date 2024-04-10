#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int x = 0;
        for(int i = 0; i < 4; i++) {
            int t;
            cin >> t;
            x += t;
        }
        cout << (x == 0 ? 0 : (x < 4 ? 1 : 2)) << '\n';
    }
    
    return 0;
}