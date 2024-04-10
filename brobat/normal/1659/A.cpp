#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, r, b;
        cin >> n >> r >> b;
        int x = ceil(r*1.0/(b + 1));
        int y = r % (b + 1);
        string s;
        for(int i = 0; i < y; i++) {
            for(int j = 0; j < x; j++) cout << "R";
            cout << "B";
        }
        int z = (b + 1) - y;
        for(int i = 0; i < z; i++) {
            for(int j = 0; j < (r/(b + 1)); j++) cout << "R";
            if(i != z - 1) cout << "B";
        }
        cout << '\n';
    }
    
    return 0;
}