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
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a == b) {
            cout << "YES" << '\n';
            continue;
        }
        bool pos = true;
        for(int i = 0; i < m - 1; i++) {
            if(a[i] != b[i]) {
                cout << "NO" << '\n';
                pos = false;
                break;
            }
        }
        if(!pos) continue;
        pos = false;
        for(int i = m - 1; i < n; i++) {
            if(a[i] == b[m - 1]) pos = true;
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}