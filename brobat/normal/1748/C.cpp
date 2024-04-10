#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector <int> p(n);
        p[0] = v[0];
        for(int i = 1; i < n; i++) {
            p[i] = v[i] + p[i - 1];
        }
        int ans = 0;
        int prev = n;
        map<int, int> cnt;
        for(int i = n - 1; i >= 0; i--) {
            cnt[p[i]]++;
            if(v[i] == 0) {
                int mx = 0;
                for(auto i : cnt) mx = max(mx, i.second);
                ans += mx;
                prev = i;
                cnt.clear();
            }
        }
        cout << ans + cnt[0] << '\n';
    }
    
    return 0;
}