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
        string s, t;
        cin >> s >> t;
        string a, b;
        for(int i = 0; i < n; i++) {
            if(s[i] != 'b') a += s[i];
            if(t[i] != 'b') b += t[i];
        }
        if(a != b) {
            cout << "NO" << '\n';
            continue;
        }
        int bs = 0;
        int bt = 0;
        int j = 0;
        bool pos = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'b') {
                bs++;
            } else {
                while(t[j] != s[i]) {
                    bt++;
                    j++;
                }
                if(s[i] == 'a') {
                    if(bs > bt) {
                        pos = false;
                        break;
                    }
                } else {
                    if(bs < bt) {
                        pos = false;
                        break;
                    }
                }   
                j++;
            }
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}