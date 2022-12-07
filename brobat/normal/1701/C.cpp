#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <int> cnt(n, 0);
        for(int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cnt[x - 1]++;
        }
        int left = 0;
        int right = 2*m;
        int ans = -1;
        while(left <= right) {
            int mid = (left + right)/2;
            vector <int> v(n, mid);
            int rem = m;
            int can = 0;
            for(int i = 0; i < n; i++) {
                int c = min(v[i], cnt[i]);
                rem -= c;
                v[i] -= c;
                can += v[i]/2;
            }
            if(can >= rem) {
                // can be done.
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}