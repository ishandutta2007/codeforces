#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector <int> v;
    v.push_back(1);
    while(v.back() < (int)1E9) {
        v.push_back(v.back() * 10);
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = (int)1E18;
        for(auto i : v) {
            if(i <= n) ans = min(ans, n - i);
        }
        cout << ans << '\n';
    }
    
    return 0;
}