#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int x = 0;
        bool pos = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'A') x++;
            else x--;
            if(x < 0) pos = false;
        }
        cout << (pos ? "Yes" : "No") << '\n';
    }
    
    return 0;
}