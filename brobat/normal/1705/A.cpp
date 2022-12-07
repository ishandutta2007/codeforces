#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector <int> v(2*n);
        for(int i = 0; i < 2*n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        bool pos = true;
        for(int i = 0; i < n; i++) {
            if(v[i] + x > v[i + n]) pos = false;
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}