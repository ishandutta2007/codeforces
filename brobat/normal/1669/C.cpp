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
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        bool pos = true;
        for(int i = 2; i < n; i += 2) {
            if((v[i] % 2) != (v[i - 2] % 2)) pos = false;
        }
        for(int i = 3; i < n; i += 2) {
            if((v[i] % 2) != (v[i - 2] % 2)) pos = false;
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}