#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int r = 0;
        int w = 0;
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            r = max(r, x);
            w = max(w, y);
        }
        if(r + w > n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for(int i = 0; i < r; i++) cout << "R";
            for(int i = 0; i < w; i++) cout << "W";
            for(int i = 0; i < n - (r + w); i++) cout << "R";
            cout << '\n';
        }
    }
    
    return 0;
}