#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        char x;
        cin >> x;
        bool pos = false;
        for(int i = 0; i < (int)s.length(); i++) {
            if(s[i] == x) {
                if(i % 2 == 0 && ((int)s.length() - i) % 2 == 1) {
                    pos = true;
                }
            }
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}