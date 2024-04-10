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
        auto CHECK = [&](int l, int r) -> bool {
            // does the answer lie in [l, r] or not?
            cout << "? " << l + 1 << " " << r + 1 << endl;
            int x = 0;
            for(int i = 0; i < r - l + 1; i++) {
                int y;
                cin >> y;
                --y;
                if(y >= l && y <= r) x++;
            }
            return (x % 2 ? true : false);
        };
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while(l <= r) {
            int mid = (l + r)/2;
            if(CHECK(l, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << "! " << ans + 1 << endl;
    }
    
    return 0;
}