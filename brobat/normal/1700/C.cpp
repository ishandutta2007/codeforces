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
        int ops = 0;
        int sub = 0;
        for(int i = 1; i < n; i++) {
            v[i] -= sub;
            if(v[i - 1] >= v[i]) {
                ops += (v[i - 1] - v[i]);            
            } else {
                sub += (v[i] - v[i - 1]);
            }
            v[i] = min(v[i], v[i - 1]);
        }
        cout << ops + sub + abs(*min_element(v.begin(), v.end())) << '\n';
    }
    
    return 0;
}