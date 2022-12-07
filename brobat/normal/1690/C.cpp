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
        vector <int> s(n), f(n);
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> f[i];
        }
        int curr = 0;
        for(int i = 0; i < n; i++) {
            cout << min(f[i] - s[i], f[i] - curr) << " ";
            curr = f[i];
        }
        cout << '\n';
    }
    
    return 0;
}