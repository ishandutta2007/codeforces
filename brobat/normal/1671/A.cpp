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
        bool pos = true;
        // 1 not allowed.
        int n = (int)s.length();
        // if(n == 1) pos = false;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'b') continue;
            pos = false;
        }
        int cnt = 1;
        char curr = s[0];
        for(int i = 1; i < n; i++) {
            if(cnt == 1 && s[i] != curr) {
                pos = false;
            } else {
                if(s[i] == curr) cnt++;
                else {
                    cnt = 1;
                    curr = s[i];
                }
            }
        }
        if(cnt == 1) pos = false;
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}