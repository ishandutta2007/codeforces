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
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        set<pair<int, int>> s;
        s.insert({-1, (int)1E18});
        s.insert({n, -(int)1E18});
        for(int i = 0; i < n; i++) {
            auto x = --s.upper_bound({i, v[i]});
            if((*x).second > v[i]) {
                s.insert({i, v[i]});
            }
        }
        // for(auto i : s) cout << i.first + 1 << " " << i.second << '\n';
        for(int i = 0; i < m; i++) {
            int k, d;
            cin >> k >> d;
            --k;
            v[k] -= d;
            pair<int, int> c = {k, v[k]};
            if((*s.lower_bound(c)).first == k) {
                s.erase(s.lower_bound(c));
            }
            // insert new value.
            auto prev = --s.upper_bound(c);
            if((*prev).second > v[k]) {
                // insert.
                s.insert(c);
                while(true) {
                    auto nx = s.upper_bound(c);
                    if((*nx).second >= v[k]) {
                        s.erase(nx);
                    } else {
                        break;
                    }
                }
            }
            cout << (int)s.size() - 2 << " ";
        }
        cout << '\n';
    }
    
    return 0;
}