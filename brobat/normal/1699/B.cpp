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
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i % 4 == 0 || i % 4 == 3) {
                    if(j % 4 == 0 || j % 4 == 3) {
                        cout << 1 << " ";
                    } else {
                        cout << 0 << " ";
                    }
                } else {
                    if(j % 4 == 0 || j % 4 == 3) {
                        cout << 0 << " ";
                    } else {
                        cout << 1 << " ";
                    }
                }
            }
            cout << '\n';
        }
    }
    
    return 0;
}