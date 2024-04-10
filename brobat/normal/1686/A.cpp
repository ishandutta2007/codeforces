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
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        bool pos = false;
        for(int i = 0; i < n; i++) {
            if((sum - v[i]) % (n - 1) == 0) {
                if((sum - v[i]) / (n - 1) == v[i]) {
                    pos = true;
                }
            }
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}