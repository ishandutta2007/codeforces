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
        int o = 0;
        int e = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x % 2) o++;
            else e++;
        }
        cout << min(o, e) << '\n';
    }
    
    return 0;
}