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
            int x; cin >> x;
            m[x]++;
        }
        bool pos = true;
        for(auto i : m) {
            if(i.second == 1) pos = false;
        }
        if(!pos) {
            cout << -1 << '\n';
            continue;
        }
        int curr = 0;
        for(auto i : m) {
            int x = i.second;
            cout << curr + x << " ";
            for(int j = 1; j < i.second; j++) {
                cout << curr + j << " ";
            }
            curr += i.second;
        }
        cout << '\n';
    }
    
    return 0;
}