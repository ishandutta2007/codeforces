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
        set <int> s;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        int r = n - (int)s.size();
        if(r % 2) r++;
        cout << n - r << '\n';
    }
    
    return 0;
}