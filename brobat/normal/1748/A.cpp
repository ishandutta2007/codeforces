#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << setprecision(15) << int(ceil(n*1.0/2)) << '\n';
    }
    
    return 0;
}