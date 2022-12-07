#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if(y % x == 0) cout << 1 << " " << (y/x) << '\n'; 
        else cout << "0 0\n";
    } 
    
    return 0;
}