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
        int a = (int)(s[0] - '0') + (int)(s[1] - '0') + (int)(s[2] - '0');
        int b = (int)(s[3] - '0') + (int)(s[4] - '0') + (int)(s[5] - '0');
        cout << (a==b ? "YES\n" : "NO\n");
    }
    
    return 0;
}