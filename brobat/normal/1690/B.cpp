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
        vector <int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int mx = -(int)1E18;
        for(int i = 0; i < n; i++) {
            mx = max(mx, a[i] - b[i]);
        }
        if(mx < 0) {
            cout << "NO\n";
            continue;
        }
        bool pos = true;
        for(int i = 0; i < n; i++) {
            a[i] = max(a[i] - mx, 0ll);
            if(a[i] != b[i]) pos = false;
        }
        cout << (pos ? "YES\n" : "NO\n");
        
    }
    
    return 0;
}