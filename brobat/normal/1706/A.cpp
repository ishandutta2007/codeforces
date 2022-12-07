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
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            --v[i];
        }
        vector <char> s(m, 'B');
        for(int i = 0; i < n; i++) {
            int x = min(v[i], m - 1 - v[i]);
            int y = max(v[i], m - 1 - v[i]);
            if(s[x] == 'A') {
                s[y] = 'A';
            } else {
                s[x] = 'A';
            }
        }
        for(auto i : s) cout << i;
        cout << '\n';
    }
    
    return 0;
}