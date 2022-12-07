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
        for(int i = 0; i < n - 1; i++) {
            if(v[i] <= 0) {
                break;
            }
            v[i + 1] += v[i];
            v[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            if(v[i] != 0) pos = false;
        }
        cout << (pos ? "Yes" : "No") << '\n';

    }
    
    return 0;
}