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
        int ans = 0;
        bool pos = true;
        for(int i = n - 2; i >= 0; i--) {
            int x = 0;
            if(!pos) break;
            while(v[i] >= v[i + 1]) {
                v[i] /= 2;
                ans++;
                x++;
                if(x > 32) {
                    pos = false;
                    break;
                }
            }
        }
        cout << (pos ? ans : -1) << '\n';
    }
    
    return 0;
}