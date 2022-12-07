#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(n == 1 && m == 1) cout << 0 << '\n';
        else cout << n + m - 2 + min(n, m) << '\n';
    }
    
    return 0;
}