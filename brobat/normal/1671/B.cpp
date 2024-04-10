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
        int curr = v[0];
        for(int i = 0; i < n; i++) {
            if(v[i] - 1 == curr + 1 || v[i] == curr + 1 || v[i] + 1 == curr + 1) {
                curr++;
            } else {
                pos = false;
            }
        }
        cout << (pos ? "YES" : "NO") << '\n'; 
    }
    
    return 0;
}