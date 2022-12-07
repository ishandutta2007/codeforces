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
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = n % 2; i < n; i += 2) {
            if(v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                // cout << i << " " << v[i] << " " << v[i + 1] << '\n';
            }
        }
        cout << (is_sorted(v.begin(), v.end()) ? "YES" : "NO") << '\n';
    }
    
    return 0;
}