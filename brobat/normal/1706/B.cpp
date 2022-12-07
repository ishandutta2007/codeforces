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
        vector <vector<int>> v(n);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            --x;
            if(v[x].empty()) {
                v[x].push_back(i);
            } else {
                if(i % 2 != v[x].back() % 2) {
                    v[x].push_back(i);
                }
            }
        }
        for(int i = 0; i < n; i++) cout << (int)v[i].size() << " ";
        cout << '\n';
    }
    
    return 0;
}