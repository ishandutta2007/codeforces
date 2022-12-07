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
        cout << 2 << '\n';
        vector <bool> d(n + 1, false);
        for(int i = 1; i <= n; i++) {
            int j = i;
            while(!d[j]) {
                d[j] = true;
                cout << j << " ";
                j *= 2;
                if(j > n) break;
            }
        }
        cout << '\n';
    }
    
    return 0;
}