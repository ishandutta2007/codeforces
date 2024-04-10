#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        vector <int> a(n);
        // vector <int> v;
        multiset <int> ms;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            ms.insert(a[i] % k);
            // v.push_back(a[i] % k);
            ans += a[i] / k;
        }
        // sort(v.begin(), v.end());
        while(!ms.empty()) {
            auto yit = (--ms.end());
            int y = *yit;
            ms.erase(yit);
            auto xit = ms.lower_bound(k - y);
            if(xit == ms.end()) {
                break;
            } else {
                ms.erase(xit);
                ans++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}