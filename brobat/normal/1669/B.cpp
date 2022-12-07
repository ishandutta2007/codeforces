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
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m[x]++;
        }
        bool pos = false;
        for(auto i : m) {
            if(i.second >= 3) {
                cout << i.first << '\n';
                pos = true;
                break;
            }
        }
        if(!pos) cout << -1 << '\n';
    }
    
    return 0;
}