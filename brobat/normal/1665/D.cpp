#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int curr = 1;
        int ans = 0;
        for(int i = 1; i <= 30; i++) {
            int x = (1 << i);
            cout << "? " << curr << " " << curr + x << endl;
            int y;
            cin >> y;
            if(y < x) {
                curr += (x/2);
            } else {
                ans += x;
            }
        }
        cout << "! " << ans/2 << endl;
    }
    
    return 0;
}