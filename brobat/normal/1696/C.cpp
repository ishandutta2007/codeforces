#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = 1;
            while(a[i].first % m == 0) {
                a[i].first /= m;
                a[i].second *= m;
            }
        }
        int k;
        cin >> k;
        vector <pair<int, int>> b(k);
        for(int i = 0; i < k; i++) {
            cin >> b[i].first;
            b[i].second = 1;
            while(b[i].first % m == 0) {
                b[i].first /= m;
                b[i].second *= m;
            }
        }
        // for(auto i : a) cout << i.first << " " << i.second << '\n';
        // cout << '\n';
        // for(auto i : b) cout << i.first << " " << i.second << '\n';
        for(int i = n - 1; i >= 1; i--) {
            if(a[i - 1].first == a[i].first) {
                a[i - 1].second += a[i].second;
                a[i] = {0, 0};
            }
        }
        for(int i = k - 1; i >= 1; i--) {
            if(b[i - 1].first == b[i].first) {
                b[i - 1].second += b[i].second;
                b[i] = {0, 0};
            }
        }
        bool pos = true;
        vector <pair<int, int>> c, d;
        for(int i = 0; i < n; i++) {
            if(a[i].first != 0) {
                c.push_back(a[i]);
            } 
        }
        for(int i = 0; i < k; i++) {
            if(b[i].first != 0) {
                d.push_back(b[i]);
            }
        }
        // for(auto i : c) cout << i.first << " " << i.second << '\n';
        // cout << '\n';
        // for(auto i : d) cout << i.first << " " << i.second << '\n';
        if((int)c.size() != (int)d.size()) {
            cout << "No" << '\n';
        } else {
            for(int i = 0; i < (int)c.size(); i++) {
                if(c[i].first == d[i].first && c[i].second == d[i].second) continue;
                pos = false;
            }
            cout << (pos ? "Yes" : "No") << '\n';
        }
    }
    
    return 0;
}