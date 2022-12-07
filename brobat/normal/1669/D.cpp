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
        string s;
        cin >> s;
        s += 'W';
        bool pos = true;
        int r = 0;
        int b = 0;
        for(int i = 0; i <= n; i++) {
            if(s[i] == 'W') {
                if(r == 0 && b == 0) continue;
                if(r == 0) pos = false;
                if(b == 0) pos = false;
                r = 0;
                b = 0;
            } else {
                (s[i] == 'R' ? r++ : b++);
            }
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}