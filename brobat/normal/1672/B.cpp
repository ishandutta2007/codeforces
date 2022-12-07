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
        int n = s.length();
        if(s[n - 1] == 'A') {
            cout << "NO\n";
            continue;
        }
        int cnt = 0;
        bool pos = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'A') cnt++;
            else cnt--;
            if(cnt < 0) pos = false;
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}