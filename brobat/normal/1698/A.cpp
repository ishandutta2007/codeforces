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
        for(int i = 0; i < n; i++) {
            int x = v[i];
            int y = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                y ^= v[j];
            }
            if(x == y) {
                cout << x << '\n';
                break;
            }
        }
    }
    
    return 0;
}