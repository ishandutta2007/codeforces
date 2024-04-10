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
        vector <int> v(n);
        set<int> s;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] > 0) s.insert(i);
        }
        int ans = 0;
        bool found = false;
        for(int i = 0; i < n - 1; i++) {
            if(v[i] > 0) found = true;
            if(found && v[i] == 0) ans++;
            ans += v[i];
        }
        cout << ans << '\n';
    }
    
    return 0;
}