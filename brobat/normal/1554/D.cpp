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
        for(int i = 0; i < (n/2) - 1; i++) {
            cout << 'a';
        }
        cout << 'b';
        for(int i = 0; i < (n/2); i++) {
            cout << 'a';
        }
        if(n % 2 && n > 1) cout << 'c';
        cout << '\n';
    }
    
    return 0;
}