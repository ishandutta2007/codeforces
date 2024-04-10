#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1E9 + 7;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, p;
        cin >> n >> p;
        vector<int> v(n);
        map<int, bool> present;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            present[v[i]] = true;
        }
        reverse(v.begin(), v.end());
        int mn = INF; // min number not present
        int mx = -INF;
        for(int i = 0; i < min(105, p); i++) {
            if(present.find(i) == present.end()) {
                mn = i;
                break;
            }
        }
        for(int i = p - 1; i >= max(p - 1 - 105, 0); i--) {
            if(present.find(i) == present.end()) {
                mx = i;
                break;
            }
        }
        // First, we definitely gotta go to mx.
        if(mn == INF) {
            // all numbers are present.
            cout << 0 << '\n';
            continue;
        }
        if(mn >= v.front()) {
            // only need to go to mx. 
            cout << mx - v.front() << '\n';
            continue;
        }
        for(int i = v.front(); i <= 505; i++) present[i] = true;
        int ops = p - v.front();
        int init = v.front();
        v.front() = p;
        // Now add 1.
        int carry = 0;
        for(auto &i : v) {
            i += carry;
            if(i >= p) {
                i -= p;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if(carry == 1) v.push_back(1);
        // for(auto i : v) cout << i << ' '; cout << '\n';
        for(auto i : v) present[i] = true;
        // Find new MAX number not present now.
        int new_mn = INF;
        for(int i = init - 1; i >= max(init - 1 - 305, 0); i--) {
            if(present.find(i) == present.end()) {
                new_mn = i;
                break;
            }
        }
        if(new_mn == INF) cout << ops << '\n';
        else cout << ops + new_mn << '\n';
    }
    
    return 0;
}