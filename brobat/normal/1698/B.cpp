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
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            if(v[i] > v[i - 1] + v[i + 1]) {
                ans++;
            }
        }
        cout << (k == 1 ? (n - 1)/2 : ans) << '\n';
    }
    
    return 0;
}