#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    map<string, int> m;
    int x = 0;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(i == j) continue;
            string y;
            y += 'a' + i;
            y += 'a' + j;
            m[y] = (++x);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << m[s] << '\n';
    }
    
    return 0;
}