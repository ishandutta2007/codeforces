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
        bool rev = false;
        for(int i = n - 2; i >= 0; i--) {
            if(!rev) {
                if(v[i] < v[i + 1]) {
                    rev = true;
                }
            } else {
                if(v[i] > v[i + 1]) {
                    ans = i + 1;
                    break; 
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}