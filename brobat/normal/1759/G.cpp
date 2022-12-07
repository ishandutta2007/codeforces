#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set <int> left;
        for(int i = 1; i <= n; i++) {
            left.insert(i);
        }
        vector <int> p(n, -1);
        vector <int> b(n/2);
        bool pos = true;
        for(int i = 0; i < n/2; i++) {
            cin >> b[i];
            if(left.find(b[i]) == left.end()) {
                pos = false;
            } else {
                left.erase(b[i]);
            }
            p[2*i + 1] = b[i];
        }
        for(int i = n/2 - 1; i >= 0; i--) {
            if(!pos) break;
            auto it = left.lower_bound(b[i]);
            if(it == left.begin()) {
                pos = false;
                break;
            }
            --it;
            p[2*i] = (*it);
            left.erase(it); 
        }
        for(int i = 0; i < n; i++) {
            if(p[i] == -1) {
                pos = false;
            }
        }
        if(!pos) {
            cout << -1 << '\n';
            continue;
        }
        for(auto i : p) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}