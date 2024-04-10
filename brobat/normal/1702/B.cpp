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
        int days = 1;
        set <char> curr;
        for(int i = 0; i < n; i++) {
            curr.insert(s[i]);
            if((int)curr.size() > 3) {
                curr.clear();
                days++;
                curr.insert(s[i]);
            }
        }
        cout << days << '\n';
    }
    
    return 0;
}