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
        bool pos = true;
        if(n % 3 == 2) pos = false;
        else 
        for(int i = 1; i < n; i += 3) {
            if(s[i] != s[i + 1]) pos = false;
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
}